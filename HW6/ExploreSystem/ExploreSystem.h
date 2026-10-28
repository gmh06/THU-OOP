#pragma once

#include <string>
#include <iostream>

class Player;
class Dungeon;

class Weapon
{
public:
    float value;
    Weapon(float value);
    virtual ~Weapon()=0;
    virtual float calc_score(int level)=0;
    virtual void strengthen()=0;
};

class Sword: public Weapon
{
public:
    Sword(float value);
    float calc_score(int level) override;
    void strengthen() override;
};

class Staff: public Weapon
{
public:
    Staff(float value);
    float calc_score(int level) override;
    void strengthen() override;
};

class Dagger: public Weapon
{
public:
    Dagger(float value);
    float calc_score(int level) override;
    void strengthen() override;
};

class Player
{
    Weapon* weapon;
    int tool_score;
public:
    Player(Weapon* weapon, int tool_score);
    float Explore(int level);
    int& get_tool_score();
    Weapon* get_weapon();
};

class Dungeon
{
public:
    int level;
    Dungeon(int level);
    virtual ~Dungeon()=0;
    virtual float startExplore(Player* player)=0;
};

class Normal: public Dungeon
{
public:
    Normal(int level);
    float startExplore(Player* player) override;
};

class WeaponEnhance: public Dungeon
{
public:
    WeaponEnhance(int level);
    float startExplore(Player* player) override;
};

class ToolSeal: public Dungeon
{
public:
    ToolSeal(int level);
    float startExplore(Player* player) override;
};

Player* createPlayer(std::string weaponName, float weaponValue, std::string toolName);
Dungeon* createDungeon(std::string dungeonName, int level);
