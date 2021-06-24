#include <bits/stdc++.h>

#include "./c_commands.h"
#include "./parser.h"
#include "./symbol_table.h"
using namespace std;

int main(int argc, char** argv) {
    string filename;
    if (argc != 2) {
        cout << "Missing file name." << endl;
        return EXIT_FAILURE;
    } else
        filename = argv[1];
    ifstream in(filename);
    if (!in) {
        cout << "The given file can't be opened." << endl;
        return EXIT_FAILURE;
    }
    if (filename.find(".asm") == string::npos) {
        cout << "The given file is not '.asm' file." << endl;
        return EXIT_FAILURE;
    }

    CompMap comp_map;
    DestMap dest_map;
    JumpMap jump_map;

    Parser parser(in, comp_map, dest_map, jump_map);
    SymbolTable symbol_table;
    int inst_count = 0;

    while (parser.hasMoreCommands()) {
        parser.advance();
        switch (parser.commandType()) {
            case L_COMMAND:
                symbol_table.add(parser.symbol(), inst_count);
                break;
            default:
                inst_count++;
        }
    }

    in.close();
    in.open(filename);
    Parser parser2(in, comp_map, dest_map, jump_map);
    filename = filename.substr(0, filename.find(".asm"));
    ofstream out(filename + ".hack");
    string symbol;
    int reg;
    int RAM_addr = 16;

    symbol_table.add("SP", 0);
    symbol_table.add("LCL", 1);
    symbol_table.add("ARG", 2);
    symbol_table.add("THIS", 3);
    symbol_table.add("THIS", 4);
    symbol_table.add("R0", 0);
    symbol_table.add("R1", 1);
    symbol_table.add("R2", 2);
    symbol_table.add("R3", 3);
    symbol_table.add("R4", 4);
    symbol_table.add("R5", 5);
    symbol_table.add("R6", 6);
    symbol_table.add("R7", 7);
    symbol_table.add("R8", 8);
    symbol_table.add("R9", 9);
    symbol_table.add("R10", 10);
    symbol_table.add("R11", 11);
    symbol_table.add("R12", 12);
    symbol_table.add("R13", 13);
    symbol_table.add("R14", 14);
    symbol_table.add("R15", 15);
    symbol_table.add("SCREEN", 16384);
    symbol_table.add("KBD", 24576);

    while (parser2.hasMoreCommands()) {
        parser2.advance();
        switch (parser2.commandType()) {
            case A_COMMAND:
                symbol = parser2.symbol();
                if (!isdigit(symbol[0]))
                    if (symbol_table.contains(symbol))
                        out << "0" << symbol_table.getAddress(symbol) << "\n";
                    else {
                        symbol_table.add(symbol, RAM_addr);
                        out << "0" << symbol_table.formatAsBin(RAM_addr++) << "\n";
                    }
                else {
                    int constant = 0;
                    for (int i = 0; i < symbol.size(); i++) {
                        constant *= 10;
                        constant += symbol[i] - '0';
                        out << "0" << symbol_table.formatAsBin(constant) << "\n";
                    }
                }
                break;
            case C_COMMAND:
                reg = parser2.comp().find("M") != string::npos ? 1 : 0;
                out << "111" << reg
                    << comp_map.getBinaryCode(parser2.comp()) << dest_map.getBinaryCode(parser2.dest())
                    << jump_map.getBinaryCode(parser2.jump()) << "\n";
                break;
            case L_COMMAND:
                break;
        }
    }

    in.close();
    out.close();
    cout << "Done" << endl;
}
