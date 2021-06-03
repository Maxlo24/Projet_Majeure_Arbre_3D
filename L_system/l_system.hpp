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
    vector<lType> axiom;
    map<lType,vector<Rules>> rules;
    vector<lType> Phrase = {};


public:
    /** Constructor */
    L_system();
    L_system(vector<lType>, vector<lType>, map<lType,vector<Rules>>);

    /** Methods */
    int getNumberOfRules();
    vector<Rules> getRulesOfType(lType);
    Rules getOneRuleOfType(lType);
    vector<lType> getAlphabet();
    vector<lType> getAxiom();

    vector<lType> getPhraseN(int n);
};

#endif // L_SYSTEM_H
