#include "l_system.hpp"

#include <QRandomGenerator>

L_system::L_system()
{
}

L_system::L_system(vector<char> alphabet, vector<char> axiom, map<char,vector<Rules>> rules)
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

vector<char> L_system::getAxiom(){ return axiom;}

string L_system::getPhraseN(int n)
{
    string pseudoPhrases = "";
    pseudoPhrases.insert(pseudoPhrases.end(),axiom.begin(),axiom.end());
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
