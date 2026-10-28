#include "Map.h"

Map::Map(int n)
{
    data = new Pair[n];
    sz = 0;
}

Map::~Map()
{
    delete[] data;
}

int Map::size() const
{
    return sz;
}

int& Map::operator[](const string& k)
{
    Pair* pair = nullptr;

    for(int i = 0; i < sz; i ++){
        if(data[i].hasKey(k)){
            pair = &data[i];
        }
    }

    if(pair == nullptr){
        pair = &data[sz];
        pair->reset(k, 0);
        sz ++;
    }

    return pair->getVal();
}

int Map::operator[](const string& k) const
{
    Pair* pair = nullptr;

    for(int i = 0; i < sz; i ++){
        if(data[i].hasKey(k)){
            pair = &data[i];
        }
    }
    
    if(pair == nullptr){
        return 0;
    }

    return pair->getVal();    
}
