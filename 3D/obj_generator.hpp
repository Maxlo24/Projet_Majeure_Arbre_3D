#ifndef OBJ_GENERATOR_HPP
#define OBJ_GENERATOR_HPP
#include "../Tree/tree.hpp"
#include <string>
#include <iostream>
#include <fstream>

using std::string;
using std::ofstream;
using std::cout;
using std::endl;
using std::to_string;

class obj_generator
{
public:
    obj_generator();
    obj_generator(tree tree);

    void setTree(tree tree);
    void setName(string name);

    void generate();

private:
    void build(int i,node *n);
    void write_obj(int nbObj, int node_index);
    void write_mtl();


    tree tree_to_generate;
    string name;

    vector<string> lst_coord;
    vector<string> lst_normal;
    vector<string> lst_face;

    vector<string> lst_material;

//    int last_vertex=0;
//    int last_norm=0;
//    int last_face=0;


    ofstream obj_f;
};

#endif // OBJ_GENERATOR_HPP
