#include "node.hpp"


node::node()
{
    this->coord = vec3(0,0,0);
    this->l_type = lType(X);
    this->parent = this;
    this->multiple_scale = 1.0f;
}

node::node(lType l_type)
{
    this->coord = vec3(0,0,0);
    this->l_type = l_type;
    this->parent = this;
    this->multiple_scale = 1.0f;
}

node::node(vec3 coord)
{
    this->coord = coord;
    this->l_type = lType(F);
    this->angle = {0,0,0};
    this->parent = this;
    this->multiple_scale = 1.0f;
}

node::node(lType l_type,vec3 angle)
{
    this->coord = vec3(0,0,0);
    this->l_type = l_type;
    this->angle = angle;
    this->parent = this;
    this->multiple_scale = 1.0f;

}

node::node(lType l_type,vec3 angle, node* parent)
{
    this->coord = vec3(0,0,0);
    this->l_type = l_type;
    this->angle = angle;
    this->parent = parent;
    this->multiple_scale = 1.0f;

}

node::node(vec3 coord,lType l_type, node *parent)
{
    this->coord = coord;
    this->l_type = l_type;
    this->angle = {0,0,0};
    this->parent = parent;
    this->multiple_scale = 1.0f;
}
node::node(vec3 coord,lType l_type,vec3 angle , node *parent, bool visible, float multiply_Scale)
{
    this->coord = coord;
    this->l_type = l_type;
    this->angle = angle;
    this->parent = parent;
    this->multiple_scale = 1.0f;
    this->visible_node = visible;
    this->multiple_scale = multiple_scale;

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

vec3 node::Angle() const
{
    return this->angle;
}

vec3& node::Angle()
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

float node::getMultiple_scale() const
{
    return multiple_scale;
}

void node::setMultiple_scale(float value)
{
    multiple_scale = value;
}

void node::modifyMultiple_scale(float value)
{
    multiple_scale = value*multiple_scale;
}

