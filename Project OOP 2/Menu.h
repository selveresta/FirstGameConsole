#pragma once
#include "Warrior.h"
#include "Wizard.h"

#include "Bot_Warrior.h"
#include "Bot_Wizard.h"


#include "Group.h"

void Play_solo();
void Play_group();
void saveUnitMenu(Unit* save_unit);
void loadUnitMenu();

void saveGroupMenu(Group* save_group);
void loadGroupMenu();
