#include "maze_generator.hpp"

maze_generator::maze_generator(cell *startPoint)
{
    startPoint->setId(0);
    this->algo_stack.push(startPoint);
    this->max_dist = 0;
}

bool maze_generator::generate(){
    bool ret = false;

    cell *currentCell = this->algo_stack.top();
    this->algo_stack.pop();

    std::vector<cell*> next_cell;
    map<string,cell*> neighbors = currentCell->Neighborshood();

    for (auto const& [key, val] : neighbors) // C++ 17 !
    {

        // we check if the neighbor and his neighbor in the same direction are valid
        if(val->type() == states::obstacle){
            map<string,cell*> neighbor_neighbors = val->Neighborshood();
            if(neighbor_neighbors[key]->type() == states::obstacle || (neighbor_neighbors[key]->type() == states::clear && rand()%30<1)){
                val->type() = states::clear;
                neighbor_neighbors[key]->type()=states::clear;
                next_cell.push_back(neighbor_neighbors[key]);
            }
        }
    }
    //if we are in a dead end
    if(next_cell.size() == 0){
        if(this->max_dist < currentCell->id()){
            this->end_cell = currentCell;
            this->max_dist = currentCell->id();
        }
    }

    //for every new path we select on random to put on top
    while (next_cell.size() != 0) {
        int dir = rand() %next_cell.size();
        next_cell[dir]->setId(currentCell->id()+1);
        this->algo_stack.push(next_cell[dir]);
        next_cell.erase(next_cell.begin()+dir);
    }

    if (this->algo_stack.empty()){
        this->end_cell->type() = states::end;
        ret = true;
    }

    return ret;
}

