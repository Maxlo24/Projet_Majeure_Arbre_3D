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

private:
    L_system tree_choice;



};

#endif // STRUCTURE_TREE_CHOICE_HPP
