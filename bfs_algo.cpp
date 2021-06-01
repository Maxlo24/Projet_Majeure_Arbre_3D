#include "bfs_algo.hpp"

BFS_algo::BFS_algo(cell *startPoint) :Algorithm(startPoint)
{
    this->algo_queue.push(this->startPoint);
}


// process the nex iteration of the algorithme
bool BFS_algo::next(){
    bool ret = false;

    cell *currentCell = this->algo_queue.front();
    this->algo_queue.pop();

    //get all the current cellneighbors
    map<string,cell*> neighbors = currentCell->fourN();
    for (auto const& [key, val] : neighbors) // C++ 17
    {

        if(val->infos() == states::clear){
            val->parent() = currentCell;
            this->algo_queue.push(val);
            val->setInfos(states::visited);
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

// generate the perfect path
void BFS_algo::perfect_path(cell *last){

    cell *actual_cell = last;

    if(actual_cell->fourN()["top"]->infos() == states::end) {
        this->relativeEnd[1] -= 1;
    }
    else if(actual_cell->fourN()["bot"]->infos() == states::end) {
        this->relativeEnd[1] += 1;
    }
    else if(actual_cell->fourN()["left"]->infos() == states::end) {
        this->relativeEnd[0] -= 1;
    }
    else if(actual_cell->fourN()["right"]->infos() == states::end) {
        this->relativeEnd[0] += 1;
    }

    while (actual_cell->infos() != states::start) {
        actual_cell->setInfos(states::perfect_path);

        if(actual_cell->parent()->fourN()["top"] == actual_cell) {
            this->relativeEnd[1] -= 1;
        }
        else if(actual_cell->parent()->fourN()["bot"] == actual_cell) {
            this->relativeEnd[1] += 1;
        }
        else if(actual_cell->parent()->fourN()["left"] == actual_cell) {
            this->relativeEnd[0] -= 1;
        }
        else if(actual_cell->parent()->fourN()["right"] == actual_cell) {
            this->relativeEnd[0] += 1;
        }

        actual_cell = actual_cell->parent();

    }
    std::cout << relativeEnd[0] << " " << relativeEnd[1] << std::endl;
}
