#ifndef NODE_HPP
#define NODE_HPP

#include<string>
#include <iostream>
#include "../vec2.hpp"
#include "../L_system/l_system.hpp"

class node
{
public:
    //constructor
    node();
    node(vec2 coord);
    node(lType l_type,float angle);
    node(lType l_type,float angle,node *parent);
    node(vec2 coord,lType l_type, node *parent);
    node(vec2 coord,lType l_type,float angle, node *parent);

    //Methodes
    vec2 Coord() const;
    vec2& Coord();

    lType Type() const;
    lType& Type();

    float Angle() const;
    float& Angle();

    const node* Parent() const;
    node*& Parent();

    int getNb_parent() const;
    void setNb_parent(int value);
    void incrementNb_parent();
    void visibleTrue();
    void visibleFalse();

    bool getVisible_node() const;

private:
    vec2 coord;
    lType l_type;
    node *parent;
    float angle;
    int nb_parent = 1;
    bool visible_node = false;

};

#endif // NODE_HPP
