#include "ExploreSystem.h"

// Weapon implementation
Weapon::Weapon(float value) : value(value) {}
Weapon::~Weapon() {}

// Sword implementation
Sword::Sword(float value) : Weapon(value) {}
float Sword::calc_score(int level) {
    return value - level;
}
void Sword::strengthen() {
    value *= 1.05;
}

// Staff implementation
Staff::Staff(float value) : Weapon(value) {}
float Staff::calc_score(int level) {
    if (level > value) {
        return 0;
    }
    return value / 2.0;
}
void Staff::strengthen() {
    value *= 1.1;
}

// Dagger implementation
Dagger::Dagger(float value) : Weapon(value) {}
float Dagger::calc_score(int level) {
    return level;
}
void Dagger::strengthen() {
    // Dagger strengthening has no effect
}

// Player implementation
Player::Player(Weapon* weapon, int tool_score) : weapon(weapon), tool_score(tool_score) {}
float Player::Explore(int level) {
    return weapon->calc_score(level) + tool_score;
}
int& Player::get_tool_score() {
    return tool_score;
}
Weapon* Player::get_weapon() {
    return weapon;
}

// Dungeon implementation
Dungeon::Dungeon(int level) : level(level) {}
Dungeon::~Dungeon() {}

// Normal implementation
Normal::Normal(int level) : Dungeon(level) {}
float Normal::startExplore(Player* player) {
    std::cout << "Enter dungeon, level: " << level << std::endl;
    return player->Explore(level);
}

// WeaponEnhance implementation
WeaponEnhance::WeaponEnhance(int level) : Dungeon(level) {}
float WeaponEnhance::startExplore(Player* player) {
    player->get_weapon()->strengthen();
    std::cout << "Enter weapon enhance dungeon, weapon enhanced, level: " << level << std::endl;
    return player->Explore(level);
}

// ToolSeal implementation
ToolSeal::ToolSeal(int level) : Dungeon(level) {}
float ToolSeal::startExplore(Player* player) {
    player->get_tool_score() = -1;
    std::cout << "Enter tool seal dungeon, tool disabled, level: " << level << std::endl;
    return player->Explore(level) * 2;
}

// Factory functions
Player* createPlayer(std::string weaponName, float weaponValue, std::string toolName) {
    Weapon* weapon = nullptr;
    if (weaponName == "sword") {
        weapon = new Sword(weaponValue);
    } else if (weaponName == "staff") {
        weapon = new Staff(weaponValue);
    } else if (weaponName == "dagger") {
        weapon = new Dagger(weaponValue);
    }

    int tool_score = 0;
    if (toolName == "torch") {
        tool_score = 3;
    } else if (toolName == "detector") {
        tool_score = 6;
    } else if (toolName == "toolkit") {
        tool_score = 9;
    }

    return new Player(weapon, tool_score);
}

Dungeon* createDungeon(std::string dungeonName, int level) {
    if (dungeonName == "normal") {
        return new Normal(level);
    } else if (dungeonName == "toolseal") {
        return new ToolSeal(level);
    } else if (dungeonName == "weaponenhance") {
        return new WeaponEnhance(level);
    }
    return nullptr;
}