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
    string axiom;
    map<char,vector<Rules>> rules;
    vector<char> Phrase = {};


public:
    /** Constructor */
    L_system();
    L_system(vector<char>, string, map<char,vector<Rules>>);

    /** Methods */
    int getNumberOfRules();
    vector<Rules> getRulesOfType(char);
    Rules getOneRuleOfType(char);
    vector<char> getAlphabet();
    string getAxiom();

    string getPhraseN(int n);
    map<char, vector<Rules> > getRules() const;
    void setAxiom(const string &value);
    void setAlphabet(const vector<char> &value);
    void addLetter(char);
    void addRuleOfType(char,string,float p =1.0f);
    void clearRules();
};

#endif // L_SYSTEM_H
