#ifndef TREE_HPP
#define TREE_HPP
#include "../Tree/node.hpp"
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

    int size() const;


private:
    vector<node*> data;
    int data_size;

};

#endif // TREE_HPP
