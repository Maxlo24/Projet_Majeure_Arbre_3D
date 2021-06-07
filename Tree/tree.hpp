#ifndef TREE_HPP
#define TREE_HPP
#include "../Tree/node.hpp"

#define _USE_MATH_DEFINES // for C++
#include <cmath>
#include <vector>


using std::vector;

class tree
{
public:
    tree();
    tree(vector<node*> data);
    tree(node *root,float paramAlpha,float paramLength);

    node* operator()(int index) const;
    node*& operator()(int index);

    void setAlpha(float angle);
    void setBeta(float angle);
    void setGamma(float angle);
    void setLength(float length);
    void setRatio(float ratio);
    void setAlphabet(vector<char> alphabet);
    void setRules(char key, vector<Rules> velue);
    int getNbrIter() const;
    int getMaxNbrParent() const;

    void add_node(node *n);
    void add_node_last_data(node *n);
    void generateTree(L_system lSystem,int n);

    void reset();
    void clearData();

    void generateNextLayer(int iter);

    int size() const;


    vector<node *> getData() const;
    node *  getNode(int i) const;

    void setTree_l_system(const L_system &value);

    float getParamScale() const;
    void setParamScale(float value);

private:
    vector<node*> data;

    node *tree_root;

    vector<char> tree_alphabet;
    map<char,vector<Rules>> tree_rules;

    L_system tree_l_system;

    float paramAlpha = M_PI/10;
    float paramBeta = M_PI/5;
    float paramGamma = M_PI/10;
    float paramLength = 1;

    float paramScale = 1.0f;

    int nbr_iter=0;
    float reduction_ratio=0.;

};

#endif // TREE_HPP
