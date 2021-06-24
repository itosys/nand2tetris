#ifndef PARSER
#define PARSER 1

#include <bits/stdc++.h>

#include "./c_commands.h"
using namespace std;

enum CommandType {
    A_COMMAND,
    C_COMMAND,
    L_COMMAND
};

class Parser {
   private:
    string _current_line;
    ifstream& _in;
    CommandType _cmd_type;
    string _symbol;
    string _comp;
    string _dest;
    string _jump;
    int _pos;
    int _line_num;
    CompMap& comp_map;
    DestMap& dest_map;
    JumpMap& jump_map;

    void handleACommand();
    void handleCCommand();
    void handleLCommand();
    void handleComment();
    void skipWhitespace();
    string extractSymbol();

   public:
    Parser(ifstream& f, CompMap& cm, DestMap& dm, JumpMap& jm)
        : _in(f), dest_map(dm), comp_map(cm), jump_map(jm), _pos(0), _line_num(0) {}
    ~Parser();
    void advance();
    bool hasMoreCommands();
    CommandType commandType() { return _cmd_type; }
    string symbol() { return _symbol; }
    string comp() { return _comp; }
    string dest() { return _dest; }
    string jump() { return _jump; }
    string getCurrentLine() { return _current_line; }
};

#endif
