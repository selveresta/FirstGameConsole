#include "Bot_Wizard.h"

Bot_Wizard::Bot_Wizard() :Unit("Merlin " + to_string(ID++), "Wizard", 200, 200)
{
	for (int i = 0; i < 4; i++)
	{
		switch (i)
		{
		case 0:
			spells[i].name_of_spells = "Fireball";
			spells[i].min_dmg = 30;
			spells[i].max_dmg = 40;
			spells[i].manacost = 30;
			break;
		case 1:
			spells[i].name_of_spells = "Ice Arrow";
			spells[i].min_dmg = 10;
			spells[i].max_dmg = 15;
			spells[i].manacost = 5;
			break;
		case 2:
			spells[i].name_of_spells = "Lightning Bolt";
			spells[i].min_dmg = 50;
			spells[i].max_dmg = 60;
			spells[i].manacost = 80;
			break;
		case 3:
			spells[i].name_of_spells = "Wall of Rocks";
			spells[i].min_dmg = 40;
			spells[i].max_dmg = 60;
			spells[i].manacost = 40;
			break;
		}
	}
}

void Bot_Wizard::attack(Unit* _target)
{
	int s = rand() % 4;
	if (spells[s].manacost > mana)
	{
		cout << "Wizard " << name << " is attacking by stick " << _target->getName() << endl;
		_target->getDamage(2);
		return;
	}
	int dmg = rand() % (spells[s].max_dmg - spells[s].min_dmg) + spells[s].min_dmg;
	cout << "Wizard " << name << " is attacking by " << spells[s].name_of_spells << " - " << _target->getName() << endl;
	mana -= spells[s].manacost;
	_target->getDamage(dmg);
	cout << endl;

}

void Bot_Wizard::getDamage(int _dmg)
{
	hp -= _dmg;
	cout << "Damage is " << _dmg << " hp." << endl;
}

void Bot_Wizard::nextLevel()
{
}

void Bot_Wizard::regen_HP()
{
	hp += 25;
}

void Bot_Wizard::regen_MP()
{
	mana += 25;
}

void Bot_Wizard::show_hp() const
{
	cout << "HP of " << name << " is " << hp << endl;
}
