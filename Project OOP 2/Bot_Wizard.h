#pragma once
#include "Unit.h"
class Bot_Wizard : public Unit
{
	Spells spells[5];
public:
	Bot_Wizard();
	void attack(Unit* _target)override;
	void getDamage(int _dmg)override;
	void nextLevel()override;
	void regen_HP()override;
	void regen_MP()override;
	void show_hp() const override;
};

