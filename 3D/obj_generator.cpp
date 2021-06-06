#include "obj_generator.hpp"

obj_generator::obj_generator()
{
    this->name = "untitled";
    this->tree_to_generate = tree();
}

obj_generator::obj_generator(tree tree, std::string tree_name)
{
    this->name = tree_name;
    this->tree_to_generate = tree;
}

void obj_generator::setTree(tree tree)
{
    this->tree_to_generate = tree;
}

void obj_generator::setName(std::string name)
{
    this->name = name;
}

void obj_generator::generate()
{

    f = ofstream(name + ".obj");

    int nbr_obj = 0;

    if (!f.is_open())
     cout << "Impossible d'ouvrir le fichier en écriture !" << endl;
    else
     {
        f<<"# Tree generator V1.0 OBJ File: " << endl << "# Autors : Julien Chaize , Henri Berthelot, Maxime Gillot" << endl;

        for(int i = 0; i<tree_to_generate.getData().size(); ++i){
            if(tree_to_generate(i)->getVisible_node()){
                lst_coord.clear();
                lst_normal.clear();
                lst_face.clear();
                build(nbr_obj,tree_to_generate(i));
                write(nbr_obj);
                ++nbr_obj;
            }
        }
     }
    f.close();
}

void obj_generator::build(int i , node *n)
{
    string s;
    vec3 actual_coord = n->Coord();
    vec3 parent_coord = n->Parent()->Coord();

    vector<vec3> mesh_vertices;
    vector<vector<int>> mesh_connectivity;

    int Nu = 5;
    int Nv = 2;
    float r=0.05;
    float h = 1;

    int d_face = Nu*(Nv-1);
    int d_vert = Nu*Nv;

    float x;
    float y;
    float z;

    vec3 angle = n->Angle();
    mat3 mat_Rz = mat3(cos(angle.z()) ,sin(angle.z()) ,0         ,
                       -sin(angle.z()),cos(angle.z()) ,0         ,
                       0              ,0              ,1         );

    mat3 mat_Rx = mat3(1          ,0              ,0              ,
                       0          ,cos(angle.x()) ,-sin(angle.x()),
                       0          ,sin(angle.x()) ,cos(angle.x()) );
    mat3 mat_Ry = mat3(cos(angle.y()) ,0              ,sin(angle.y()),
                       0              ,1              ,0,
                       -sin(angle.y()),0              ,cos(angle.y()));

    for(int u=0 ; u<Nu ; ++u)
    {
        for(int v=0 ; v<Nv ; ++v)
        {
            x = r*std::cos(2*M_PI*float(u)/Nu);
            y = h*float(v)/(Nv-1);
            z = r*std::sin(2*M_PI*float(u)/Nu);

            vec3 point = {x,y,z};
            point = mat_Rz*mat_Ry*mat_Rx*point;
            mesh_vertices.push_back(point+parent_coord);
        }
    }
//    s = to_string(actual_coord.x()) + " " + to_string(actual_coord.y()) + " " + to_string(actual_coord.z());
//    lst_coord.push_back(s);


    for(vec3 coord : mesh_vertices){
        s = to_string(coord.x()) + " " + to_string(coord.y()) + " " + to_string(coord.z());
        lst_coord.push_back(s);
    }


    for(int u=0 ; u<Nu-1 ; ++u)
    {
        for(int v=0 ; v<Nv-1 ; ++v)
        {
            mesh_connectivity.push_back({u*Nv+v+1,u*Nv+v+2,(u+1)*Nv+v+2,(u+1)*Nv+v+1});
        }
    }
    for(int v=0 ; v<Nv-1 ; ++v)
    {
        mesh_connectivity.push_back({(Nu-1)*Nv+v+1,(Nu-1)*Nv+v+2,v+2,v+1});
    }



    for(int f=0; f<mesh_connectivity.size();++f){
        s = "";
        for(int index : mesh_connectivity[f]){
            s += to_string(index+ i*d_vert)+" ";// + "/"+to_string(i+1)+"/" + to_string(f+1 + i*d_face)+" ";
        }
        //cout<<s<<endl;
        s.pop_back();
        lst_face.push_back(s);
    }
//    lst_normal.push_back("1.0 0.0 0.0");
}

void obj_generator::write(int i)
{
    f << "o" << " " << name << "_branche_" << i << endl;
    for(string coord : lst_coord){
        f << "v" << " " << coord << endl;
    }

    for(string normal : lst_normal){
        f << "vn" << " " << normal << endl;
    }
    f << "s" << " " << "off" << endl;
    for(string face : lst_face){
        f << "f" << " " << face << endl;
    }
}
