#pragma once

#include "Operator.h"

class Constant: public Operator
{
    int data;
public:
    Constant(int d): Operator(nullptr, nullptr), data(d) {};
    int calc() override {
        return data;
    }
    void setdata(int d){
        data = d;
    }
};

class Plus: public Operator
{
public:
    Plus(Value* r1, Value* r2): Operator(r1, r2) {}
    int calc() override {
        return getV1() + getV2();
    }
};

class Sub: public Operator
{
public:
    Sub(Value* r1, Value* r2): Operator(r1, r2) {}
    int calc() override {
        return getV1() - getV2();
    }
};

class Multyply: public Operator
{
public:
    Multyply(Value* r1, Value* r2): Operator(r1, r2) {}
    int calc() override {
        return getV1() * getV2();
    }
};

class Dummy: public Operator
{
public:
    Dummy(Value* r1): Operator(r1, nullptr) {}
    int calc() override {
        return getV1();
    }
};