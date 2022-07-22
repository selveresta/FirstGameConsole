#include "Bot_Warrior.h"

Bot_Warrior::Bot_Warrior() :Unit("Barbarian " + to_string(ID++), "Warrior", 100, 200)
{
	armor = 50;
	for (int i = 0; i < 3; i++)
	{
		switch (i)
		{
		case 0:
			spells[i].name_of_spells = "Crit bit";
			spells[i].min_dmg = 74;
			spells[i].max_dmg = 75;
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
		}
	}
}

void Bot_Warrior::attack(Unit* _target)
{
	int s = rand() % 3;
	if (spells[s].manacost > mana)
	{
		cout << "Warrior " << name << " is attacking by sword " << _target->getName() << endl;
		_target->getDamage(10);
		return;
	}
	int dmg = rand() % (spells[s].max_dmg - spells[s].min_dmg) + spells[s].min_dmg;
	cout << "Warrior " << name << " is attacking by " << spells[s].name_of_spells << " - " << _target->getName() << endl;
	mana -= spells[s].manacost;
	_target->getDamage(dmg);
	cout << endl;

}

void Bot_Warrior::getDamage(int _dmg)
{
	if (armor >= _dmg)
	{
		armor -= _dmg;
		cout << "Damage is " << _dmg << " hp." << endl;
		return;
	}
	_dmg -= armor;
	armor = 0;
	hp -= _dmg;
	cout << "Damage is " << _dmg << " hp." << endl;
}

void Bot_Warrior::nextLevel()
{
}

void Bot_Warrior::regen_HP()
{
	hp += 50;
}

void Bot_Warrior::regen_MP()
{
	mana += 15;
}

void Bot_Warrior::show_hp() const
{
	cout << "HP of " << name << " is " << hp << endl;

}
