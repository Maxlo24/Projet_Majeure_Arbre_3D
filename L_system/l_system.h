#ifndef L_SYSTEM_H
#define L_SYSTEM_H

#include "rules.h"

#include <iostream>
#include <vector>
#include <map>

using std::vector;
using std::map;

enum lType {A,B,F};

class L_system
{
private:
    vector<char> alphabet;
    char axiom;
    map<char,vector<Rules>> rules;


public:
    L_system();
};

#endif // L_SYSTEM_H
