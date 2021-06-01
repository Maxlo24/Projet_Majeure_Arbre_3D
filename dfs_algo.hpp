#ifndef DFS_ALGO_HPP
#define DFS_ALGO_HPP

#include "algorithm.hpp"
#include <iostream>

class DFS_algo : public Algorithm
{
public:
    DFS_algo()= default;
    DFS_algo(cell *startPoint);

    //inherited methodes
    bool next();


private :
    stack<cell*> algo_stack;
    void relative_path(cell *last);
};

#endif // DFS_ALGO_HPP
