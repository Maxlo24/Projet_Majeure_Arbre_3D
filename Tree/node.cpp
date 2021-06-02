#include "node.hpp"


node::node()
{
    this->coord = vec3(0,0,0);
    this->l_type = lType(X);
    this->parent = this;
}

node::node(vec3 coord)
{
    this->coord = coord;
    this->l_type = lType(X);
    this->angle = 0;
    this->parent = this;
}

node::node(lType l_type,float angle)
{
    this->coord = vec3(0,0,0);
    this->l_type = l_type;
    this->angle = angle;
    this->parent = this;

}

node::node(lType l_type,float angle, node* parent)
{
    this->coord = vec3(0,0,0);
    this->l_type = l_type;
    this->angle = angle;
    this->parent = parent;

}

node::node(vec3 coord,lType l_type, node *parent)
{
    this->coord = coord;
    this->l_type = l_type;
    this->angle = 0;
    this->parent = parent;
}
node::node(vec3 coord,lType l_type,float angle , node *parent)
{
    this->coord = coord;
    this->l_type = l_type;
    this->angle = angle;
    this->parent = parent;
}



vec3 node::Coord() const
{
    return this->coord;
}

vec3& node::Coord()
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

float node::Angle() const
{
    return this->angle;
}

float& node::Angle()
{
    return this->angle;
}

const node* node::Parent() const
{
    return this->parent;
}

node*& node::Parent()
{
    return this->parent;
}

int node::getNb_parent() const
{
    return nb_parent;
}

void node::setNb_parent(int value)
{
    nb_parent = value;
}

void node::incrementNb_parent()
{
    nb_parent = parent->getNb_parent() +1;
}

void node::visibleTrue()
{
    visible_node = true;
}

void node::visibleFalse()
{
    visible_node = false;
}

bool node::getVisible_node() const
{
    return visible_node;
}

