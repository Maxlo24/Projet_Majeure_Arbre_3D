#include "structure_tree_choice.hpp"

structure_tree_choice::structure_tree_choice()
{

}

Rules structure_tree_choice::decryptRule(std::string rule,float proba){
    Rules translateRule(proba);
    for (char c:rule){
        if (c=='A')  translateRule.addElement(A);
        else if (c=='B')  translateRule.addElement(B);
        else if (c=='X')  translateRule.addElement(X);
        else if (c=='F')  translateRule.addElement(F);
        else if (c=='-')  translateRule.addElement(oD);
        else if (c=='+')  translateRule.addElement(oG);
        else if (c=='&')  translateRule.addElement(oPb);
        else if (c=='^')  translateRule.addElement(oPh);
        else if (c=='<')  translateRule.addElement(oRG);
        else if (c=='>')  translateRule.addElement(oRD);
        else if (c=='|')  translateRule.addElement(oT);
        else if (c=='[')  translateRule.addElement(oSp);
        else if (c==']')  translateRule.addElement(oRp);
    }
    return translateRule;
}

L_system structure_tree_choice::binary_tree()
{
    vector<lType> alphabet = {X};
    map<lType,vector<Rules>> rules;
    rules[X] = {Rules(1.0,{oSp,oG,X,oRp,oD,X})};
    return L_system(alphabet,X,rules);
}

L_system structure_tree_choice::fractal_plant()
{
    vector<lType> alphabet = {X,F};
    map<lType,vector<Rules>> rules;
    rules[X] = {decryptRule("F+[[X]-X]-F[-FX]+X")};
    rules[F] = {decryptRule("FF")};
    return L_system(alphabet,X,rules);
}

L_system structure_tree_choice::fractal_stick()
{
    vector<lType> alphabet = {X,F};
    map<lType,vector<Rules>> rules;
    rules[X] = {decryptRule("F[+X]F[-X]+X")};
    rules[F] = {decryptRule("")};
    return L_system(alphabet,X,rules);
}

L_system structure_tree_choice::fractal_sym()
{
    vector<lType> alphabet = {X,F};
    map<lType,vector<Rules>> rules;
    rules[X] = {decryptRule("[-FX]+FX")};
    rules[F] = {decryptRule("")};
    return L_system(alphabet,X,rules);
}
