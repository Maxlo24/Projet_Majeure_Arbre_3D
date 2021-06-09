#include "obj_generator.hpp"

obj_generator::obj_generator()
{
    this->name = "untitled";
    this->tree_to_generate = tree();
}

obj_generator::obj_generator(tree tree)
{
    this->name = tree.Name();
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

void obj_generator::generate(QProgressBar *progress)
{
    write_mtl();

    obj_f = ofstream(name + ".obj");
    int nbr_obj = 0;
    int nbr_node = tree_to_generate.getData().size();

    if (!obj_f.is_open())
     cout << "Impossible d'ouvrir le fichier en écriture !" << endl;
    else
     {
        // Obj title
        obj_f<<"# Tree generator V1.0 OBJ File: " << endl << "# Autors : Julien Chaize , Henri Berthelot, Maxime Gillot" << endl;
        obj_f << "o" << " " << name << "_branche_" << nbr_obj << endl;

        for(auto i=0u; i<nbr_node; ++i){
            if(tree_to_generate(i)->getVisible_node()){
                lst_coord.clear();
                lst_normal.clear();
                lst_face.clear();
                build(nbr_obj,tree_to_generate(i));
                write_obj(nbr_obj,i);
                ++nbr_obj;
            }
            progress->setValue(int(float(i)/nbr_node*100));
//            cout<<int(float(i)/nbr_node*100)<<endl;
        }
     }
    obj_f.close();

}

void obj_generator::build(int i , node *n)
{
    string s;
    vec3 actual_coord = n->Coord();
    vec3 parent_coord = n->Parent()->Coord();

    vector<vec3> mesh_vertices;
    vector<vector<int>> mesh_connectivity;

    int Nu = 6;
    int Nv = 2;
    float r1= n->Radius();
    float r2= n->Parent()->Radius();
    float dr = (r2-r1)/(Nv-1);
    float r;

    float h = n->Parent()->getMultiple_scale()/2;

    int d_face = Nu*(Nv-1);
    int d_vert = Nu*(Nv+1);

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

    angle = n->Parent()->Angle();
    mat3 mat_Rz_p = mat3(cos(angle.z()) ,sin(angle.z()) ,0         ,
                       -sin(angle.z()),cos(angle.z()) ,0         ,
                       0              ,0              ,1         );

    mat3 mat_Rx_p = mat3(1          ,0              ,0              ,
                       0          ,cos(angle.x()) ,-sin(angle.x()),
                       0          ,sin(angle.x()) ,cos(angle.x()) );
    mat3 mat_Ry_p = mat3(cos(angle.y()) ,0              ,sin(angle.y()),
                       0              ,1              ,0,
                       -sin(angle.y()),0              ,cos(angle.y()));

    for(int u=0 ; u<Nu ; ++u)
    {
        int v=0;
        r = r2-v*dr;
        x = r*std::cos(2*M_PI*float(u)/Nu);
        y = -h*float(1)/(Nv-1);
        z = r*std::sin(2*M_PI*float(u)/Nu);

        vec3 point = {x,y,z};
        point = mat_Rz_p*mat_Ry_p*mat_Rx_p*point;
        mesh_vertices.push_back(point+parent_coord);

        for(v=0 ; v<Nv ; ++v)
        {
            r = r2-(v+1)*dr/2;
            x = r*std::cos(2*M_PI*float(u)/Nu);
            y = h*float(v)/(Nv-1);
            z = r*std::sin(2*M_PI*float(u)/Nu);

            point = {x,y,z};
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


//    for(int u=0 ; u<Nu-1 ; ++u)
//    {
//        for(int v=0 ; v<Nv-1 ; ++v)
//        {
//            mesh_connectivity.push_back({u*Nv+v+1,u*Nv+v+2,(u+1)*Nv+v+2,(u+1)*Nv+v+1});
//        }
//    }
//    for(int v=0 ; v<Nv-1 ; ++v)
//    {
//        mesh_connectivity.push_back({(Nu-1)*Nv+v+1,(Nu-1)*Nv+v+2,v+2,v+1});
//    }

    for(int u=0 ; u<Nu-1 ; ++u)
    {
        for(int v=0 ; v<Nv ; ++v)
        {
            mesh_connectivity.push_back({u*(Nv+1)+v+1,u*(Nv+1)+v+2,(u+1)*(Nv+1)+v+2,(u+1)*(Nv+1)+v+1});
        }
    }
    for(int v=0 ; v<Nv ; ++v)
    {
        mesh_connectivity.push_back({(Nu-1)*(Nv+1)+v+1,(Nu-1)*(Nv+1)+v+2,v+2,v+1});
    }



    for(auto f=0u; f<mesh_connectivity.size();++f){
        s = "";
        for(int index : mesh_connectivity[f]){
            s += to_string(index+ i*d_vert)+" ";// + "/"+to_string(i+1)+"/" + to_string(f+1 + i*d_face)+" ";
        }
        //cout<<s<<endl;
        s.pop_back();
        lst_face.push_back(s);
    }
//    if(i>0){
//        for(int u=1; u<Nu;++u){
//            s = ""+ to_string((u)*Nv+(i-1)*d_vert) +" "+ to_string((u)*Nv-1+i*d_vert) +" "+ to_string((u+1)*Nv-1+i*d_vert) +" "+ to_string((u+1)*Nv+(i-1)*d_vert);
//            lst_face.push_back(s);
//        }
//    }

//    lst_normal.push_back("1.0 0.0 0.0");
}

void obj_generator::write_obj(int nbObj, int i)
{
    obj_f << "#" << name << "_branche_" << nbObj << endl;
    for(auto &coord : lst_coord){
        obj_f << "v" << " " << coord << endl;
    }
    obj_f<<endl;

    for(auto &normal : lst_normal){
        obj_f << "vn" << " " << normal << endl;
    }
    obj_f << "usemtl " << "Mat_" << tree_to_generate(i)->getNb_parent()-1 << endl;
    obj_f << "s off" << endl;
    for(auto &face : lst_face){
        obj_f << "f" << " " << face << endl;
    }
    obj_f<<endl;
}

void obj_generator::write_mtl()
{
    vector<vector<int>> c = tree_to_generate.Color();
    int nbCol = tree_to_generate.getMaxNbrParent();

    float dr = float(c[1][0] - c[0][0]) / nbCol /255;
    float dg = float(c[1][1] - c[0][1]) / nbCol /255;
    float db = float(c[1][2] - c[0][2]) / nbCol /255;

    ofstream mtl_f = ofstream(name + ".mtl");

    if (!mtl_f.is_open())
     cout << "Impossible d'ouvrir le fichier en écriture !" << endl;
    else
    {
        // Mtl title
        mtl_f<<"# Tree generator V1.0 MTL File: " << endl << "# Autors : Julien Chaize , Henri Berthelot, Maxime Gillot" << endl;

        for(int i=0; i<nbCol ;++i){
            float degrade = (float(i)/nbCol);
            degrade = degrade*degrade;

            mtl_f<< "newmtl "<< "Mat_" << i << endl;
            mtl_f<< "Kd " << float(c[0][0])/255 + degrade*i*dr <<" "<< float(c[0][1])/255 + degrade*i*dg <<" "<< float(c[0][2])/255 + degrade*i*db <<endl;

            mtl_f<<endl;
        }
    }
}
