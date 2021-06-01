#include "dfs_algo.hpp"

DFS_algo::DFS_algo(cell *startPoint) :Algorithm(startPoint)
{
    this->algo_stack.push(this->startPoint);
}


bool DFS_algo::next(){
    bool ret = false;

    cell *currentCell = this->algo_stack.top();
    this->algo_stack.pop();

    if(currentCell->infos() == states::clear){
        currentCell->setInfos(states::visited);
    }

    map<string,cell*> neighbors = currentCell->fourN();
    for (auto const& [key, val] : neighbors) // C++ 17 !
    {

        if(val->infos() == states::clear){
            val->parent() = currentCell;
            this->algo_stack.push(val);
        }

        if(val->infos() == states::end){
            val->parent() = currentCell;
            ret = true;
            relative_path(val->parent());
        }

    }
    if(this->algo_stack.size()==0)
        ret = true;

    return ret;
}

void DFS_algo::relative_path(cell *last) {
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
