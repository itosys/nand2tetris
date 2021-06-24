#include "./parser.h"

#include <bits/stdc++.h>

#include "./c_commands.h"
using namespace std;

Parser::~Parser() {
    _in.close();
}

void Parser::advance() {
    if (!hasMoreCommands()) return;

    switch (_current_line[_pos]) {
        case '(':
            handleLCommand();
            break;
        case '@':
            handleACommand();
            break;
        default:
            handleCCommand();
            break;
    }
    _line_num++;
}

bool Parser::hasMoreCommands() {
    if (!_in) return false;

    skipWhitespace();
    if (_pos == _current_line.size())
        getline(_in, _current_line);
    else
        return true;

    _pos = 0;
    skipWhitespace();
    if (_pos == _current_line.size()) return hasMoreCommands();
    if (_current_line[_pos] == '/') {
        handleComment();
        return hasMoreCommands();
    }
    return true;
}

void Parser::skipWhitespace() {
    while (isspace(_current_line[_pos])) _pos++;
}

void Parser::handleComment() {
    _pos++;
    if (_current_line[_pos] == '/') _pos = _current_line.size();
    return;
}

string Parser::extractSymbol() {
    string s;
    char c;
    while (_pos < _current_line.size()) {
        c = _current_line[_pos];
        if (!isalnum(c) && c != '_' && c != '.' && c != '$' && c != ':') break;
        s += c;
        _pos++;
    }
    return s;
}

void Parser::handleLCommand() {
    _pos++;
    skipWhitespace();
    string label = extractSymbol();
    skipWhitespace();
    _symbol = label;
    _cmd_type = L_COMMAND;
    _pos = _current_line.size();
}

void Parser::handleACommand() {
    _pos++;
    skipWhitespace();
    string s;
    if (!isdigit(_current_line[_pos]))
        s = extractSymbol();
    else
        while (isdigit(_current_line[_pos])) s += _current_line[_pos];

    skipWhitespace();
    _pos = _current_line.size();
    _symbol = s;
    _cmd_type = A_COMMAND;
}

void Parser::handleCCommand() {
    /*
        states:
            0: no clue
            1: found dest, looking for comp
            2: found dest and comp, looking for jump
    */
    skipWhitespace();
    int state = 0;
    string s;
    char c;
    int comp_pos = _pos, dest_pos = _pos, jump_pos = _pos;

    while (state < 3) {
        if (_pos >= _current_line.size())
            c = 0;
        else
            c = _current_line[_pos];

        if (isspace(c)) {
            _pos++;
            continue;
        }

        if (state == 0) {
            switch (c) {
                case '=':
                    _dest = s;
                    s = "";
                    comp_pos = jump_pos = _pos;
                    state = 1;
                    _pos++;
                    continue;
                case ';':
                case '/':
                case 0:
                    _dest = "null";
                    _comp = s;
                    s = "";
                    jump_pos = _pos;
                    state = 2;
                    _pos++;
                    continue;
            }
        } else if (state == 1) {
            switch (c) {
                case ';':
                case '/':
                case 0:
                    _comp = s;
                    s = "";
                    jump_pos = _pos;
                    state = 2;
                    _pos++;
                    continue;
            }
        } else if (state == 2) {
            switch (c) {
                case '/':
                case 0:
                    if (s == "")
                        _jump = "null";
                    else
                        _jump = s;
                    state = 3;
            }
        }
        s += c;
        _pos++;
    }
    _cmd_type = C_COMMAND;
    _pos = _current_line.size();
}
