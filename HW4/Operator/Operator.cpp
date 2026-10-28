#include "Operator.h"
Operator::Operator(Value *r1, Value *r2)
{
    v1 = r1;
    v2 = r2;
}
int Operator::getV1()
{
    if(v1){
        return v1->calc();
    }
        return 0;
}
int Operator::getV2()
{
    if(v2){
        return v2->calc();
    }
    return 0;
}