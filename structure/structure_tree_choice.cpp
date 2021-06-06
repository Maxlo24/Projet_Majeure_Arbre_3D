#include "structure_tree_choice.hpp"

structure_tree_choice::structure_tree_choice()
{

}



L_system structure_tree_choice::binary_tree()
{
    vector<char> alphabet = {'X','F'};
    map<char,vector<Rules>> rules;
    rules['X'] = {Rules("[-FX]+FX")};
    rules['F'] = {Rules("F")};
    return L_system(alphabet,{'F','X'},rules);
}

L_system structure_tree_choice::fractal_plant()
{
    vector<char> alphabet = {'X','F'};
    map<char,vector<Rules>> rules;
    rules['X'] = {Rules("F+[[X]-X]-F[-FX]+X")};
    rules['F'] = {Rules("FF")};
    return L_system(alphabet,{'X'},rules);
}

L_system structure_tree_choice::fractal_stick()
{
    vector<char> alphabet = {'X','F'};
    map<char,vector<Rules>> rules;
    rules['X'] = {Rules("F[+X]F[-X]+X")};
    rules['F'] = {Rules("FF")};
    return L_system(alphabet,{'X'},rules);
}

L_system structure_tree_choice::fractal_sym()
{
    vector<char> alphabet = {'Y','X','F'};
    map<char,vector<Rules>> rules;
    rules['Y'] = {Rules("X[-FFF][+FFF]FX")};
    rules['X'] = {Rules("YFX[+Y][-Y]")};
    rules['F'] = {Rules("F")};
    return L_system(alphabet,{'Y'},rules);
}

L_system structure_tree_choice::fractal_bush()
{
    vector<char> alphabet = {'F'};
    map<char,vector<Rules>> rules;
    rules['F'] = {Rules("FF+[+F-F-F]-[-F+F+F]")};
    return L_system(alphabet,{'F'},rules);
}

L_system structure_tree_choice::fractal_leaf()
{
    vector<char> alphabet = {'F','X','Y','Z','W'};
    map<char,vector<Rules>> rules;
    rules['F'] = {Rules("F")};
    rules['X'] = {Rules("Z")};
    rules['Y'] = {Rules("W")};
    rules['Z'] = {Rules("F[+X]FW")};
    rules['W'] = {Rules("F[-Y]FZ")};
    return L_system(alphabet,{'Z'},rules);
}

L_system structure_tree_choice::fractal_fir()
{
    vector<char> alphabet = {'X','Y','Z','V','W','F'};
    map<char,vector<Rules>> rules;
    rules['V'] = {Rules("[+++W][---W]YV")};
    rules['W'] = {Rules("+X[-W]Z")};
    rules['X'] = {Rules("-W[+X]Z")};
    rules['Y'] = {Rules("YZ")};
    rules['Z'] = {Rules("[-FFF][+FFF]F")};
    rules['F'] = {Rules("F")};
    return L_system(alphabet,{'V','Z','F','F','F'},rules);
}

L_system structure_tree_choice::fractal_dragon()
{
    vector<char> alphabet = {'X','Y','F'};
    map<char,vector<Rules>> rules;
    rules['X'] = {Rules("X+YF+")};
    rules['Y'] = {Rules("-FX-Y")};
    rules['F'] = {Rules("F")};
    return L_system(alphabet,{'F','X'},rules);
}

L_system structure_tree_choice::fractal_complex1()
{
    vector<char> alphabet = {'X','F'};
    map<char,vector<Rules>> rules;
    rules['X'] = {Rules("F+[[X]-X]-F[-FX]+X")};
    rules['F'] = {Rules("FF+[+F-F-F]-[-F+F+F]",0.2),Rules("FF",0.8)};
    return L_system(alphabet,{'X'},rules);
}
L_system structure_tree_choice::fractal_persil()
{
    vector<char> alphabet = {'X','Y','Z','V','W','F'};
    map<char,vector<Rules>> rules;
    rules['V'] = {Rules("[+++W][---W]YV")};
    rules['W'] = {Rules("+X[-W]Z")};
    rules['X'] = {Rules("-W[+X]Z",0.3),Rules("F[+X]F[-X]+X",0.6),Rules("[-FX]+FX",0.1)};
    rules['Y'] = {Rules("YZ")};
    rules['Z'] = {Rules("[-FFF][+FFF]F")};
    rules['F'] = {Rules("F",0.5),Rules("FF",0.5)};

    return L_system(alphabet,{'F','X'},rules);
}

L_system structure_tree_choice::fractal_3D_tree(){
    vector<char> alphabet = {'F','C','D','E','X','A','B','G'};
    map<char,vector<Rules>> rules;
    rules['F'] = {Rules("A[++++++&CF][-^----DF][+^^^^^EF][&&&&&-GF]")};
    rules['C'] = {Rules("B-C")};
    rules['D'] = {Rules("B+D")};
    rules['E'] = {Rules("B&E")};
    rules['G'] = {Rules("B^G")};
    rules['A'] = {Rules("BA")};
    rules['B'] = {Rules("BB")};

    return L_system(alphabet,{'F'},rules);
}

L_system structure_tree_choice::fractal_3D_tree1(){
    vector<char> alphabet = {'F','X'};
    map<char,vector<Rules>> rules;
    rules['F'] = {Rules("F")};
    //rules[X] = {Rules("\"[+FFFX]<<<[+FFFX]<<<[+FFFX]")};
    rules['X'] = {Rules("\"[&[-FX]+FX][^[-FX]+FX]")};

    return L_system(alphabet,{'F','F','F','X'},rules);
}

