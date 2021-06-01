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

tree::tree(node *root,float paramAlpha,float paramLength){
    this->tree_root = root;
    node *n1 = new node({root->Coord().x,root->Coord().y+paramLength});
    n1->Parent()=root;
    this->data = {root,n1};
    this->data_size = data.size();
    this->last_data = {n1};
    this->last_data_size = last_data.size();
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
    this->reduction_ration = ratio;
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

void tree::setAlphabet(vector<lType> alphabet)
{
    this->tree_alphabet = alphabet;
}

void tree::setRules(lType key, vector<Rules> value)
{
    this->tree_rules[key]=value;
}

void tree::reset()
{
    node *n1 = new node({tree_root->Coord().x,tree_root->Coord().y+paramLength});
    n1->Parent()=tree_root;
    data = {tree_root,n1};
    last_data = {n1};
    data_size=1;
    last_data_size=1;
    nbr_iter=0;
}

void tree::generateNextLayer()
{
    L_system lSys(tree_alphabet,A,tree_rules);
    vector<node*> lastDataCopy = this->last_data;
    last_data.clear();
    for (node * lnode: lastDataCopy)
    {
        this->incrementTree(lSys,lnode);
    }
    nbr_iter+=1;
}

void tree::incrementTree(L_system lSystem,node *parentNode){
    Rules rules = lSystem.getOneRuleOfType(parentNode->Type());
    float segment_length = (paramLength/(1+nbr_iter*reduction_ration));
    float angle = parentNode->Angle();
    vector<node*> queueNode;
    node *currentNode = parentNode;
    for (lType type:rules.getRule()){
        if (type == A || type == B || type == X || type == F){
            float dangle = angle-currentNode->Angle();
            vec2 dP = vec2(segment_length*sin(dangle),segment_length*cos(dangle));
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
