#include "Menu.h"
#pragma once
#include "Menu.h"

void Play_solo() {
	Unit* unit1 = nullptr;
	Unit* unit2 = nullptr;
	int choose;
	do {
		system("cls");
		cout << "First player, pick you champion: " << endl;
		cout << "1.Warrior " << endl;
		cout << "2.Wizard" << endl;
		cout << "Enter: ";
		cin >> choose;
	} while (choose != 1 && choose != 2);
	if (choose == 1)
		unit1 = new Warrior();//unit1 = new Warrior();
	else unit1 = new Wizard();
	cout << "Enter name of ypou champion: ";
	string name;
	cin >> name;
	unit1->setName(name);
	cout << endl;

	int i = 1;
	while (unit1->isAlive())
	{
		do {
			system("cls");
			cout << "Pick you enemy: " << endl;
			cout << "1.Warrior " << endl;
			cout << "2.Wizard" << endl;
			cout << "Enter: ";
			cin >> choose;
		} while (choose != 1 && choose != 2);
		if (choose == 1)
			unit2 = new Bot_Warrior();
		else unit2 = new Bot_Wizard();

		while (unit1->isAlive() && unit2->isAlive())
		{
			cout << "~~~~~~~~~ Round" << i++ << "~~~~~~~~~`" << endl;
			unit1->attack(unit2);
			unit2->attack(unit1);
			cout << endl;
			unit1->show_hp();
			unit2->show_hp();
			cout << endl;
			int a = _getch();
		}
		if (unit1->isAlive())
			cout << unit1->getName() << " won!" << endl;
		else if (unit2->isAlive())
			cout << unit2->getName() << " won!" << endl;
		else
			cout << "Draw" << endl;
		int a = _getch();
		if (unit1->isAlive())
		{

			do
			{
				system("cls");
				cout << "1.Next enemy " << endl;
				cout << "2.Save game" << endl;
				cout << "3.Exit" << endl;
				cout << "Enter: ";
				cin >> choose;
			} while (choose != 1 && choose != 2 && choose != 3);



			switch (choose)
			{
			case 1:
				break;
			case 2:
				saveUnitMenu(unit1);
				unit1->setHP(0);
				break;
			case 3:
				unit1->setHP(0);
				break;
			default:
				break;
			}
		}

	}

	delete unit1;
	delete unit2;
}


void Play_group()
{
	int choose_group = 0;
	//string choose_group;
	//Group* group = new Group;
	unique_ptr<Group> group(new Group);
	//Group* group_enemy = new Group;
	unique_ptr<Group> group_enemy(new Group);
	do
	{

		do
		{

			system("cls");
			cout << "Add champion to you group:" << endl;
			cout << "1.Warrior " << endl;
			cout << "2.Wizard" << endl;
			cout << "0.End" << endl;
			cout << "Enter: ";
			cin >> choose_group;
			if (choose_group == 0 || choose_group == 1 || choose_group == 2)
			{
				break;
			}

		} while (true);//atoi(&choose_group[0]) != 1 && atoi(&choose_group[0]) != 2 && atoi(&choose_group[0]) != 0);


		Unit* unit;
		if (choose_group == 1) {
			unit = new Warrior();
			cout << "Enter name of you champion: ";
			string name;
			cin >> name;
			unit->setName(name);
			group->addUnit(unit);
			//delete unit;
			cout << endl;
		}
		else if (choose_group == 2) {
			unit = new Wizard();
			cout << "Enter name of you champion: ";
			string name;
			cin >> name;
			unit->setName(name);
			group->addUnit(unit);
			//delete unit;
			cout << endl;
		}

	} while (choose_group != 0);
	system("cls");
	cout << endl;
	do
	{
		do
		{
			system("cls");
			cout << "Add champion to enemy group:" << endl;
			cout << "1.Warrior " << endl;
			cout << "2.Wizard" << endl;
			cout << "0.End" << endl;
			cout << "Enter: ";
			cin >> choose_group;
			if (choose_group == 0 || choose_group == 1 || choose_group == 2)
			{
				break;
			}

		} while (true); // atoi(&choose_group[0]) != 1 && atoi(&choose_group[0]) != 2 && atoi(&choose_group[0]) != 0);

		Unit* unit;
		if (choose_group == 1) {
			unit = new Bot_Warrior();
			group_enemy->addUnit(unit);
			//delete unit;
			cout << endl;
		}
		else if (choose_group == 2) {
			unit = new Bot_Wizard();
			group_enemy->addUnit(unit);
			cout << endl;
			//delete unit;
		}


	} while (choose_group != 0);
	system("cls");
	group->showGroup();
	cout << endl;
	group_enemy->showGroup();
	cout << endl;
	cout << endl;
	int i = 1;

	while (group->isAliveGroup() && group_enemy->isAliveGroup())
	{
		cout << "~~~~~~~~~ Round" << i++ << "~~~~~~~~~`" << endl;
		group->attack_Group(group_enemy.get());
		group_enemy->attack_Group(group.get());
		group->showHPMPGroup();
		group_enemy->showHPMPGroup();
		int a = _getch();
		system("cls");
	}

	if (group->isAliveGroup())
	{
		cout << "\tWin\n";
		group->showGroup();
	}
	else
	{
		cout << "\tWin\n";
		group_enemy->showGroup();
	}
}

