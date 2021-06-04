#include "tree.hpp"

tree::tree()
{
    node *root= new node({0.f,0.f+paramLength,0});
    this->tree_root = root;
    this->data = {root};
}

tree::tree(vector<node*> data)
{
    this->data = data;
}

tree::tree(node *root,float paramAlpha,float paramLength){
    this->tree_root = root;
    this->data = {root};
    this->paramAlpha = paramAlpha;
    this->paramLength = paramLength;
}

node* tree::operator()(int index) const{
    return this->data[index];
}
node*& tree::operator()(int index){
    return this->data[index];
}

void tree::setAngle(float angle)
{
    this->paramAlpha = angle;
}

void tree::setLength(float length)
{
    this->paramLength = length;
}

void tree::setRatio(float ratio)
{
    this->reduction_ratio = ratio;
}

void tree::add_node(node *n)
{
    this->data.push_back(n);
}


int tree::size() const
{
    return this->data.size();
}

vector<node *> tree::getData() const
{
    return data;
}


void tree::setTree_l_system(const L_system &value)
{
    tree_l_system = value;
    //data[0]->Type() = tree_l_system.getAxiom();

}

void tree::setAlphabet(vector<lType> alphabet)
{
    this->tree_alphabet = alphabet;
}

void tree::setRules(lType key, vector<Rules> value)
{
    this->tree_rules[key]=value;
}

int tree::getNbrIter() const
{
    return nbr_iter;
}

int tree::getMaxNbrParent() const
{
    int max_parent = 0;
    for(node *n : data){
        if(n->getNb_parent()>max_parent) max_parent = n->getNb_parent();
    }
    return max_parent;
}

void tree::reset()
{
    clearData();
    data = {tree_root};
    nbr_iter=0;
}

void tree::clearData()
{
    for(auto i = 1; i < data.size();i++){
        delete data[i];
    }
}

void tree::generateNextLayer(int iter)
{
    generateTree(tree_l_system,iter);
    nbr_iter+=1;
}

void tree::generateTree(L_system lSystem,int n){
    vector<lType> phrase =  lSystem.getPhraseN(n);
    node *newN;
    node *currentNode = tree_root;
    //add_node(newN);
    float segment_length;
    vec3 angle = currentNode->Angle();
    vector<node*> queueNode;
    for (lType type:phrase){
        if (type == A || type == B || type == C || type == D || type == E || type == F){
            segment_length = paramLength/(1.0f+reduction_ratio*currentNode->getNb_parent());
            //vec3 dP = vec3(segment_length*sin(angle),segment_length*cos(angle),segment_length*(rand()%50-25)/25);
            mat3 mat_Rz = mat3(cos(angle.z()) ,sin(angle.z()) ,0         ,
                               -sin(angle.z()),cos(angle.z()) ,0         ,
                               0              ,0              ,1         );

            mat3 mat_Rx = mat3(1          ,0              ,0              ,
                               0          ,cos(angle.x()) ,-sin(angle.x()),
                               0          ,sin(angle.x()) ,cos(angle.x()) );

            mat3 mat_Ry = mat3(cos(angle.y()) ,0            ,sin(angle.y()) ,
                               0              ,1            ,0              ,
                               -sin(angle.y()),0            ,cos(angle.y()) );

            vec3 dP = mat_Rz*mat_Rx*mat_Ry*vec3(0,segment_length,0);
            newN = new node(currentNode->Coord()+dP,type,angle,currentNode);
            newN->visibleTrue();
            newN->incrementNb_parent();
            add_node(newN);
            currentNode = newN;
        }
        else if (type == X || type == Y || type == Z || type == U || type == V || type == W){
            node *newN = new node(currentNode->Coord(),type,angle,currentNode);
            newN->visibleFalse();
            newN->incrementNb_parent();
            add_node(newN);
            currentNode = newN;
        }else if (type == oG){
            angle.z() += paramAlpha;
        }else if (type == oD){
            angle.z() -= paramAlpha;
        }else if (type == oPb){
            angle.y() -= paramAlpha;
        }else if (type == oPh){
            angle.y() += paramAlpha;
        }else if (type == oRG){
            angle.x() -= paramAlpha;
        }else if (type == oRD){
            angle.x() += paramAlpha;
        }else if (type == oBd){

        }else if (type == oBg){

        }else if (type == oT){
            angle.z() += M_PI;
        }else if (type == oSp){
            queueNode.push_back(currentNode);
        }else if (type == oRp){
            currentNode = queueNode.back();
            queueNode.pop_back();
            angle = currentNode->Angle();
        }
    }
}
