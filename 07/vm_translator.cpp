#include <bits/stdc++.h>
using namespace std;

namespace translator {
enum VMCommand { C_ARITHMETIC,
                 C_PUSH,
                 C_POP,
                 C_LABEL,
                 C_GOTO,
                 C_IF,
                 C_FUNCTION,
                 C_RETURN,
                 C_CALL };

VMCommand parseCommand(string line) {
    if ((line.substr(0, 3) == "add") || (line.substr(0, 3) == "sub") || (line.substr(0, 3) == "neg") ||
        (line.substr(0, 3) == "and") || (line.substr(0, 3) == "not") || (line.substr(0, 2) == "eq") ||
        (line.substr(0, 2) == "gt") || (line.substr(0, 2) == "lt") || (line.substr(0, 2) == "or"))
        return C_ARITHMETIC;
    else if ((line.substr(0, 4) == "push"))
        return C_PUSH;
    else if ((line.substr(0, 3) == "pop"))
        return C_POP;
    else if ((line.substr(0, 5) == "label"))
        return C_LABEL;
    else if ((line.substr(0, 4) == "goto"))
        return C_GOTO;
    else if ((line.substr(0, 2) == "if"))
        return C_IF;
    else if ((line.substr(0, 8) == "function"))
        return C_FUNCTION;
    else if ((line.substr(0, 6) == "return"))
        return C_RETURN;
    else if ((line.substr(0, 4) == "call"))
        return C_CALL;
    return C_CALL;
}

string arg1(VMCommand vm_command, string line) {
    string s = "";
    if (vm_command != C_RETURN) {
        int first_space = line.find(" ", 0);
        int second_space = line.find(" ", first_space + 1);
        s = line.substr(first_space + 1, second_space - first_space - 1);
    }
    return s;
}

int arg2(VMCommand vm_command, string line) {
    string s = "";
    if (vm_command == C_PUSH || vm_command == C_POP || vm_command == C_FUNCTION || vm_command == C_CALL) {
        int first_space = line.find(" ", 0);
        int second_space = line.find(" ", first_space + 1);
        int third_space = line.find(" ", second_space + 1);
        s = line.substr(second_space + 1, third_space - second_space - 1);
    }
    return stoi(s);
}

void popD(ofstream& fout) {
    fout << "@SP" << endl
         << "AM=M-1" << endl
         << "D=M" << endl;
}

void popGPR(ofstream& fout, int regNum) {
    assert(regNum >= 13 && regNum <= 15);
    fout << "@" << regNum << endl
         << "M=D" << endl;
}

void decSP(ofstream& fout) {
    fout << "@SP" << endl
         << "AM=M-1" << endl;
}

void incSP(ofstream& fout) {
    fout << "@SP" << endl
         << "AM=M+1" << endl;
}

void setReturn(ofstream& fout) {
    fout << "@RETURN"
         << "labelnum_" << endl  // TODO
         << "D=A" << endl
         << "@R15" << endl
         << "M=D" << endl;
}

void getReturn(ofstream& fout) {
    fout << "@R15" << endl
         << "A=M" << endl
         << "0;JMP" << endl;
}

void push(ofstream& fout, string loc, int i) {
    if (loc == "3" || loc == "5") {
        fout << "@" << loc << endl
             << "D=A" << endl
             << "@" << i << endl
             << "A=D+A" << endl
             << "D=M" << endl
             << "@SP" << endl
             << "A=M" << endl
             << "M=D" << endl;
        incSP(fout);
    } else {
        fout << "@" << loc << endl
             << "D=M" << endl
             << "@" << i << endl
             << "A=D+A" << endl
             << "D=M" << endl
             << "@SP" << endl
             << "A=M" << endl
             << "M=D" << endl;
        incSP(fout);
    }
}

void init(ofstream& fout, int& start) {
    fout << "@START" << start << endl
         << "0;JMP" << endl
         << "(MAKETRUE)" << endl;
    decSP(fout);
    fout << "M=-1" << endl;
    incSP(fout);
    getReturn(fout);
    fout << "(START" << start << ")" << endl;
    start++;
}

void writeArithmetic(ofstream& fout, VMCommand vm_command, string line, int& labelnum) {
    string command = arg1(vm_command, line);
    if (command == "add") {
        popD(fout);
        decSP(fout);
        fout << "M=D+M" << endl;
        incSP(fout);
    } else if (command == "sub") {
        popD(fout);
        decSP(fout);
        fout << "M=M-D" << endl;
        incSP(fout);
    } else if (command == "neg") {
        decSP(fout);
        fout << "M=-M" << endl;
        incSP(fout);
    } else if (command == "not") {
        decSP(fout);
        fout << "M=!M" << endl;
        incSP(fout);
    } else if (command == "and") {
        popD(fout);
        decSP(fout);
        fout << "M=D&M" << endl;
        incSP(fout);
    } else if (command == "or") {
        popD(fout);
        decSP(fout);
        fout << "M=D|M" << endl;
        incSP(fout);
    } else if (command == "eq") {
        setReturn(fout);
        popD(fout);
        decSP(fout);
        fout << "D=D-M" << endl
             << "M=0" << endl;
        incSP(fout);
        fout << "@MAKETRUE" << endl
             << "D;JEQ" << endl
             << "(RETURN"
             << labelnum
             << ")" << endl;
        labelnum++;
    } else if (command == "gt") {
        setReturn(fout);
        popD(fout);
        decSP(fout);
        fout << "D=D-M" << endl
             << "M=0" << endl;
        incSP(fout);
        fout << "@MAKETRUE" << endl
             << "D;JLT" << endl
             << "(RETURN"
             << labelnum
             << ")" << endl;
        labelnum++;
    } else if (command == "lt") {
        setReturn(fout);
        popD(fout);
        decSP(fout);
        fout << "D=D-M" << endl
             << "M=0" << endl;
        incSP(fout);
        fout << "@MAKETRUE" << endl
             << "D;JGT" << endl
             << "(RETURN"
             << labelnum
             << ")" << endl;
        labelnum++;
    }
}

void writePushPop(ofstream& fout, VMCommand vm_command, string line, string filename) {
    string a1 = arg1(vm_command, line);
    int a2 = arg2(vm_command, line);
    if (vm_command == C_PUSH) {
        if (a1 == "constant") {
            fout << "@" << a2 << endl
                 << "D=A" << endl
                 << "@SP" << endl
                 << "A=M" << endl
                 << "M=D" << endl;
            incSP(fout);
        } else if (a1 == "local") {
            push(fout, "LCL", a2);
        } else if (a1 == "argument") {
            push(fout, "ARG", a2);
        } else if (a1 == "this") {
            push(fout, "THIS", a2);
        } else if (a1 == "that") {
            push(fout, "THAT", a2);
        } else if (a1 == "pointer") {
            push(fout, "3", a2);
        } else if (a1 == "temp") {
            push(fout, "5", a2);
        } else if (a1 == "static") {
            fout << "@" << filename << "." << a2 << endl
                 << "D=M" << endl
                 << "@SP" << endl
                 << "A=M" << endl
                 << "M=D" << endl
                 << "@SP" << endl
                 << "M=M+1" << endl;
        }
    }
}
}  // namespace translator

int main(int argc, char* argv[]) {
    ifstream fin(argv[argc - 1]);
    string file = argv[argc - 1];
    int dotindex = file.find(".", 0);
    string asmfile = file.substr(0, dotindex) + ".asm";
    ofstream fout(asmfile);
    string line;
    int start = 0, labelnum = 0;
    translator::init(fout, start);
    while (getline(fin, line)) {
        while ((line.substr(0, 2) == "//") || (line.substr(0, 1) == "")) {
            getline(fin, line);
        }
        translator::VMCommand command = translator::parseCommand(line);
        if (command == translator::C_ARITHMETIC)
            translator::writeArithmetic(fout, command, line, labelnum);
        else if (command == translator::C_POP || translator::C_PUSH)
            translator::writePushPop(fout, command, line, asmfile);
    }
}
