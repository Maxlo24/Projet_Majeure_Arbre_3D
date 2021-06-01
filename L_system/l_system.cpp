#include "l_system.hpp"

#include <QRandomGenerator>

L_system::L_system()
{
}

L_system::L_system(vector<lType> alphabet, lType axiom, map<lType,vector<Rules>> rules)
    :alphabet(alphabet),axiom(axiom),rules(rules)
{}

int L_system::getNumberOfRules(){
    int number = 0;
    for(map<lType,vector<Rules>>::iterator it=rules.begin() ; it!=rules.end() ; ++it)
    {
        number += it->second.size();
    }
    return number;
}

vector<Rules> L_system::getRulesOfType(lType type){return rules[type];}


Rules L_system::getOneRuleOfType(lType type){
    QRandomGenerator generator(1);
    int random = generator.bounded(100);
    float proba = 0;
    vector<Rules >t_rule = rules[type];
    for (Rules r:t_rule){
        proba += r.getProba();
        if (proba*100 > random)
            return r;
    }
    return t_rule.back();
}

vector<lType> L_system::getAlphabet(){ return alphabet;}

lType L_system::getAxiom(){ return axiom;}
