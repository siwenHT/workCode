﻿#ifndef _MAIN_ROLE_DATA_
#define _MAIN_ROLE_DATA_
#include "cocos2d.h"
#include "Commen_ActionToDo.h"
#include "Commen_Direction.h"
class MainRoledata
{
public :
	cocos2d::Point nowpoint;
	std::string spiritUrl;
	std::string repSpritUrl;
	bool isRepMode;
	int maxcut_stand;
	int maxcut_run;
	int maxcut_attack;
	int maxcut_hurt;
	int maxcut_death;
	int maxcut_magic;
	int maxcut_fly01;
	int maxcut_fly02;
	int maxcut_fly03;
	int maxcut_hurt_idle;
	int maxcut_hurt_kneel;
	int maxcut_attack_03;
	int maxcut_attack_04;
	int maxcut_ride_stand;
	int maxcut_ride_run;
	int maxcut_attackmode_01;
	int maxcut_attackmode_02;
	int maxcut_attackmode_03;
	int maxcut_attackmode_04;
	int maxcut_attackmode_05;
	int maxcut_attackmode_06;
	int maxcut_attackmode_07;
	int maxcut_attackmode_08;
	int maxcut_attackmode_09;
	int maxcut_attackmode_10;
	int maxcut_attackmode_11;
	int maxcut_attackmode_12;
	int maxcut_weaponeff_01;
	int maxcut_weaponeff_02;
	int maxcut_weaponeff_03;
	int maxcut_weaponeff_04;
	int maxcut_weaponeff_05;
	int maxcut_weaponeff_06;
	int maxcut_weaponeff_07;
	int maxcut_weaponeff_08;
	int maxcut_weaponeff_09;
	int maxcut_weaponeff_10;
	int maxcut_weaponeff_11;
	int maxcut_weaponeff_12;
	Commen_ActionToDo acttodo;
	Commen_Direction dir;
	int maxcut;
	float actiontime;
	std::string animKey;
};
#endif
