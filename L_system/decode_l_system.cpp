#include "decode_l_system.hpp"





Decode_l_system::Decode_l_system()
{

}

Decode_l_system::Decode_l_system(float alpha, float length)
    :paramAlpha(alpha),paramLength(length)
{}

/*
void Decode_l_system::incrementTree(L_system lSystem,node parentNode){
    rules = lSystem.getOneRuleOfType(parentNode.Type());
    for (lType type:rules.getRule()){
        if (type == A){
            node newN(A,paramAlpha,&parentNode);

        }else if (type == B){

        }else if (type == oG){

        }else if (type == oD){

        }else if (type == oPb){

        }else if (type == oPh){

        }else if (type == oRG){

        }else if (type == oRD){

        }else if (type == oT){

        }else if (type == oSp){

        }else if (type == oRp){

        }


    }
}*/

void Decode_l_system::setParamLength(float value)
{
    paramLength = value;
}

void Decode_l_system::setParamAlpha(float value)
{
    paramAlpha = value;
}

float Decode_l_system::getParamAlpha() const
{
    return paramAlpha;
}

float Decode_l_system::getParamLength() const
{
    return paramLength;
}
