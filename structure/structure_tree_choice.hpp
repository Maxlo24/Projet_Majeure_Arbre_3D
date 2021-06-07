#ifndef STRUCTURE_TREE_CHOICE_HPP
#define STRUCTURE_TREE_CHOICE_HPP

#include "../L_system/l_system.hpp"

#include <string>
using std::string;

class structure_tree_choice
{
public:
    structure_tree_choice();

    L_system fractal_custom();

    L_system binary_tree();
    L_system fractal_plant();
    L_system fractal_stick();
    L_system fractal_sym();
    L_system fractal_bush();
    L_system fractal_leaf();
    L_system fractal_fir();
    L_system fractal_dragon();

    L_system fractal_complex1();
    L_system fractal_persil();
    L_system fractal_complex2();

    L_system fractal_3D_tree();
    L_system fractal_3D_tree1();



private:
    L_system tree_choice;



};

#endif // STRUCTURE_TREE_CHOICE_HPP
