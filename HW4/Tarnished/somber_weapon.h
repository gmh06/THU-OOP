#pragma once

#include "weapon.h"
#include <string>
#include <iostream>
using namespace std;

class SomberWeapon: public Weapon
{
private:
    string my_name() const
    {
        if(get_level()){
            return get_name() + "+" + to_string(get_level());
        }else{
            return get_name();
        }
    }

public:
    SomberWeapon(string name): Weapon(name) {
        cout << "Somber weapon " << name << " was created." << endl;
    }
    ~SomberWeapon(){
        cout << "Somber weapon " << my_name() << " was destroyed." << endl;
    }
    bool nameIs(string target) const
    {
        return get_name() == target;
    }
    void try_upgrade(int target, SomberSmithingStone** stone)
    {
        if(target <= get_level()){
            cout << "Stay calm!" << endl;
            return;
        }

        // pre-check
        for(int i = get_level() + 1; i <= target; i ++){
            if(stone[i] && stone[i]->sufficient(1)){
                continue;
            }else{
                cout << "Upgrade failed for lacking somber smithing stone " << i << "." << endl;
                return;
            }
        }

        // do
        string start = my_name();
        for(int i = get_level() + 1; i <= target; i ++){
            stone[i]->consume(1);
            if(stone[i]->empty()){
                delete stone[i];
                stone[i] = nullptr;
            }

            string oldname = my_name();
            upgrade();
            cout << "Somber weapon " << oldname << " was upgraded to " << my_name() << "." << endl;
        }

        cout << "Upgrade " << start << " to " << my_name() << " Successfully." << endl;
    }
};