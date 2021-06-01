#ifndef BFS_ALGO_HPP
#define BFS_ALGO_HPP
#include "algorithm.hpp"
#include <iostream>

class BFS_algo : public Algorithm
{
public:
    //constructors
    BFS_algo()= default;
    BFS_algo(cell *startPoint);

    //inherited methodes
    bool next();


private :
    //arguments
    queue<cell*> algo_queue;
    //methodes
    void perfect_path(cell *last);
};

#endif // BFS_ALGO_HPP
