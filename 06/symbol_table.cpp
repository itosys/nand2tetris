#include "./symbol_table.h"

#include <bits/stdc++.h>
using namespace std;

void SymbolTable::add(string s, int addr) {
    _table[s] = addr;
}

bool SymbolTable::contains(string s) {
    return _table.find(s) != _table.end();
}

string SymbolTable::formatAsBin(int addr) {
    string bin(15, '0');
    int n = 14;
    while (addr) {
        bin[n--] = addr & 1 ? '1' : '0';
        addr >>= 1;
    }
    return bin;
}

string SymbolTable::getAddress(string s) {
    return formatAsBin(_table[s]);
}
