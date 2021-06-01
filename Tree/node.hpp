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

private:
    vec2 coord;
    lType l_type;
    node *parent;
    float angle;

};

#endif // NODE_HPP
