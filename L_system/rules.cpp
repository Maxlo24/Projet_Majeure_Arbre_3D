#include "rules.hpp"

Rules::Rules()
{}
Rules::Rules(float proba)
    :proba(proba)
{ rule = {};}

Rules::Rules(float proba, vector<lType> rule)
    :proba(proba),rule(rule)
{}

float Rules::getProba(){return proba;}

vector<lType> Rules::getRule(){ return rule;}

void Rules::addElement(lType E){rule.push_back(E);}
