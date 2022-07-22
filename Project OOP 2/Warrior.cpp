#include "Warrior.h"

Warrior::Warrior() :Unit("Barbarian " + to_string(ID++), "Warrior", 100, 100)
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
			spells[i].name_of_spells = "Double sword";
			spells[i].min_dmg = 19;
			spells[i].max_dmg = 20;
			spells[i].manacost = 5;
			break;
		case 2:
			spells[i].name_of_spells = "Fire sword";
			spells[i].min_dmg = 20;
			spells[i].max_dmg = 30;
			spells[i].manacost = 20;
			break;
		}
	}
}

void Warrior::attack(Unit* _target)
{
	int choose = 0;
	for (int i = 0; i < 3; i++)
		cout << i + 1 << ". " << spells[i].name_of_spells << "(" << spells[i].manacost << ")" << endl;

	cout << "Mana Pool of " << name << ": " << mana << endl;
	do
	{
		cout << "Choose skill: ";
		cin >> choose;
	} while (choose != 1 && choose != 2 && choose != 3);
	cout << endl;

	if (spells[choose - 1].manacost > mana)
	{
		cout << "!!No mana!!\n";
		cout << "Wizard " << name << " is attacking by sword " << _target->getName() << endl;
		_target->getDamage(10);
		return;
	}
	int dmg = rand() % (spells[choose - 1].max_dmg - spells[choose - 1].min_dmg) + spells[choose - 1].min_dmg;
	cout << "Warrior " << name << " is attacking by " << spells[choose - 1].name_of_spells << "  " << _target->getName() << endl;
	_target->getDamage(dmg);
	mana -= spells[choose - 1].manacost;
	cout << endl;
}

void Warrior::getDamage(int _dmg)
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

void Warrior::nextLevel()
{
	if (exp >= max_exp)
	{
		level++;
		max_exp += 100;
		exp = abs(max_exp - exp);
	}
}

void Warrior::regen_HP()
{
	hp += 25;
}

void Warrior::regen_MP()
{
	mana += 10;
}


void Warrior::show_hp() const
{
	cout << "HP of " << name << ": " << hp << endl;
}
