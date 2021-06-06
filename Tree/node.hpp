#ifndef NODE_HPP
#define NODE_HPP

#include<string>
#include <iostream>
#include "../vec2.hpp"
#include "../3D/vec3.hpp"
#include "../3D/mat3.hpp"
#include "../L_system/l_system.hpp"

class node
{
public:
    //constructor
    node();
    node(vec3 coord);
    node(char l_type);
    node(char l_type,vec3 angle);
    node(char l_type,vec3 angle,node *parent);
    node(vec3 coord,char l_type, node *parent);
    node(vec3 coord,char l_type,vec3 angle, node *parent, bool visible, float mutliply_scale);

    //Methodes
    vec3 Coord() const;
    vec3& Coord();

    char Type() const;
    char& Type();

    vec3 Angle() const;
    vec3& Angle();

    const node* Parent() const;
    node*& Parent();

    int getNb_parent() const;
    void setNb_parent(int value);
    void incrementNb_parent();
    void visibleTrue();
    void visibleFalse();

    bool getVisible_node() const;

    float getMultiple_scale() const;
    void setMultiple_scale(float value);
    void modifyMultiple_scale(float value);

    void copyNode(node *);

private:
    vec3 coord;
    char l_type;
    node *parent;
    vec3 angle = {0,0,0};
    int nb_parent = 1;
    bool visible_node = false;
    float multiple_scale;

};

#endif // NODE_HPP
