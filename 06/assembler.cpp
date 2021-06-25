#include <bits/stdc++.h>
using namespace std;

namespace assembler {

// A command to binary
string a2bin(string a_com) {
    int val = stoi(a_com);
    string out = "0";
    if ((val - 16384) >= 0) {
        val -= 16384;
        out += "1";
    } else
        out += "0";
    if ((val - 8192) >= 0) {
        val -= 8192;
        out += "1";
    } else
        out += "0";
    if ((val - 4096) >= 0) {
        val -= 4096;
        out += "1";
    } else
        out += "0";
    if ((val - 2048) >= 0) {
        val -= 2048;
        out += "1";
    } else
        out += "0";
    if ((val - 1024) >= 0) {
        val -= 1024;
        out += "1";
    } else
        out += "0";
    if ((val - 512) >= 0) {
        val -= 512;
        out += "1";
    } else
        out += "0";
    if ((val - 256) >= 0) {
        val -= 256;
        out += "1";
    } else
        out += "0";
    if ((val - 128) >= 0) {
        val -= 128;
        out += "1";
    } else
        out += "0";
    if ((val - 64) >= 0) {
        val -= 64;
        out += "1";
    } else
        out += "0";
    if ((val - 32) >= 0) {
        val -= 32;
        out += "1";
    } else
        out += "0";
    if ((val - 16) >= 0) {
        val -= 16;
        out += "1";
    } else
        out += "0";
    if ((val - 8) >= 0) {
        val -= 8;
        out += "1";
    } else
        out += "0";
    if ((val - 4) >= 0) {
        val -= 4;
        out += "1";
    } else
        out += "0";
    if ((val - 2) >= 0) {
        val -= 2;
        out += "1";
    } else
        out += "0";
    if ((val - 1) >= 0) {
        val -= 1;
        out += "1";
    } else
        out += "0";
    return out;
}

// C command to binary
string c2bin(string c_com) {
    c_com = c_com.substr(0, c_com.find(" ", 0));
    string out = "111", comp, dest, jump;

    // comp
    int equalSign = c_com.find("=", 0);
    if (equalSign > -1 && equalSign < c_com.length()) {
        if (c_com.substr(equalSign + 1, 3) == "D|M")
            comp = "1010101";
        else if (c_com.substr(equalSign + 1, 3) == "D|A")
            comp = "0010101";
        else if (c_com.substr(equalSign + 1, 3) == "D&A")
            comp = "0000000";
        else if (c_com.substr(equalSign + 1, 3) == "D&M")
            comp = "1000000";
        else if (c_com.substr(equalSign + 1, 3) == "A-D")
            comp = "0000111";
        else if (c_com.substr(equalSign + 1, 3) == "M-D")
            comp = "1000111";
        else if (c_com.substr(equalSign + 1, 3) == "D+1")
            comp = "0011111";
        else if (c_com.substr(equalSign + 1, 3) == "A+1")
            comp = "0110111";
        else if (c_com.substr(equalSign + 1, 3) == "M+1")
            comp = "1110111";
        else if (c_com.substr(equalSign + 1, 3) == "D-1")
            comp = "0001110";
        else if (c_com.substr(equalSign + 1, 3) == "A-1")
            comp = "0110010";
        else if (c_com.substr(equalSign + 1, 3) == "M-1")
            comp = "1110010";
        else if (c_com.substr(equalSign + 1, 3) == "D+A")
            comp = "0000010";
        else if (c_com.substr(equalSign + 1, 3) == "D+M")
            comp = "1000010";
        else if (c_com.substr(equalSign + 1, 3) == "D-A")
            comp = "0010011";
        else if (c_com.substr(equalSign + 1, 3) == "D-M")
            comp = "1010011";
        else if (c_com.substr(equalSign + 1, 2) == "-1")
            comp = "0111010";
        else if (c_com.substr(equalSign + 1, 2) == "!D")
            comp = "0001101";
        else if (c_com.substr(equalSign + 1, 2) == "!A")
            comp = "0110001";
        else if (c_com.substr(equalSign + 1, 2) == "!M")
            comp = "1110001";
        else if (c_com.substr(equalSign + 1, 2) == "-D")
            comp = "0001111";
        else if (c_com.substr(equalSign + 1, 2) == "-A")
            comp = "0110011";
        else if (c_com.substr(equalSign + 1, 2) == "-M")
            comp = "1110011";
        else if (c_com.substr(equalSign + 1, 1) == "0")
            comp = "0101010";
        else if (c_com.substr(equalSign + 1, 1) == "1")
            comp = "0111111";
        else if (c_com.substr(equalSign + 1, 1) == "D")
            comp = "0001100";
        else if (c_com.substr(equalSign + 1, 1) == "A")
            comp = "0110000";
        else if (c_com.substr(equalSign + 1, 1) == "M")
            comp = "1110000";
    } else {
        if (c_com.find("D|M", 0) >= 0 && c_com.find("D|M", 0) < c_com.length())
            comp = "1010101";
        else if (c_com.find("D|A", 0) >= 0 && c_com.find("D|A", 0) < c_com.length())
            comp = "0010101";
        else if (c_com.find("D&A", 0) >= 0 && c_com.find("D&A", 0) < c_com.length())
            comp = "0000000";
        else if (c_com.find("D&M", 0) >= 0 && c_com.find("D&M", 0) < c_com.length())
            comp = "1000000";
        else if (c_com.find("A-D", 0) >= 0 && c_com.find("A-D", 0) < c_com.length())
            comp = "0000111";
        else if (c_com.find("M-D", 0) >= 0 && c_com.find("M-D", 0) < c_com.length())
            comp = "1000111";
        else if (c_com.find("D+1", 0) >= 0 && c_com.find("D+1", 0) < c_com.length())
            comp = "0011111";
        else if (c_com.find("A+1", 0) >= 0 && c_com.find("A+1", 0) < c_com.length())
            comp = "0110111";
        else if (c_com.find("M+1", 0) >= 0 && c_com.find("M+1", 0) < c_com.length())
            comp = "1110111";
        else if (c_com.find("D-1", 0) >= 0 && c_com.find("D-1", 0) < c_com.length())
            comp = "0001110";
        else if (c_com.find("A-1", 0) >= 0 && c_com.find("A-1", 0) < c_com.length())
            comp = "0110010";
        else if (c_com.find("M-1", 0) >= 0 && c_com.find("M-1", 0) < c_com.length())
            comp = "1110010";
        else if (c_com.find("D+A", 0) >= 0 && c_com.find("D+A", 0) < c_com.length())
            comp = "0000010";
        else if (c_com.find("D+M", 0) >= 0 && c_com.find("D+M", 0) < c_com.length())
            comp = "1000010";
        else if (c_com.find("D-A", 0) >= 0 && c_com.find("D-A", 0) < c_com.length())
            comp = "0010011";
        else if (c_com.find("D-M", 0) >= 0 && c_com.find("D-M", 0) < c_com.length())
            comp = "1010011";
        else if (c_com.find("-1", 0) >= 0 && c_com.find("-1", 0) < c_com.length())
            comp = "0111010";
        else if (c_com.find("!D", 0) >= 0 && c_com.find("!D", 0) < c_com.length())
            comp = "0001101";
        else if (c_com.find("!A", 0) >= 0 && c_com.find("!A", 0) < c_com.length())
            comp = "0110001";
        else if (c_com.find("!M", 0) >= 0 && c_com.find("!M", 0) < c_com.length())
            comp = "1110001";
        else if (c_com.find("-D", 0) >= 0 && c_com.find("-D", 0) < c_com.length())
            comp = "0001111";
        else if (c_com.find("-A", 0) >= 0 && c_com.find("-A", 0) < c_com.length())
            comp = "0110011";
        else if (c_com.find("-M", 0) >= 0 && c_com.find("-M", 0) < c_com.length())
            comp = "1110011";
        else if (c_com.find("0", 0) >= 0 && c_com.find("0", 0) < c_com.length())
            comp = "0101010";
        else if (c_com.find("1", 0) >= 0 && c_com.find("1", 0) < c_com.length())
            comp = "0111111";
        else if (c_com.find("D", 0) >= 0 && c_com.find("D", 0) < c_com.length())
            comp = "0001100";
        else if (c_com.find("A", 0) >= 0 && c_com.find("A", 0) < c_com.length())
            comp = "0110000";
        else if (c_com.find("M", 0) >= 0 && c_com.find("M", 0) < c_com.length())
            comp = "1110000";
    }

    // jump
    int semi = c_com.find(";", 0);
    if (c_com.substr(semi + 1, 3) == "JGT")
        jump = "001";
    else if (c_com.substr(semi + 1, 3) == "JEQ")
        jump = "010";
    else if (c_com.substr(semi + 1, 3) == "JGE")
        jump = "011";
    else if (c_com.substr(semi + 1, 3) == "JLT")
        jump = "100";
    else if (c_com.substr(semi + 1, 3) == "JNE")
        jump = "101";
    else if (c_com.substr(semi + 1, 3) == "JLE")
        jump = "110";
    else if (c_com.substr(semi + 1, 3) == "JMP")
        jump = "111";
    else
        jump = "000";

    // dest
    if (equalSign > -1 && equalSign < c_com.length()) {
        string d3, d2, d1;
        int findM = c_com.find("M", 0);
        if (findM > -1 && findM < equalSign) {
            d3 = "1";
        } else {
            d3 = "0";
        }
        int findD = c_com.find("D", 0);
        if (findD > -1 && findD < equalSign) {
            d2 = "1";
        } else {
            d2 = "0";
        }
        int findA = c_com.find("A", 0);
        if (findA > -1 && findA < equalSign) {
            d1 = "1";
        } else {
            d1 = "0";
        }
        dest = d1 + d2 + d3;
    } else
        dest = "000";
    return out + comp + dest + jump;
}

int isNum(string num) {
    if (num == "0" || num == "1" || num == "2" || num == "3" || num == "4" || num == "5" || num == "6" || num == "7" || num == "8" || num == "9")
        return 1;
    else
        return 0;
}

string itos(int i) {
    ostringstream s;
    s << i;
    return s.str();
}

int isSymbol(vector<string> &symbols, string s) {
    for (int i = 0; i < symbols.size(); i++)
        if (symbols[i] == s) return 1;

    return 0;
}

}  // namespace assembler

