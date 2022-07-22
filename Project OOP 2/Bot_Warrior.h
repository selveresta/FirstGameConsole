#pragma once
#include "Unit.h"
class Bot_Warrior : public Unit
{
	int armor;
	Spells spells[3];
public:
	Bot_Warrior();
	void attack(Unit* _target)override;
	void getDamage(int _dmg)override;
	void nextLevel()override;
	void regen_HP()override;
	void regen_MP()override;
	void show_hp()const override;
};
