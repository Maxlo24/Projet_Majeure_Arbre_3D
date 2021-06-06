#ifndef L_SYSTEM_H
#define L_SYSTEM_H

#include "rules.hpp"

#include <iostream>
#include <vector>
#include <map>
#include <string>

using std::vector;
using std::map;
using std::string;


class L_system
{
private:
    vector<char> alphabet;
    vector<char> axiom;
    map<char,vector<Rules>> rules;
    vector<char> Phrase = {};


public:
    /** Constructor */
    L_system();
    L_system(vector<char>, vector<char>, map<char,vector<Rules>>);

    /** Methods */
    int getNumberOfRules();
    vector<Rules> getRulesOfType(char);
    Rules getOneRuleOfType(char);
    vector<char> getAlphabet();
    vector<char> getAxiom();

    string getPhraseN(int n);
};

#endif // L_SYSTEM_H
