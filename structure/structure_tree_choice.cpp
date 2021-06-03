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
        else if (c=='Y')  translateRule.addElement(Y);
        else if (c=='Z')  translateRule.addElement(Z);
        else if (c=='W')  translateRule.addElement(W);
        else if (c=='V')  translateRule.addElement(V);
        else if (c=='F')  translateRule.addElement(F);
        else if (c=='-')  translateRule.addElement(oG);
        else if (c=='+')  translateRule.addElement(oD);
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
    vector<lType> alphabet = {X,F};
    map<lType,vector<Rules>> rules;
    rules[X] = {decryptRule("[-FX]+FX")};
    rules[F] = {decryptRule("F")};
    return L_system(alphabet,{F,X},rules);
}

L_system structure_tree_choice::fractal_plant()
{
    vector<lType> alphabet = {X,F};
    map<lType,vector<Rules>> rules;
    rules[X] = {decryptRule("F+[[X]-X]-F[-FX]+X")};
    rules[F] = {decryptRule("FF")};
    return L_system(alphabet,{X},rules);
}

L_system structure_tree_choice::fractal_stick()
{
    vector<lType> alphabet = {X,F};
    map<lType,vector<Rules>> rules;
    rules[X] = {decryptRule("F[+X]F[-X]+X")};
    rules[F] = {decryptRule("FF")};
    return L_system(alphabet,{X},rules);
}

L_system structure_tree_choice::fractal_sym()
{
    vector<lType> alphabet = {Y,X,F};
    map<lType,vector<Rules>> rules;
    rules[Y] = {decryptRule("X[-FFF][+FFF]FX")};
    rules[X] = {decryptRule("YFX[+Y][-Y]")};
    rules[F] = {decryptRule("F")};
    return L_system(alphabet,{Y},rules);
}

L_system structure_tree_choice::fractal_bush()
{
    vector<lType> alphabet = {F};
    map<lType,vector<Rules>> rules;
    rules[F] = {decryptRule("FF+[+F-F-F][-F+F+F]")};
    return L_system(alphabet,{F},rules);
}

L_system structure_tree_choice::fractal_leaf()
{
    vector<lType> alphabet = {F,X,Y,Z,W};
    map<lType,vector<Rules>> rules;
    rules[F] = {decryptRule("F")};
    rules[X] = {decryptRule("Z")};
    rules[Y] = {decryptRule("W")};
    rules[Z] = {decryptRule("F[+X]FW")};
    rules[W] = {decryptRule("F[-Y]FZ")};
    return L_system(alphabet,{Z},rules);
}

L_system structure_tree_choice::fractal_fir()
{
    vector<lType> alphabet = {X,Y,Z,V,W,F};
    map<lType,vector<Rules>> rules;
    rules[V] = {decryptRule("[+++W][---W]YV")};
    rules[W] = {decryptRule("+X[-W]Z")};
    rules[X] = {decryptRule("-W[+X]Z")};
    rules[Y] = {decryptRule("YZ")};
    rules[Z] = {decryptRule("[-FFF][+FFF]F")};
    rules[F] = {decryptRule("F")};
    return L_system(alphabet,{V,Z,F,F,F},rules);
}

L_system structure_tree_choice::fractal_dragon()
{
    vector<lType> alphabet = {X,Y,F};
    map<lType,vector<Rules>> rules;
    rules[X] = {decryptRule("X+YF+")};
    rules[Y] = {decryptRule("-FX-Y")};
    rules[F] = {decryptRule("F")};
    return L_system(alphabet,{F,X},rules);
}

L_system structure_tree_choice::fractal_complex1()
{
    vector<lType> alphabet = {X,F};
    map<lType,vector<Rules>> rules;
    rules[X] = {decryptRule("F+[[X]-X]-F[-FX]+X")};
    rules[F] = {decryptRule("FF+[+F-F-F][-F+F+F]",0.2),decryptRule("FF",0.8)};
    return L_system(alphabet,{X},rules);
}
L_system structure_tree_choice::fractal_persil()
{
    vector<lType> alphabet = {X,Y,Z,V,W,F};
    map<lType,vector<Rules>> rules;
    rules[V] = {decryptRule("[+++W][---W]YV")};
    rules[W] = {decryptRule("+X[-W]Z")};
    rules[X] = {decryptRule("-W[+X]Z",0.3),decryptRule("F[+X]F[-X]+X",0.6),decryptRule("[-FX]+FX",0.1)};
    rules[Y] = {decryptRule("YZ")};
    rules[Z] = {decryptRule("[-FFF][+FFF]F")};
    rules[F] = {decryptRule("F",0.5),decryptRule("FF",0.5)};

    return L_system(alphabet,{F,X},rules);
}

