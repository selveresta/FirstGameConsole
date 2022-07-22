#include "Unit.h"
int Unit::ID = 1;

Unit::Unit(const string& _name, const string& _class, int h, int m)
{
	name = _name;
	hp = h;
	mana = m;
	classUnit = _class;
}


///VIRTUAL FUNC
void Unit::attack(Unit* _target) {}
void Unit::getDamage(int _dmg) {}
void Unit::nextLevel() {}
void Unit::show_hp() const {}
Unit::~Unit() = default;
///VIRTUAL FUNC



bool Unit::isAlive() const
{
	return hp > 0;
}

void Unit::save(fstream & heroUnit)
{
	int len_class = classUnit.size();
	heroUnit.write((char*)len_class, sizeof(char));
	heroUnit.write((char*)&classUnit, len_class);
	heroUnit.write((char*)&hp, sizeof(int));
	heroUnit.write((char*)&mana, sizeof(int));
	heroUnit.write((char*)&level, sizeof(int));
	heroUnit.write((char*)&exp, sizeof(int));
	heroUnit.write((char*)&max_exp, sizeof(int));
	int len_name = name.size();
	heroUnit.write((char*)len_name, sizeof(char));
	heroUnit.write(&name[0], len_name);
}

void Unit::load(fstream & heroUnit)
{
	heroUnit.read((char*)&hp, sizeof(int));
	heroUnit.read((char*)&mana, sizeof(int));
	heroUnit.read((char*)&level, sizeof(int));
	heroUnit.read((char*)&exp, sizeof(int));
	heroUnit.read((char*)&max_exp, sizeof(int));
	int len_name = 0;
	heroUnit.read((char*)len_name, sizeof(char));
	name.resize(len_name);
	heroUnit.read(&name[0], len_name);
}

///SETTRES GETTERS
const string& Unit::getName() const
{
	return name;
}

void Unit::setName(const string& _n)
{
	name = _n;
}

int Unit::getHP() const
{
	return hp;
}

void Unit::setHP(int hp)
{
	this->hp = hp;
}

int Unit::getMP() const
{
	return mana;
}

void Unit::setMP(int mp)
{
	mana = mp;
}

int Unit::getLVL() const
{
	return level;
}

void Unit::setLVL(int lvl)
{
	level = lvl;
}

void Unit::setExp(int _exp)
{
	exp = _exp;
}

int Unit::getExp() const
{
	return exp;
}

void Unit::setMExp(int _exp)
{
	max_exp = _exp;
}

int Unit::getMExp() const
{
	return max_exp;
}

void Unit::setClass(string CLS)
{
	classUnit = CLS;
}

string Unit::getClass() const
{
	return classUnit;
}
///SETTRES GETTERS
