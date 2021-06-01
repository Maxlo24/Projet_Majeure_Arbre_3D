#include "tree.hpp"

tree::tree()
{
    this->data = {};
    this->data_size = 0;
}

tree::tree(vector<node*> data)
{
    this->data = data;
    this->data_size = data.size();
    this->last_data = data;
    this->last_data_size = last_data.size();
}


node* tree::operator()(int index) const{
    return this->data[index];
}
node*& tree::operator()(int index){
    return this->data[index];
}

void tree::add_node(node *n)
{
    this->data.push_back(n);
    this->data_size+=1;
}

void tree::add_node_last_data(node *n)
{
    this->last_data.push_back(n);
    this->last_data_size+=1;
}

int tree::size() const
{
    return this->data_size;
}

vector<node *> tree::getData() const
{
    return data;
}

vector<node *> tree::getLastData() const
{
    return last_data;
}


void tree::incrementTree(L_system lSystem,node *parentNode){
    Rules rules = lSystem.getOneRuleOfType(parentNode->Type());
    float angle = parentNode->Angle();
    vector<node*> queueNode;
    node *currentNode = parentNode;
    last_data.clear();
    for (lType type:rules.getRule()){
        if (type == A || type == B || type == X || type == F){
            float dangle = angle-currentNode->Angle();
            vec2 dP = vec2(paramLength*sin(dangle),paramLength*cos(dangle));
            node *newN = new node(currentNode->Coord()+dP,type,angle,currentNode);
            add_node(newN);
            add_node_last_data(newN);
            currentNode = newN;
        }else if (type == oG){
            angle += paramAlpha;
        }else if (type == oD){
            angle -= paramAlpha;
        }else if (type == oPb){

        }else if (type == oPh){

        }else if (type == oRG){

        }else if (type == oRD){

        }else if (type == oT){
            angle += M_PI;
        }else if (type == oSp){
            queueNode.push_back(currentNode);
        }else if (type == oRp){
            currentNode = queueNode.back();
            queueNode.pop_back();
            angle = currentNode->Angle();
        }
    }
   }
