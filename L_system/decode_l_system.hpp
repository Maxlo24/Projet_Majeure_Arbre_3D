#ifndef DECODE_L_SYSTEM_HPP
#define DECODE_L_SYSTEM_HPP


#include "../Tree/node.hpp"


class Decode_l_system
{
private:
    Rules rules;
    vector<node*> nodes;
    float paramAlpha;
    float paramLength;
public:
    Decode_l_system();

    void incrementLSystem(L_system,node);


    void setParamAlpha(float value);
    void setParamLength(float value);
    float getParamAlpha() const;
    float getParamLength() const;
};

#endif // DECODE_L_SYSTEM_HPP
