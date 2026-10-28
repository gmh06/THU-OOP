# pragma once
#include "LegacySkill.h"
#include <iostream>


class ISkill
{
public:
    virtual ~ISkill()=0;
    virtual int cast()=0;

};

class LegacySkillAdapter: public ISkill
{
    LegacySkill* skill;
public:
    LegacySkillAdapter(LegacySkill* skill);
    int cast() override;
};

class MpChecker: public ISkill
{
    ISkill* skill;
    int currentMp;
    int mpCost;

    bool check_currentMp_greaterorequal_than_mpCost();

public:
    MpChecker(ISkill* skill, int mpInit, int mpCost);
    int cast() override;
};

class CritBuff: public ISkill
{
    ISkill* skill;
public:
    CritBuff(ISkill* skill);
    int cast() override;
};

class PoisonBuff: public ISkill
{
    ISkill* skill;
public:
    PoisonBuff(ISkill* skill);
    int cast() override;
};
