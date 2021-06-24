#ifndef C_COMMANDS
#define C_COMMANDS 1

#include <bits/stdc++.h>
using namespace std;

class CompMap {
   private:
    map<string, string> _codes;

   public:
    CompMap();
    string getBinaryCode(string m) {
        return _codes[m];
    }
};

class DestMap {
   private:
    map<string, string> _codes;

   public:
    DestMap();
    string getBinaryCode(string m) {
        return _codes[m];
    }
};

class JumpMap {
   private:
    map<string, string> _codes;

   public:
    JumpMap();
    string getBinaryCode(string m) {
        return _codes[m];
    }
};

#endif
