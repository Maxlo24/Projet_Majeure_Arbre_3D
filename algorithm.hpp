#ifndef ALGORITHM_H
#define ALGORITHM_H
#include "cell.hpp"
#include <vector>
#include <queue>
#include <stack>
using std::vector;
using std::queue;
using std::stack;
using std::priority_queue;

// A custom compare methode used by priority queue
struct Compare {
  bool operator()(cell*a,cell*b) {
      return a->id() > b->id();
  }
};

// Mother class for all algorithm
class Algorithm
{
public:

    //constructor
    Algorithm()=default;
    Algorithm(cell *startPoint);
    ~Algorithm();

    // pure virtual methodes
    virtual bool next()  =0;

    //
    vector<int> relEnd() const;

protected:
    cell *startPoint;
    vector<int> relativeEnd; // relative position of the end to the start point

};

#endif // ALGORITHM_H
