#ifndef STRUCTURE_TREE_CHOICE_HPP
#define STRUCTURE_TREE_CHOICE_HPP

#include "../L_system/l_system.hpp"

#include <string>
using std::string;

class structure_tree_choice
{
public:
    structure_tree_choice();

    Rules decryptRule(string rule,float E=1.0);

    L_system binary_tree();
    L_system fractal_plant();
    L_system fractal_stick();
    L_system fractal_sym();
    L_system fractal_bush();
    L_system fractal_leaf();
    L_system fractal_fir();
    L_system fractal_dragon();
    L_system fractal_complex1();
<<<<<<< HEAD
    L_system fractal_complex2();
    L_system fractal_3D_tree();
=======
    L_system fractal_persil();
>>>>>>> eb0bf4485daa82493e6f505f48d9ffd5035c9fdd


private:
    L_system tree_choice;



};

#endif // STRUCTURE_TREE_CHOICE_HPP
