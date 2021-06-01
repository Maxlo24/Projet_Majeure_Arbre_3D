#include "cell.hpp"

cell::cell(states etat)
{
    this->state = etat;
}

cell::cell()
{
    this->state = states::clear;
    this->cell_parent = this;
}

// Id getter
int cell::id() const{
    return this->ID;
}

// Id setter
void cell::setId(int id){
    this->ID = id;
}

states cell::infos() const{
    return this->state;
}

void cell::setInfos(states s) {
    if ((this->state != states::clear) && (this->state != states::visited)) {
        std::cerr << "An algorithm try to cheat" << std::endl;
        throw;
    }
    if ((s != states::visited) && (s != states::perfect_path)) {
        std::cerr << "Invalid set argument" << std::endl;
        throw;
    }
    this->state = s;
}

void cell::addNeighbors(string direction, cell* ptrC) {
    if (direction == "top" || direction == "left" || direction == "right" || direction == "bot") {
        this->Neighbors[direction] = ptrC;
    }
}

map<string,cell*> cell::fourN() const{
    if (this->state == states::obstacle) {
        std::cerr << "An algorithm try to cheat" << std::endl;
        throw;
    }
    return this->Neighbors;
}

const cell* cell::parent() const{
    return this->cell_parent;
}

cell*& cell::parent(){
    return this->cell_parent;
}

states& cell::type() {
    return this->state;
}

map<string,cell*>& cell::Neighborshood() {
    return this->Neighbors;
}
