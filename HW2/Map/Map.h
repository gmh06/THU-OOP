#pragma once
#include "Pair.h"

class Map{
    Pair * data;
    int sz;
public:
    Map(int n);
    ~Map();
    int size() const;
    int & operator [](const string & k);
    int operator [](const string & k) const;
};