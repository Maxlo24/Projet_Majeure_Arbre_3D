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

int tree::size() const
{
    return this->data_size;
}


void tree::incrementTree(L_system lSystem,node parentNode){
    Rules rules = lSystem.getOneRuleOfType(parentNode.Type());
    float angle = parentNode.Angle();
    vector<node> queueNode;
    node currentNode = parentNode;
    for (lType type:rules.getRule()){
        if (type == A || type == B){
            node *newN = new node(A,angle,&currentNode,currentNode.Coord()+vec2(paramLength*cos(angle-currentNode.Angle()),paramLength*sin(angle-currentNode.Angle())));
            data.push_back(newN);
            currentNode = *newN;
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
            angle = currentNode.Angle();
        }
    }
   }