void saveUnitMenu(Unit* save_unit)
{
	system("cls");
	fstream save_game;
	string filename;
	cout << "Enter name of you save: ";
	cin >> filename;
	filename += ".txt";
	save_game.open(&filename[0], ios::out | ios::binary);
	if (!save_game.is_open())
		save_unit->save(save_game);
	else cout << "File not found";
	save_game.close();

}

void loadUnitMenu()
{
	system("cls");
	fstream load_game;
	string filename;
	cout << "Enter name of you save: ";
	cin >> filename;
	filename += ".txt";
	load_game.open(filename.c_str(), ios::in | ios::binary);
	Unit* load_unit = new Warrior();
	if (!load_game.is_open()) {
		load_unit->load(load_game);
		if (load_unit->getClass() == "Warrior") {
			delete load_unit;
			load_unit = new Warrior();
		}
		else if (load_unit->getClass() == "Wizard") {
			delete load_unit;
			load_unit = new Wizard();
		}
	}
	else cout << "File not found";
	load_game.close();

	Unit* unit2 = nullptr;
	int choose;
	int i = 1;
	while (load_unit->isAlive())
	{
		do {
			system("cls");
			cout << "Enemy pick you champion: " << endl;
			cout << "1.Warrior " << endl;
			cout << "2.Wizard" << endl;
			cout << "Enter: ";
			cin >> choose;
		} while (choose != 1 && choose != 2);
		if (choose == 1)
			unit2 = new Bot_Warrior();
		else unit2 = new Bot_Wizard();


		while (load_unit->isAlive() && unit2->isAlive())
		{
			cout << "~~~~~~~~~ Round" << i++ << "~~~~~~~~~`" << endl;
			load_unit->attack(unit2);
			unit2->attack(load_unit);
			cout << endl;
			load_unit->show_hp();
			unit2->show_hp();
			cout << endl;
			int a = _getch();
		}
		if (load_unit->isAlive())
			cout << load_unit->getName() << " won!" << endl;
		else if (unit2->isAlive())
			cout << unit2->getName() << " won!" << endl;
		else
			cout << "Draw" << endl;
		int a = _getch();
		do
		{
			system("cls");
			cout << "1.Next enemy " << endl;
			cout << "2.Save game" << endl;
			cout << "3.Exit" << endl;
			cout << "Enter: ";
			cin >> choose;
		} while (choose != 1 && choose != 2 && choose != 3);
		switch (choose)
		{
		case 1:
			break;
		case 2:
			saveUnitMenu(load_unit);
			break;
		case 3:
			load_unit->setHP(0);
			break;
		default:
			break;
		}
	}

	delete load_unit;
	delete unit2;

}

void saveGroupMenu(Group* save_group)
{
	system("cls");
	fstream save_game;
	string filename;
	cout << "Enter name of you save: ";
	cin >> filename;
	filename += ".txt";
	save_game.open(filename.c_str(), ios::out | ios::binary);
	if (!save_game.is_open())
		save_group->save(save_game);
	else cout << "File not found";
	save_game.close();
}

void loadGroupMenu()
{
	system("cls");
	fstream load_game;
	string filename;
	cout << "Enter name of you save: ";
	cin >> filename;
	filename += ".txt";
	load_game.open(filename.c_str(), ios::in | ios::binary);
	unique_ptr<Group> group(new Group);
	if (!load_game.is_open())
		group->load(load_game);
	else cout << "File not found";
	load_game.close();
}
