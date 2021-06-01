#include "algorithm.hpp"

Algorithm::Algorithm(cell *sp)
{
    this->startPoint = sp;
    this->relativeEnd.push_back(0);
    this->relativeEnd.push_back(0);
}

vector<int> Algorithm::relEnd() const {
    return this->relativeEnd;
}

Algorithm::~Algorithm(){

}
