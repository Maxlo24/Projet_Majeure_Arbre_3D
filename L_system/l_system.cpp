#include "l_system.hpp"

#include <QRandomGenerator>



map<char, vector<Rules> > L_system::getRules() const
{
    return rules;
}

void L_system::setAxiom(const string &value)
{
    axiom = value;
}

void L_system::setAlphabet(const vector<char> &value)
{
    alphabet = value;
}

void L_system::addLetter(char l)
{
    if ( std::find(alphabet.begin(), alphabet.end(), l) == alphabet.end()) alphabet.push_back(l);

}

void L_system::addRuleOfType(char l, std::string rule, float p)
{
    (rules[l]).push_back(Rules(rule,p));
}

void L_system::clearRules()
{
    rules.clear();
}

L_system::L_system()
{
}

L_system::L_system(vector<char> alphabet, string axiom, map<char,vector<Rules>> rules)
    :alphabet(alphabet),axiom(axiom),rules(rules)
{}

int L_system::getNumberOfRules(){
    int number = 0;
    for(map<char,vector<Rules>>::iterator it=rules.begin() ; it!=rules.end() ; ++it)
    {
        number += it->second.size();
    }
    return number;
}

vector<Rules> L_system::getRulesOfType(char type){return rules[type];}


Rules L_system::getOneRuleOfType(char type){
    int random = rand()%100;
    float proba = 0;
    vector<Rules >t_rule = rules[type];
    for (Rules r:t_rule){
        proba += r.getProba();
        if (proba*100 > random)
            return r;
    }
    return t_rule.back();
}

vector<char> L_system::getAlphabet(){ return alphabet;}

string L_system::getAxiom(){ return axiom;}

string L_system::getPhraseN(int n)
{
    string pseudoPhrases = "";
    pseudoPhrases.append(axiom);
    string pseudoPhrases1 = "";
    for (int i = 0; i < n+1; i++){
        pseudoPhrases1 = pseudoPhrases;
        pseudoPhrases = {};
        for (string::iterator it = pseudoPhrases1.begin() ; it != pseudoPhrases1.end(); ++it){
            if (std::find(alphabet.begin(), alphabet.end(),*it)!=alphabet.end()){
                string paragraph = getOneRuleOfType(*it).getRule();
                pseudoPhrases.insert(pseudoPhrases.end(),paragraph.begin(),paragraph.end());
            } else{
                pseudoPhrases.push_back(*it);
            }
        }
    }
    return pseudoPhrases;

}
