#include "node.hpp"


node::node()
{
    this->coord = vec2(0,0);
    this->l_type = lType(A);
    this->parent = nullptr;
}

node::node(vec2 coord)
{
    this->coord = coord;
    this->l_type = lType(A);
    this->angle = 0;
    this->parent = nullptr;
}

node::node(lType l_type,float angle, node* parent)
{
    this->coord = vec2(0,0);
    this->l_type = l_type;
    this->angle = angle;
    this->parent = parent;

}

node::node(vec2 coord,lType l_type, node *parent)
{
    this->coord = coord;
    this->l_type = l_type;
    this->angle = 0;
    this->parent = parent;
}


vec2 node::Coord() const
{
    return this->coord;
}

vec2& node::Coord()
{
    return this->coord;
}


lType node::Type() const
{
    return this->l_type;
}

lType& node::Type()
{
    return this->l_type;
}

const node* node::Parent() const
{
    return this->parent;
}

node*& node::Parent()
{
    return this->parent;
}

