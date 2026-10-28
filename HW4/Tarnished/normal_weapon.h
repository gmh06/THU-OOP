#pragma once

#include "weapon.h"
#include <string>
#include <iostream>
using namespace std;

class NormalWeapon: public Weapon
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
    NormalWeapon(string name): Weapon(name) {
        cout << "Normal weapon " << name << " was created." << endl;
    }
    ~NormalWeapon(){
        cout << "Normal weapon " << my_name() << " was destroyed." << endl;
    }
    bool nameIs(string target) const
    {
        return get_name() == target;
    }
    void try_upgrade(int target, NormalSmithingStone** stone)
    {
        if(target <= get_level()){
            cout << "Stay calm!" << endl;
            return;
        }

        // pre-check
        int k = get_level()/3 + 1;
        int needed = 0;
        for(int i = get_level() + 1; i <= target; i ++){
            int now_k = (i - 1)/3 + 1;
            if(k == now_k){
                switch(i % 3){
                    case 0: needed += 6; break;
                    case 1: needed += 2; break;
                    case 2: needed += 4; break;
                } 
            }else{
                if(stone[k] && stone[k]->sufficient(needed)){
                    needed = 2;
                    k = now_k;
                }else{
                    cout << "Upgrade failed for lacking normal smithing stone " << k << "." << endl;
                    return;
                }
            }
        }

        if(stone[k] && stone[k]->sufficient(needed)){
            needed = 0;
        }else{
            cout << "Upgrade failed for lacking normal smithing stone " << k << "." << endl;
            return;
        }

        // do
        string start = my_name();
        for(int i = get_level() + 1; i <= target; i ++){
            k = (i - 1)/3 + 1;
            switch(i % 3){
                case 0: needed = 6; break;
                case 1: needed = 2; break;
                case 2: needed = 4; break;
            }

            stone[k]->consume(needed);
            if(stone[k]->empty()){
                delete stone[k];
                stone[k] = nullptr;
            }

            string oldname = my_name();
            upgrade();
            cout << "Normal weapon " << oldname << " was upgraded to " << my_name() << "." << endl;
        }

        cout << "Upgrade " << start << " to " << my_name() << " Successfully." << endl;
    }
};