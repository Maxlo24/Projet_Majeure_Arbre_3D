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

enum lType {A,B,F,oG,oD,oPb,oPh,oRG,oRD,oT,oSp,oRp};
class Rules
{
private:
    float proba;
    vector<lType> rule;
public:
    /** Constructor */
    Rules();
    Rules(float,vector<lType>);

    /** Methods */
    float getProba();
    vector<lType> getRule();

};

#endif // RULES_H