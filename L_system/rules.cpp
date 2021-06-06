#include "rules.hpp"

Rules::Rules()
{
    proba = 1;
}
Rules::Rules(float proba)
    :proba(proba)
{ rule = {};}

Rules::Rules(string rule,float proba)
    :proba(proba),rule(rule)
{}
Rules::Rules(string rule)
    :proba(1),rule(rule)
{}


float Rules::getProba(){return proba;}

string Rules::getRule(){ return rule;}

void Rules::addElement(char E){rule.push_back(E);}

void Rules::operator=(Rules Rule)
{
    proba = Rule.proba;
    rule = Rule.rule;
}
