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
    void add_node_last_data(node *n);
    void incrementTree(L_system lSystem,node *parentNode);

    int size() const;


    vector<node *> getData() const;
    vector<node *> getLastData() const;

private:
    vector<node*> data;
    int data_size;
    vector<node*> last_data;
    int last_data_size;

    float paramAlpha = M_PI/10;
    float paramLength = 40;
    int nbr_iter;

};

#endif // TREE_HPP
