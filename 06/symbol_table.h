#ifndef SYMBOL_TABLE
#define SYMBOL_TABLE 1

#include <bits/stdc++.h>
using namespace std;

class SymbolTable {
   private:
    map<string, int> _table;

   public:
    SymbolTable() {}
    void add(string s, int addr);
    bool contains(string s);
    string getAddress(string s);
    string formatAsBin(int addr);
};

#endif