int main(int argc, char *argv[]) {
    ifstream fin(argv[argc - 1]);
    string file = argv[argc - 1];
    int dotindex = file.find(".", 0);
    string hackfile = file.substr(0, dotindex) + ".hack";
    ofstream fout(hackfile.c_str());

    map<string, int> symbol_table;
    symbol_table["R0"] = 0;
    symbol_table["R1"] = 1;
    symbol_table["R2"] = 2;
    symbol_table["R3"] = 3;
    symbol_table["R4"] = 4;
    symbol_table["R5"] = 5;
    symbol_table["R6"] = 6;
    symbol_table["R7"] = 7;
    symbol_table["R8"] = 8;
    symbol_table["R9"] = 9;
    symbol_table["R10"] = 10;
    symbol_table["R11"] = 11;
    symbol_table["R12"] = 12;
    symbol_table["R13"] = 13;
    symbol_table["R14"] = 14;
    symbol_table["R15"] = 15;
    symbol_table["SCREEN"] = 16384;
    symbol_table["KBD"] = 24576;
    symbol_table["SP"] = 0;
    symbol_table["LCL"] = 1;
    symbol_table["ARG"] = 2;
    symbol_table["THIS"] = 3;
    symbol_table["THAT"] = 4;

    vector<string> symbols;
    symbols.push_back("R0");
    symbols.push_back("R1");
    symbols.push_back("R2");
    symbols.push_back("R3");
    symbols.push_back("R4");
    symbols.push_back("R5");
    symbols.push_back("R6");
    symbols.push_back("R7");
    symbols.push_back("R8");
    symbols.push_back("R9");
    symbols.push_back("R10");
    symbols.push_back("R11");
    symbols.push_back("R12");
    symbols.push_back("R13");
    symbols.push_back("R14");
    symbols.push_back("R15");
    symbols.push_back("SCREEN");
    symbols.push_back("KBD");
    symbols.push_back("SP");
    symbols.push_back("LCL");
    symbols.push_back("ARG");
    symbols.push_back("THIS");
    symbols.push_back("THAT");
    int symSize = 22;

    // define jump symbols
    int pc = 0, ram_location = 16;
    string sym;
    while (getline(fin, sym)) {
        if ((sym.substr(0, 1) == "(") && !(assembler::isSymbol(symbols, sym.substr(1, sym.find(")", 0) - 1)))) {
            symbol_table[sym.substr(1, sym.find(")", 0) - 1)] = pc;
            symbols.push_back(sym.substr(1, sym.find(")", 0) - 1));
            symSize++;
        }
        if (sym.substr(0, 1) != "/" && sym.substr(0, 1) != "(" && sym.substr(0, 1) != "")
            pc++;
    }
    fin.close();

    // user defined variable symbols
    fin.open(argv[argc - 1]);
    while (getline(fin, sym)) {
        if (sym.substr(0, 1) == "@") {
            if (!(assembler::isNum(sym.substr(1, 1))) && !(assembler::isSymbol(symbols, sym.substr(1, sym.find(" ", 0) - 1)))) {
                symbol_table[sym.substr(1, sym.length() - 1)] = ram_location;
                ram_location++;
                symbols.push_back(sym.substr(1, sym.length() - 1));
                symSize++;
            }
        }
    }
    fin.close();

    // command parse
    string command, hack_command;
    fin.open(argv[argc - 1]);
    while (getline(fin, command)) {
        if (command.substr(0, 1) == "/" || command.substr(0, 1) == "" || command.substr(0, 1) == "(")  // skip
        {
            ;
        } else if (command.substr(0, 1) == "@")  // A command
        {
            if (assembler::isNum(command.substr(1, 1))) {
                hack_command = assembler::a2bin(command.substr(1, command.length() - 1));
                fout << hack_command << endl;
            } else  // user defined symbol
            {
                hack_command = assembler::a2bin(assembler::itos(symbol_table[command.substr(1, command.length() - 1)]));
                fout << hack_command << endl;
            }
        } else  // C command
        {
            hack_command = assembler::c2bin(command);
            fout << hack_command << endl;
        }
    }
}
