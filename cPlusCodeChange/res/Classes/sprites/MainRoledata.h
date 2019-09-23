#ifndef _MAIN_ROLE_DATA_
#define _MAIN_ROLE_DATA_

#include "cocos2d.h"
#include "Commen_ActionToDo.h"
#include "Commen_Direction.h"





class MainRoledata
{
public :
	//人物初始坐标
	cocos2d::Point nowpoint;
	//人物默认像素图
	std::string spiritUrl;

	//替换模型资源id
	std::string repSpritUrl;
	//是否替换显示模型中
	bool isRepMode;

	//人物站立最大帧
	int maxcut_stand;
	//人物跑动最大帧
	int maxcut_run;
	//人物战斗最大帧
	int maxcut_attack;
	//人物伤害最大帧
	int maxcut_hurt;
	int maxcut_death;
	//人物施法最大帧
	int maxcut_magic;
	//轻功动作最大帧  轻功动作现在定为三种
	int maxcut_fly01;
	int maxcut_fly02;
	int maxcut_fly03;
	//受伤动作最大帧
	int maxcut_hurt_idle;
	//受伤跪地动作最大帧
	int maxcut_hurt_kneel;
	//突进技能前半段动作帧数
	int maxcut_attack_03;
	//突进技能后半段动作帧数
	int maxcut_attack_04;
	//坐骑动作
	int maxcut_ride_stand;
	int maxcut_ride_run;
	//人物攻击几个模式动作
	int maxcut_attackmode_01;
	int maxcut_attackmode_02;
	int maxcut_attackmode_03;
	int maxcut_attackmode_04;
	// 人物连序攻击动作
	int maxcut_attackmode_05;
	int maxcut_attackmode_06;
	int maxcut_attackmode_07;
	int maxcut_attackmode_08;

	int maxcut_attackmode_09;
	int maxcut_attackmode_10;
	int maxcut_attackmode_11;
	int maxcut_attackmode_12;

	//人物攻击刀光帧数
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

	//人物当前动作
	Commen_ActionToDo acttodo;
	//人物当前朝向
	Commen_Direction dir;
	//人物当前动作帧数
	int maxcut;
	//动画时间
	float actiontime;
	//当前播放动画key
	std::string animKey;
};

#endif
