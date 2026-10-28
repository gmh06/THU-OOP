#pragma once

#include "smithing_stone.h"
#include <string>
#include <iostream>
using namespace std;

class SomberSmithingStone: public SmithingStone
{
public:
    SomberSmithingStone(int level): SmithingStone(level)
    {
        cout << "Somber smithing stone " << level << " was created." << endl;
    }
    ~SomberSmithingStone()
    {
        cout << "Somber smithing stone " << get_level() << " was destroyed." << endl;
    }
    void add(int amount)
    {
        add_amount(amount);
        cout << "Somber smithing stone " << get_level() << " was added with " << amount << "." << endl;
    }
    void consume(int amount)
    {
        add_amount(-amount);
        cout << "Somber smithing stone " << get_level() << " was subtracted with " << amount << "." << endl;
    }
    bool sufficient(int need) const
    {
        return greater_equal(need);
    }
    bool empty() const
    {
        return !greater_equal(1);
    }
};