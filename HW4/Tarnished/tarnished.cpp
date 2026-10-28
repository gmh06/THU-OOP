#include "tarnished.h"
#include <iostream>
Tarnished::Tarnished()
{
    for(int i = 0; i < MAX_WEAPONS; i ++)
    {
        normal_weapons[i] = nullptr;
        somber_weapons[i] = nullptr;
    }
    for(int i = 0; i < MAX_STONES; i ++)
    {
        normal_smithing_stones[i] = nullptr;
        somber_smithing_stones[i] = nullptr;
    }
}

Tarnished::~Tarnished()
{
    for(int i = 0; i < MAX_STONES; i ++)
    {
        if(normal_smithing_stones[i])
            delete normal_smithing_stones[i];
    }
    for(int i = 0; i < MAX_STONES; i ++)
    {
        if(somber_smithing_stones[i])
            delete somber_smithing_stones[i];
    }
    for(int i = 0; i < MAX_WEAPONS; i ++)
    {
        if(normal_weapons[i])
            delete normal_weapons[i];
    }
    for(int i = 0; i < MAX_WEAPONS; i ++)
    {
        if(somber_weapons[i])
            delete somber_weapons[i];
    }
}

void Tarnished::pick_up_stone(int type, int level, int number)
{
    if(type == 0) // normal
    {
        if(!normal_smithing_stones[level]){
            normal_smithing_stones[level] = new NormalSmithingStone(level);
        }

        normal_smithing_stones[level]->add(number);
    }else // somber
    {
        if(!somber_smithing_stones[level]){
            somber_smithing_stones[level] = new SomberSmithingStone(level);
        }

        somber_smithing_stones[level]->add(number);
    }
}

void Tarnished::pick_up_weapon(int type, string name)
{
    if(type == 0) // normal
    {
        for(int i = 0; i < MAX_WEAPONS; i ++){
            if(!normal_weapons[i]){
                normal_weapons[i] = new NormalWeapon(name);
                break;
            }
        }
    }else // somber
    {
        for(int i = 0; i < MAX_WEAPONS; i ++){
            if(!somber_weapons[i]){
                somber_weapons[i] = new SomberWeapon(name);
                break;
            }
        }
    }   
}

void Tarnished::upgrade_weapon(int target, string name)
{
    for(NormalWeapon* i : normal_weapons){
        if(i && i->nameIs(name)){
            i->try_upgrade(target, normal_smithing_stones);
            return;
        }
    }
    for(SomberWeapon* i : somber_weapons){
        if(i && i->nameIs(name)){
            i->try_upgrade(target, somber_smithing_stones);
            return;
        }
    }
          
    cout << "You don't have the right!" << endl;
    return;
}