#include "astar_algo.hpp"

ASTAR_algo::ASTAR_algo(cell *startPoint, vector<int> relPos) :Algorithm(startPoint)
{
    this->prioQueue.push(this->startPoint);
    this->relativeEnd = relPos;
}


bool ASTAR_algo::next(){
    bool ret = false;

    cell *currentCell = this->prioQueue.top();
    this->prioQueue.pop();

    map<string,cell*> neighbors = currentCell->fourN();
    for (auto const& [key, val] : neighbors) // C++ 17 !
    {

        if(val->infos() == states::clear){
            val->parent() = currentCell;
            this->prioQueue.push(val);
            val->setInfos(states::visited);
        }

        if(val->infos() == states::end){
            val->parent() = currentCell;
            ret = true;
            perfect_path(val->parent());
        }

    }
    if(this->prioQueue.size()==0)
        ret = true;

    return ret;
}

void ASTAR_algo::perfect_path(cell *last){

    cell *actual_cell = last;

    while (actual_cell->infos() != states::start) {
        actual_cell->setInfos(states::perfect_path);
        actual_cell = actual_cell->parent();
    }
}
