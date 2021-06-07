#include "tree.hpp"

tree::tree()
{
    node *root= new node({0.f,0.f+paramLength,0});
    this->tree_root = root;
    this->data = {root};
    this->radius = {1.0,0.01};
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

node* tree::operator()(int index) const {return this->data[index];}
node*& tree::operator()(int index) {return this->data[index];}

void tree::setAlpha(float angle) {this->paramAlpha = angle;}
void tree::setBeta(float angle) {this->paramBeta = angle;}
void tree::setGamma(float angle ) {this->paramGamma = angle;}

void tree::setLength(float length) {this->paramLength = length;}
void tree::setRatio(float ratio) {this->reduction_ratio = ratio;}

void tree::add_node(node *n) {this->data.push_back(n);}

int tree::size() const {return this->data.size();}


vector<vector<int> > tree::Color() const {return color;}
vector<vector<int> > &tree::Color() {return color;}

vector<float> tree::Radius() const {return radius;}
vector<float> &tree::Radius() {return radius;}


vector<node *> tree::getData() const {return data;}
node *tree::getNode(int i) const {return data[i];}


void tree::setTree_l_system(const L_system &value) {tree_l_system = value;}

float tree::getParamScale() const {return paramScale;}
void tree::setParamScale(float value) {paramScale = value;}

float tree::getParamAlphaRandom() const {return paramAlphaRandom;}
void tree::setParamAlphaRandom(float value){paramAlphaRandom = value;}

float tree::getParamBetaRandom() const{return paramBetaRandom;}
void tree::setParamBetaRandom(float value) {paramBetaRandom = value;}

float tree::getParamGammaRandom() const {return paramGammaRandom;}
void tree::setParamGammaRandom(float value) {paramGammaRandom = value;}

void tree::setAlphabet(vector<char> alphabet){this->tree_alphabet = alphabet;}
L_system tree::getTree_l_system() const {return tree_l_system;}

L_system &tree::getTree_l_system() {return tree_l_system;}

void tree::setRules(char key, vector<Rules> value) {this->tree_rules[key]=value;}

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
}

void tree::clearData()
{
    for(auto i = 1u; i < data.size();i++){
        delete data[i];
    }
}



void tree::generateTree(int n){
    string phrase =  tree_l_system.getPhraseN(n);
    node *newN;
    node *currentNode = tree_root;
    vec3 angle = currentNode->Angle();
    vector<node*> queueNode;
    for (char type:phrase){
        if (type == 'A' || type == 'B' || type == 'C' || type == 'D' || type == 'E' || type == 'F' || type == 'G'){

            mat3 mat_Rz = mat3(cos(angle.z()) ,sin(angle.z()) ,0         ,
                               -sin(angle.z()),cos(angle.z()) ,0         ,
                               0              ,0              ,1         );

            mat3 mat_Rx = mat3(1          ,0              ,0              ,
                               0          ,cos(angle.x()) ,-sin(angle.x()),
                               0          ,sin(angle.x()) ,cos(angle.x()) );
            mat3 mat_Ry = mat3(cos(angle.y()) ,0              ,sin(angle.y()),
                               0              ,1              ,0,
                               -sin(angle.y()),0              ,cos(angle.y()));

            vec3 dP = mat_Ry*mat_Rz*mat_Rx*vec3(0,currentNode->getMultiple_scale(),0);
            newN = new node(currentNode->Coord()+dP,type,angle,currentNode,true,currentNode->getMultiple_scale());
            newN->incrementNb_parent();
            add_node(newN);
            currentNode = newN;
        }
        else if (type == 'X' || type == 'Y' || type == 'Z' || type == 'U' || type == 'V' || type == 'W'){
            node *newN = new node(currentNode->Coord(),type,angle,currentNode,false,currentNode->getMultiple_scale());
            newN->incrementNb_parent();
            add_node(newN);
            currentNode = newN;
        }else if (type == '+'){
            angle.z() += paramAlpha+paramAlphaRandom*(rand()%21-10)/200;
        }else if (type == '-'){
            angle.z() -= paramAlpha+paramAlphaRandom*(rand()%21-10)/200;
        }else if (type == '&'){
            angle.x() -= paramGamma+paramGammaRandom*(rand()%21-10)/200;
        }else if (type == '^'){
            angle.x() += paramGamma+paramGammaRandom*(rand()%21-10)/200;
        }else if (type == '/'){
            angle.y() -= paramBeta+paramBetaRandom*(rand()%21-10)/200;
        }else if (type == '\\'){
            angle.y() += paramBeta+paramBetaRandom*(rand()%21-10)/200;
        }else if (type == '_'){

        }else if (type == '-'){

        }else if (type == '|'){
            angle.z() += M_PI;
        }else if (type == '['){
            node *nodecopied = new node();
            nodecopied->copyNode(currentNode);
            nodecopied->Angle() = angle;
            queueNode.push_back(nodecopied);
        }else if (type == ']'){
            currentNode = queueNode.back();
            queueNode.pop_back();
            angle = currentNode->Angle();
        }else if (type == '"'){
            currentNode->modifyMultiple_scale(paramScale);
        }
    }
    setNodeRadius();
}

void tree::setNodeRadius()
{
    int Nr = getMaxNbrParent();
    float dr = (radius[0]-radius[1])/Nr;
    for(auto n : data){
        n->Radius() = radius[0]-dr*(n->getNb_parent());
        n->Parent()->Radius() = radius[0]-dr*(n->getNb_parent()-1);
    }
}
