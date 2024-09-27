#include "string_util.h"

string repeater(const char c, const unsigned n){
    string str = "";
    for(unsigned i = 0; i < n; i++) str += c;
    return str;
}

string repeater(const string& s, const unsigned n){
    string str = "";
    for(unsigned i = 0; i < n; i++) str += s;
    return str;
}