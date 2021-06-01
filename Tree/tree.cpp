#include "tree.hpp"

tree::tree()
{
    this->data = {};
    this->data_size = 0;
}

tree::tree(vector<node*> data)
{
    this->data = data;
    this->data_size = data.size();
}


node* tree::operator()(int index) const{
    return this->data[index];
}
node*& tree::operator()(int index){
    return this->data[index];
}

void tree::add_node(node *n)
{
    this->data.push_back(n);
    this->data_size+=1;
}

int tree::size() const
{
    return this->data_size;
}
