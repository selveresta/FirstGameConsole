#include "Group.h"
int Group::ID_group = 0;

void Group::addUnit(Unit* u)
{
	Unit** tmp = new Unit*[static_cast<int>(n_group + 1)];
	for (int i = 0; i < n_group; i++)
		tmp[i] = group[i];

	tmp[n_group] = u;
	delete[] group;
	group = tmp;
	n_group++;
}

void Group::deleteUnit()
{
	Unit** tmp = new Unit * [static_cast<int>(n_group - 1)];
	for (int i = 0; i < n_group - 1; i++)
	{
		tmp[i] = group[i];
	}
	delete[] group;
	group = tmp;
	n_group--;
}

Group::Group() = default;

void Group::attack_Group(Group* _target) // Group*
{
	int j = 0;
	for (int i = 0; i < n_group; i++)
	{
		if (!_target->group[j]->isAlive())
			j++;
		if (!group[i]->isAlive())
			i++;

		if (_target->group[j]->isAlive())
		{
			cout << group[i]->getName() << " is attacking " << _target->group[j]->getName() << endl;
			group[i]->attack(_target->group[j]);
		}
		else if (_target->group[++j] == nullptr) {
			return;
		}

	}
}





void Group::showGroup() const
{
	cout << "\tGroup " << to_string(++ID_group) << endl;
	for (int i = 0; i < n_group; i++)
	{
		cout << i + 1 << ".Name - " << group[i]->getName() << endl;
	}
}

bool Group::isAliveGroup()
{
	bool live = true;
	for (int i = 0; i < n_group; i++)
	{
		if (group[i]->isAlive())
			live = true;
		else live = false;
	}
	if (n_group < 1)
		return false;
	return live;
}

int Group::getSize() const
{
	return n_group;
}


void Group::save(fstream& GroupUnit)
{
	int n_group_save = n_group;
	GroupUnit.write((char*)&n_group_save, sizeof(int));
	for (int i = 0; i < n_group; i++)
	{

		int save_hp = group[i]->getHP();
		int save_mana = group[i]->getMP();
		int save_level = group[i]->getLVL();
		int save_exp = group[i]->getExp();
		int save_maxexp = group[i]->getMExp();

		string save_name = group[i]->getName();
		int len_name = save_name.length();
		GroupUnit.write((char*)&save_hp, sizeof(int));
		GroupUnit.write((char*)&save_mana, sizeof(int));
		GroupUnit.write((char*)&save_level, sizeof(int));
		GroupUnit.write((char*)&save_exp, sizeof(int));
		GroupUnit.write((char*)&save_maxexp, sizeof(int));
		GroupUnit.write((char*)&len_name, sizeof(char));
		GroupUnit.write((char*)&save_name, len_name);
	}

}

void Group::load(fstream& GroupUnit)
{
	GroupUnit.read((char*)n_group, sizeof(int));
	group = new Unit * [n_group];
	for (int i = 0; i < n_group; i++)
	{
		int load_hp = 0;
		int load_mana = 0;
		int load_lvl = 0;
		int load_exp = 0;
		int load_maxexp = 0;
		int len_name_load = 0;

		GroupUnit.read((char*)&load_hp, sizeof(int));
		group[i]->setHP(load_hp);

		GroupUnit.read((char*)&load_mana, sizeof(int));
		group[i]->setMP(load_mana);

		GroupUnit.read((char*)&load_lvl, sizeof(int));
		group[i]->setLVL(load_lvl);

		GroupUnit.read((char*)&load_exp, sizeof(int));
		group[i]->setExp(load_exp);

		GroupUnit.read((char*)&load_maxexp, sizeof(int));
		group[i]->setMExp(load_maxexp);

		GroupUnit.read((char*)len_name_load, sizeof(char));
		string tmp;
		tmp.resize(len_name_load);
		GroupUnit.read(&tmp[0], len_name_load);
		group[i]->setName(tmp);
	}
}


void Group::showHPMPGroup()const
{
	for (int i = 0; i < n_group; i++) {
		if (!group[i]->isAlive())
			continue;
		cout << group[i]->getName() << " " << group[i]->getHP() << " HP." << "MP = " << group[i]->getMP() << endl;

	}
	cout << endl;
}


