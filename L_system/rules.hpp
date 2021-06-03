#ifndef RULES_H
#define RULES_H

#include <vector>
using std::vector;


/*
 * oG : tourner à gauche
 * oD : tourner à droite
 * oPd : pivoter vers le bas
 * oPh : pivoter vers le haut
 * oRg : rouler vers la gauche
 * oRD : rouler vers la droite
 * oT : tourner sur soit même de 180°
 * oSp : sauvegarder la dernière position
 * oRp : restaurer la dernière position
 */

enum lType {A,B,C,D,E,F,U,V,W,X,Y,Z,oG,oD,oPb,oPh,oRG,oRD,oBd,oBg,oT,oSp,oRp};
class Rules
{
private:
    float proba;
    vector<lType> rule;
public:
    /** Constructor */
    Rules();
    Rules(float);
    Rules(float,vector<lType>);

    /** Methods */
    float getProba();
    vector<lType> getRule();
    void addElement(lType);


};

#endif // RULES_H
