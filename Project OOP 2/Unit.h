#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <stdio.h>
#include <conio.h>
#include <cmath>
#include <memory>
#include <fstream>
using namespace std;

struct Spells
{
	string name_of_spells;
	int min_dmg = 0;
	int max_dmg = 0;
	int manacost = 0;
};

class Unit
{
protected:
	static int ID;
	int hp;
	int mana;
	int level = 1;
	int exp = 0;
	int max_exp = 100;
	string name;
	string classUnit;
public:
	Unit(const string& _name, const string& _class, int h, int mana);
	virtual void attack(Unit* _target) = 0;
	virtual void getDamage(int _dmg) = 0;
	virtual void nextLevel() = 0;
	virtual void show_hp()const = 0;
	virtual void regen_HP() = 0;
	virtual void regen_MP() = 0;
	virtual ~Unit();
	const string& getName()const;
	void setName(const string& _n);
	bool isAlive()const;

	void save(fstream& heroUnit);
	void load(fstream& heroUnit);

	int getHP()const;
	void setHP(int hp);
	int getMP()const;
	void setMP(int mp);
	int getLVL()const;
	void setLVL(int lvl);
	void setExp(int _exp);
	int getExp() const;
	void setMExp(int _exp);
	int getMExp() const;

	void setClass(string CLS);
	string getClass()const;
};


