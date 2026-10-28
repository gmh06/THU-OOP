#pragma once

#include "smithing_stone.h"
#include <string>
#include <iostream>
using namespace std;

class NormalSmithingStone: public SmithingStone
{
public:
    NormalSmithingStone(int level): SmithingStone(level)
    {
        cout << "Normal smithing stone " << level << " was created." << endl;
    }
    ~NormalSmithingStone()
    {
        cout << "Normal smithing stone " << get_level() << " was destroyed." << endl;
    }
    void add(int amount)
    {
        add_amount(amount);
        cout << "Normal smithing stone " << get_level() << " was added with " << amount << "." << endl;
    }
    void consume(int amount)
    {
        add_amount(-amount);
        cout << "Normal smithing stone " << get_level() << " was subtracted with " << amount << "." << endl;
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