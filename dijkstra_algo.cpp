#include "dijkstra_algo.hpp"

Dijkstra_algo::Dijkstra_algo(cell *startPoint) :Algorithm(startPoint)
{
    this->algo_queue.push(this->startPoint);
    startPoint->setId(0);
}

bool Dijkstra_algo::next(){
    bool ret = false;
    cell *currentCell = this->algo_queue.top();
    this->algo_queue.pop();


    map<string,cell*> neighbors = currentCell->fourN();
    for (auto const& [key, val] : neighbors) // C++ 17 !
    {

        if(val->infos() == states::clear){
            val->setId(currentCell->id() + 1);
            val->parent() = currentCell;
            val->setInfos(states::visited);
            this->algo_queue.push(val);
        }

        if(val->infos() == states::end){
            val->parent() = currentCell;
            ret = true;
            perfect_path(val->parent());
        }

    }
    if(this->algo_queue.size()==0)
        ret = true;

    return ret;
}


void Dijkstra_algo::perfect_path(cell *last){

    cell *actual_cell = last;

    while (actual_cell->infos() != states::start) {
        actual_cell->setInfos(states::perfect_path);
        actual_cell = actual_cell->parent();
    }
}

