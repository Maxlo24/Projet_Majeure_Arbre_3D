#ifndef RULES_H
#define RULES_H

#include <vector>
#include <string>
using std::vector;
using std::string;

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

//enum lType {A,B,C,D,E,F,G,U,V,W,X,Y,Z,oG,oD,oPb,oPh,oRG,oRD,oBd,oBg,oT,oSp,oRp,mS};

class Rules
{
private:
    float proba;
    string rule;
public:
    /** Constructor */
    Rules();
    Rules(float);
    Rules(string,float);
    Rules(string);

    /** Methods */
    float getProba();
    string getRule();
    void addElement(char);

    void operator=(Rules);


};

#endif // RULES_H
