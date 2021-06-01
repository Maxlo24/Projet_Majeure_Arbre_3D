#ifndef TREE_HPP
#define TREE_HPP
#include "../Tree/node.hpp"
#include <vector>


using std::vector;

class tree
{
public:
    tree();
    tree(vector<node> data);



private:
    vector<node> data;
    int data_size;

};

#endif // TREE_HPP
