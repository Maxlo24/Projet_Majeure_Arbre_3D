#ifndef DIJKSTRA_ALGO_HPP
#define DIJKSTRA_ALGO_HPP
#include "algorithm.hpp"
#include <iostream>
#include <vector>


// Class of the dijkstra algorithme, heritate of Algorithme
class Dijkstra_algo : public Algorithm
{
public:
    //constructors
    Dijkstra_algo();
    Dijkstra_algo(cell *startPoint);

    //inherited methodes
    bool next();


private:
    //arguments
    std::priority_queue<cell*, std::vector<cell*>,Compare> algo_queue;
    //methode
    void perfect_path(cell *last);
};

#endif // DIJKSTRA_ALGO_HPP
