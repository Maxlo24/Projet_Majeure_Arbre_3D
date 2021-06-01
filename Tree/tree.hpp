#ifndef TREE_HPP
#define TREE_HPP
#include "../Tree/node.hpp"

#define _USE_MATH_DEFINES // for C++
#include <cmath>
#include <vector>


using std::vector;

class tree
{
public:
    tree();
    tree(vector<node*> data);

    node* operator()(int index) const;
    node*& operator()(int index);


    void add_node(node *n);
    void incrementTree(L_system lSystem,node parentNode);

    int size() const;


private:
    vector<node*> data;
    int data_size;

    float paramAlpha;
    float paramLength;

};

#endif // TREE_HPP
