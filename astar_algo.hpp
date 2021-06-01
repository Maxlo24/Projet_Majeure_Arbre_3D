#ifndef ASTAR_ALGO_HPP
#define ASTAR_ALGO_HPP
#include "algorithm.hpp"
#include <iostream>

class ASTAR_algo : public Algorithm
{
public:
    ASTAR_algo()= default;
    ASTAR_algo(cell *startPoint, vector<int> relPos);

    //inherited methodes
    bool next();


private :
    std::priority_queue<cell*, std::vector<cell*>,Compare> prioQueue;
    void perfect_path(cell *last);
};

#endif // ASTAR_ALGO_HPP
