#include "complicationAproblems.h"
USING_NS_CC;
complicationAproblems::complicationAproblems()
{
	m_plainDecide = 8;
	indicatesWilrefer = cocos2d::Vec2(50, 50);
	m_declarationsReflectIntent = 3;
	periodAddedFall = false;
	m_resourcesEquality = 100;
	allocateConsists = 10;
}
complicationAproblems *complicationAproblems::create(const std::string&m_unwindingOnalthough,std::string actorflag)
{
    complicationAproblems *pRet = new complicationAproblems();
    if (pRet && pRet->initWithFile(m_unwindingOnalthough, actorflag))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
}
complicationAproblems::~complicationAproblems(void)
{
	stopAllActions();
}
void complicationAproblems::bitsManyUnlike(float times,soonAlongMemberwise action,accessedIntroductory dir,int loop,float ltimes)
{
	if (getTypeId() == MAGIC_WEAPON_TYPE) 
	{
		incrementallyComplicated(times, action, dir, loop, ltimes);
		return;
	}
	if (periodAddedFall)
		return;
	if (action != soonAlongMemberwise::stand && action != soonAlongMemberwise::ACTION_NONE)
	{
		stopActionByTag(TagType::majorDestructorSequential1ion);
	}
	else
	{
		majorDestructorSequential1();
	}
	addingRelies::bitsManyUnlike(times, action, dir, loop, ltimes);
}
void complicationAproblems::incrementallyComplicated(float times,soonAlongMemberwise action,accessedIntroductory dir,int loop,float ltimes)
{
	stopActionByTag(TagType::majorDestructorSequential1ion);
	main_node->stopActionByTag(TagType::resertAction);
	main_node->stopActionByTag(TagType::autoAction);
	if (action == soonAlongMemberwise::stand || action == soonAlongMemberwise::ACTION_NONE)
	{
		nextAddsDiskReject();
	}
	if (action != soonAlongMemberwise::stand)
		action = soonAlongMemberwise::ACTION_NONE;
	dir = accessedIntroductory::dir_up;
	addingRelies::bitsManyUnlike(times, action, dir, loop, ltimes);
}
void complicationAproblems::settestCallableSpecifiers1(cocos2d::Vec2 pos, float autoTime, float stepTime, float restTime, float farL)
{
	indicatesWilrefer = pos;
	m_plainDecide = autoTime;
	m_declarationsReflectIntent = stepTime;
	allocateConsists = restTime;
	m_resourcesEquality = farL;
}
void complicationAproblems::standed()
{
	if(m_incrementallyPostfix&&cerrResultsThroughCeases(ACTION_STATE_IDLE))
	{
	
		stopActionByTag(ACTION_MOVE_TAG);
		stopActionByTag(ACTION_FLY01_TAG);
		stopActionByTag(ACTION_FLY02_TAG);
		stopActionByTag(ACTION_ATTACK_TAG);
		stopActionByTag(ACTION_SUDDEN_TAG);
		stopActionByTag(ACTION_SHADOW_TAG);
		bitsManyUnlike(m_coutIdentical,stand,m_interchangeablyNamespaces.dir,0);
	}
}
void complicationAproblems::majorDestructorSequential1()
{
	stopActionByTag(TagType::majorDestructorSequential1ion);
	FiniteTimeAction* actbackfun = CallFunc::create([&](){
		if (getTypeId() == MAGIC_WEAPON_TYPE)
		{
			this->thenUnusualFairly();
			return;
		}
	
		this->thenUnusualFairly();
	});
	Action* act = Sequence::create(DelayTime::create(m_plainDecide), actbackfun, NULL);
	act->setTag(TagType::majorDestructorSequential1ion);
	runAction(act);
}
void complicationAproblems::thenUnusualFairly()
{
	if (getTypeId() == MAGIC_WEAPON_TYPE)
	{
		whichReplacesSections();
		return;
	}
	getrepresentExpands()->stopAllActions();
	periodAddedFall = true;
	FiniteTimeAction* func1 = CallFunc::create([&](){ addingRelies::bitsManyUnlike(-1, soonAlongMemberwise::run, accessedIntroductory::dir_right_up, -1); });
	FiniteTimeAction* func2 = CallFunc::create([&](){ getrepresentExpands()->runAction(MoveBy::create(m_declarationsReflectIntent, cocos2d::Vec2(indicatesWilrefer.x, indicatesWilrefer.y))); });
	FiniteTimeAction* func3 = CallFunc::create([&](){ addingRelies::bitsManyUnlike(-1, soonAlongMemberwise::run, accessedIntroductory::dir_right_down, -1); });
	FiniteTimeAction* func4 = CallFunc::create([&](){ getrepresentExpands()->runAction(MoveBy::create(m_declarationsReflectIntent, cocos2d::Vec2(indicatesWilrefer.x, -indicatesWilrefer.y))); });
	FiniteTimeAction* func2_1 = CallFunc::create([&](){ addingRelies::bitsManyUnlike(-1, soonAlongMemberwise::run, accessedIntroductory::dir_left_down, -1); });
	FiniteTimeAction* func2_2 = CallFunc::create([&](){ getrepresentExpands()->runAction(MoveBy::create(m_declarationsReflectIntent, cocos2d::Vec2(-indicatesWilrefer.x, -indicatesWilrefer.y))); });
	FiniteTimeAction* func2_3 = CallFunc::create([&](){ addingRelies::bitsManyUnlike(-1, soonAlongMemberwise::run, accessedIntroductory::dir_left_up, -1); });
	FiniteTimeAction* func2_4 = CallFunc::create([&](){ getrepresentExpands()->runAction(MoveBy::create(m_declarationsReflectIntent, cocos2d::Vec2(-indicatesWilrefer.x, indicatesWilrefer.y))); });
	FiniteTimeAction* endFunc = CallFunc::create([&](){ periodAddedFall = false; bitsManyUnlike(-1, soonAlongMemberwise::stand, accessedIntroductory::dir_left_down, -1);});
	Action* action = Sequence::create(func1, func2, DelayTime::create(m_declarationsReflectIntent+0.1f),\
									  func3, func4, DelayTime::create(m_declarationsReflectIntent+0.1f),\
		                              func2_1, func2_2, DelayTime::create(m_declarationsReflectIntent+0.1f),\
									  func2_3, func2_4 ,DelayTime::create(m_declarationsReflectIntent+0.1f),\
									  endFunc, NULL);
	action->setTag(TagType::autoAction);
	runAction(action);
}
void complicationAproblems::whichReplacesSections()
{
	main_node->stopAllActions();
	FiniteTimeAction* endFunc = CallFunc::create([&](){ this->majorDestructorSequential1();});
	Action* action = Sequence::create(MoveBy::create(m_declarationsReflectIntent, Vec2(-indicatesWilrefer.x, indicatesWilrefer.y)), DelayTime::create(0.1f),\
									  MoveBy::create(m_declarationsReflectIntent, Vec2(-indicatesWilrefer.x, -indicatesWilrefer.y)), DelayTime::create(0.1f),\
									  MoveBy::create(m_declarationsReflectIntent, Vec2(indicatesWilrefer.x, -indicatesWilrefer.y)), DelayTime::create(0.1f),\
								      MoveBy::create(m_declarationsReflectIntent, Vec2(indicatesWilrefer.x, indicatesWilrefer.y)), DelayTime::create(0.1f),\
								      endFunc, NULL);
	action->setTag(TagType::autoAction);
	main_node->runAction(action);
}
void complicationAproblems::setreviseStringWhen(cocos2d::Point pos)
{
	m_preservingGreater.x = pos.x;
	m_preservingGreater.y = pos.y;
	if (getTypeId() != MAGIC_WEAPON_TYPE)
	{
		addingRelies::setreviseStringWhen(pos);
	}
	else
	{
		main_node->setPosition(pos.x, pos.y);
	}
}
void complicationAproblems::setPosition(float x, float y)
{
	main_node->stopActionByTag(TagType::resertAction);
	Vec2 curPos = main_node->getPosition();
	Vec2 rootPos = getPosition();
	Vec2 newCurPos = Vec2(curPos.x - (x - rootPos.x), curPos.y - (y - rootPos.y));
	Vec2 zeroPoint = Vec2::ZERO;
	float oldDistance = zeroPoint.distance(curPos);
	float newDis = zeroPoint.distance(newCurPos);
	if (newDis <= m_resourcesEquality && getTypeId() == MAGIC_WEAPON_TYPE && rootPos != Vec2::ZERO)
	{
		main_node->setPosition(newCurPos.x, newCurPos.y);
	}
	addingRelies::setPosition(x, y);
}
void complicationAproblems::nextAddsDiskReject()
{
	main_node->stopActionByTag(TagType::resertAction);
	Vec2 pos = m_preservingGreater;
	float dis = pos.distance(main_node->getPosition());
	float times = dis / m_resourcesEquality * allocateConsists;
	FiniteTimeAction* endFunc = CallFunc::create([&](){ this->majorDestructorSequential1(); });
	Action* action = Sequence::create(MoveTo::create(times, m_preservingGreater), endFunc ,NULL);
	action->setTag(TagType::resertAction);
	main_node->runAction(action);
}