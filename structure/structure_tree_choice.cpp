#include "structure_tree_choice.hpp"

structure_tree_choice::structure_tree_choice()
{

}

Rules structure_tree_choice::decryptRule(std::string rule)
{

}

L_system structure_tree_choice::binary_tree()
{
    vector<lType> alphabet = {A};
    map<lType,vector<Rules>> rules;
    rules[A] = {Rules(1.0,{oSp,oG,A,oRp,oD,A})};
    return L_system(alphabet,A,rules);
}

L_system structure_tree_choice::fractal_plant()
{
    vector<lType> alphabet = {A,B};
    map<lType,vector<Rules>> rules;
    rules[A] = {Rules(1.0,{B,oG,oSp,oSp,A,oRp,oD,A,oRp,oD,B,oSp,oD,B,A,oRp,oG,A})};
    rules[B] = {Rules(1.0,{B,B})};
    return L_system(alphabet,A,rules);
}
