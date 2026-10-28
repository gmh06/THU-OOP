#include "GameSkill.h"

ISkill::~ISkill() {}

LegacySkillAdapter::LegacySkillAdapter(LegacySkill* skill) : skill(skill) {}

int LegacySkillAdapter::cast() {
    return skill->doMagicAttack();
}

MpChecker::MpChecker(ISkill* skill, int mpInit, int mpCost) : skill(skill), currentMp(mpInit), mpCost(mpCost) {}

bool MpChecker::check_currentMp_greaterorequal_than_mpCost() {
    return currentMp >= mpCost;
}

int MpChecker::cast() {
    if (check_currentMp_greaterorequal_than_mpCost()) {
        currentMp -= mpCost;
        return skill->cast();
    } else {
        std::cout << "[MP insufficient!]" << std::endl;
        return 0;
    }
}

CritBuff::CritBuff(ISkill* skill) : skill(skill) {}

int CritBuff::cast() {
    std::cout << "[Critical hit!]" << std::endl;
    return skill->cast() * 2;
}

PoisonBuff::PoisonBuff(ISkill* skill) : skill(skill) {}

int PoisonBuff::cast() {
    std::cout << "[Poison hit!]" << std::endl;
    return skill->cast() + 15;
}