#pragma once
#include "Unit.h"
class Group
{
	static int ID_group;
	Unit** group = nullptr;
	int n_group = 0;
public:
	Group();
	void attack_Group(Group* _target);
	void addUnit(Unit* u);
	void deleteUnit();
	bool isAliveGroup();
	int getSize()const;
	void showGroup()const;
	void save(fstream& GroupUnit);
	void load(fstream& GroupUnit);
	void showHPMPGroup()const;
};

