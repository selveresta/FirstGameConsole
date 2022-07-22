#include "Menu.h"

int main() {
	srand(time(0));
	cout << "1.Play solo\n";
	cout << "2.Play group\n";
	cout << "3.Load hero\n";
	cout << "4.Load group\n";
	cout << "5.Exit\n";
	int choose_game;
	cout << "Enter: ";
	cin >> choose_game;
	system("cls");
	switch (choose_game)
	{
	case 1:
		Play_solo();
		break;
	case 2:
		Play_group();
		break;
	case 3:
		loadUnitMenu();
		break;
	case 4:
		loadUnitMenu();
		break;
	case 5:
		loadGroupMenu();
		break;
	}
}