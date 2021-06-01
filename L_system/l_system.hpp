#ifndef L_SYSTEM_H
#define L_SYSTEM_H

#include "rules.hpp"

#include <iostream>
#include <vector>
#include <map>

using std::vector;
using std::map;


class L_system
{
private:
    vector<lType> alphabet;
    lType axiom;
    map<lType,vector<Rules>> rules;


public:
    /** Constructor */
    L_system();
    L_system(vector<lType>, lType, map<lType,vector<Rules>>);

    /** Methods */
    int getNumberOfRules();
    vector<Rules> getRulesOfType(lType);
    Rules getOneRuleOfType(lType);
    vector<lType> getAlphabet();
    lType getAxiom();
};

#endif // L_SYSTEM_H
