#include "./c_commands.h"

#include <bits/stdc++.h>
using namespace std;

CompMap::CompMap() {
    _codes["0"] = "101010";
    _codes["1"] = "111111";
    _codes["-1"] = "111010";
    _codes["D"] = "001100";
    _codes["A"] = "110000";
    _codes["M"] = "110000";
    _codes["!D"] = "001101";
    _codes["!A"] = "110001";
    _codes["!M"] = "110001";
    _codes["-D"] = "001111";
    _codes["-A"] = "110011";
    _codes["-M"] = "110011";
    _codes["D+1"] = "011111";
    _codes["A+1"] = "110111";
    _codes["M+1"] = "110111";
    _codes["D-1"] = "001110";
    _codes["A-1"] = "110010";
    _codes["M-1"] = "110010";
    _codes["D+A"] = "000010";
    _codes["D+M"] = "000010";
    _codes["D-A"] = "010011";
    _codes["D-M"] = "010011";
    _codes["A-D"] = "000111";
    _codes["M-D"] = "000111";
    _codes["D&A"] = "000000";
    _codes["D&M"] = "000000";
    _codes["D|A"] = "010101";
    _codes["D|M"] = "010101";
}

DestMap::DestMap() {
    _codes["null"] = "000";
    _codes["M"] = "001";
    _codes["D"] = "010";
    _codes["MD"] = "011";
    _codes["A"] = "100";
    _codes["AM"] = "101";
    _codes["AD"] = "110";
    _codes["AMD"] = "111";
}

JumpMap::JumpMap() {
    _codes["null"] = "000";
    _codes["JGT"] = "001";
    _codes["JEQ"] = "010";
    _codes["JGE"] = "011";
    _codes["JLT"] = "100";
    _codes["JNE"] = "101";
    _codes["JLE"] = "110";
    _codes["JMP"] = "111";
}
