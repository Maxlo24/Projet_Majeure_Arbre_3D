#ifndef MAZE_GENERATOR_HPP
#define MAZE_GENERATOR_HPP
#include "cell.hpp"
#include <iostream>
#include <stack>
#include <vector>
#include <stdlib.h>

using std::stack;

// A class to generate a maze in a graph
class maze_generator
{
public:
    //constructors
    maze_generator()= default;
    maze_generator(cell *startPoint);

    //inherited methodes
    bool generate();


private :
    //arguments
    stack<cell*> algo_stack;
    cell *end_cell;
    int max_dist;
};

#endif // MAZE_GENERATOR_HPP
