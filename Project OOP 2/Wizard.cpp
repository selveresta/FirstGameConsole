#include "Wizard.h"


Wizard::Wizard() :Unit("Merlin " + to_string(ID++), "Wizard", 200, 200) {
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

void Wizard::attack(Unit* _target)
{
	int choose = 0;
	for (int i = 0; i < 3; i++)
		cout << i + 1 << ". " << spells[i].name_of_spells << "(" << spells[i].manacost << ")" << endl;

	cout << "Mana Pool of " << name << ": " << mana << endl;

	do
	{
		cout << "Choose skill: ";
		cin >> choose;
	} while (choose != 1 && choose != 2 && choose != 3 && choose != 4);
	cout << endl;

	if (spells[choose - 1].manacost > mana)
	{
		cout << "Wizard " << name << " is attacking by stick " << _target->getName() << endl;
		_target->getDamage(2);
		return;
	}
	int dmg = rand() % (spells[choose - 1].max_dmg - spells[choose - 1].min_dmg) + spells[choose - 1].min_dmg;
	cout << "Wizard " << name << " is attacking by " << spells[choose - 1].name_of_spells << " - " << _target->getName() << endl;
	mana -= spells[choose - 1].manacost;
	_target->getDamage(dmg);
	cout << endl;
}

void Wizard::getDamage(int _dmg)
{
	hp -= _dmg;
	cout << "Damage is " << _dmg << " hp." << endl;
}

void Wizard::nextLevel()
{
	if (exp == max_exp)
	{
		level++;
		max_exp += 100;
		exp = abs(max_exp - exp);
	}
}

void Wizard::regen_HP()
{
	hp += 25;
}

void Wizard::regen_MP()
{
	mana += 25;
}


void Wizard::show_hp() const
{
	cout << "HP of " << name << " is " << hp << endl;
}

