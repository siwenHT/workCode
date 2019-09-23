#include "SpriteGuard.h"

USING_NS_CC;

SpriteGuard::SpriteGuard()
{	
	m_autoTime = 8;
	m_moverPoint = cocos2d::Vec2(50, 50);
	m_stepTime = 3;
	m_isAutoMove = false;
	m_farLength = 100;
	m_restTime = 10;
}


SpriteGuard *SpriteGuard::create(const std::string&pszFileName,std::string actorflag)
{
    SpriteGuard *pRet = new SpriteGuard();
	
    if (pRet && pRet->initWithFile(pszFileName, actorflag))
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

SpriteGuard::~SpriteGuard(void)
{
	stopAllActions();
}

void SpriteGuard::playAction(float times,Commen_ActionToDo action,Commen_Direction dir,int loop,float ltimes)
{
	if (getTypeId() == MAGIC_WEAPON_TYPE) 
	{
		playAction_ex(times, action, dir, loop, ltimes);
		return;
	}

	//守护自转逻辑
	if (m_isAutoMove)
		return;

	if (action != Commen_ActionToDo::stand && action != Commen_ActionToDo::ACTION_NONE)
	{
		stopActionByTag(TagType::beginAutoAction);
	}
	else
	{
		beginAutoAct();
	}

	SpriteBase::playAction(times, action, dir, loop, ltimes);
}

void SpriteGuard::playAction_ex(float times,Commen_ActionToDo action,Commen_Direction dir,int loop,float ltimes)
{
	stopActionByTag(TagType::beginAutoAction);
	main_node->stopActionByTag(TagType::resertAction);
	main_node->stopActionByTag(TagType::autoAction);

	//法宝转动逻辑
	if (action == Commen_ActionToDo::stand || action == Commen_ActionToDo::ACTION_NONE)
	{
		resetSpriteAct();
	}

	if (action != Commen_ActionToDo::stand)
		action = Commen_ActionToDo::ACTION_NONE;
	dir = Commen_Direction::dir_up;
	SpriteBase::playAction(times, action, dir, loop, ltimes);
}

void SpriteGuard::setAutoInfo(cocos2d::Vec2 pos, float autoTime, float stepTime, float restTime, float farL)
{
	m_moverPoint = pos;
	m_autoTime = autoTime;
	m_stepTime = stepTime;
	m_restTime = restTime;
	m_farLength = farL;
}

void SpriteGuard::standed()
{
	if(stand_inited&&changeState(ACTION_STATE_IDLE))
	{
		//stopAllActions();
		stopActionByTag(ACTION_MOVE_TAG);
		stopActionByTag(ACTION_FLY01_TAG);
		stopActionByTag(ACTION_FLY02_TAG);
		stopActionByTag(ACTION_ATTACK_TAG);
		stopActionByTag(ACTION_SUDDEN_TAG);
		stopActionByTag(ACTION_SHADOW_TAG);
		playAction(m_stand_times,stand,m_roledata.dir,0);
	}
}

void SpriteGuard::beginAutoAct()
{
	stopActionByTag(TagType::beginAutoAction);
	FiniteTimeAction* actbackfun = CallFunc::create([&](){
		if (getTypeId() == MAGIC_WEAPON_TYPE)
		{
			this->autoMoveShow();
			return;
		}
		
		this->autoMoveShow();
	});
	Action* act = Sequence::create(DelayTime::create(m_autoTime), actbackfun, NULL);
	act->setTag(TagType::beginAutoAction);
	runAction(act);
}

void SpriteGuard::autoMoveShow()
{
	if (getTypeId() == MAGIC_WEAPON_TYPE)
	{
		autoMoveShow_ex();
		return;
	}
	getMainSprite()->stopAllActions();
	//CCLOG("main_node pos", main_node->getPositionX(), main_node->getPositionY());

	//自己移动
	m_isAutoMove = true;
	FiniteTimeAction* func1 = CallFunc::create([&](){ SpriteBase::playAction(-1, Commen_ActionToDo::run, Commen_Direction::dir_right_up, -1); });
	//FiniteTimeAction* func2 = CallFunc::create([&](){ CCLOG("sprpos_%f_%f_1", getMainSprite()->getPosition().x, getMainSprite()->getPosition().y);getMainSprite()->runAction(MoveBy::create(m_stepTime, cocos2d::Vec2(m_moverPoint.x, m_moverPoint.y))); });
	FiniteTimeAction* func2 = CallFunc::create([&](){ getMainSprite()->runAction(MoveBy::create(m_stepTime, cocos2d::Vec2(m_moverPoint.x, m_moverPoint.y))); });

	FiniteTimeAction* func3 = CallFunc::create([&](){ SpriteBase::playAction(-1, Commen_ActionToDo::run, Commen_Direction::dir_right_down, -1); });
	//FiniteTimeAction* func4 = CallFunc::create([&](){ CCLOG("sprpos_%f_%f_2", getMainSprite()->getPosition().x, getMainSprite()->getPosition().y); getMainSprite()->runAction(MoveBy::create(m_stepTime, cocos2d::Vec2(m_moverPoint.x, -m_moverPoint.y))); });
	FiniteTimeAction* func4 = CallFunc::create([&](){ getMainSprite()->runAction(MoveBy::create(m_stepTime, cocos2d::Vec2(m_moverPoint.x, -m_moverPoint.y))); });

	FiniteTimeAction* func2_1 = CallFunc::create([&](){ SpriteBase::playAction(-1, Commen_ActionToDo::run, Commen_Direction::dir_left_down, -1); });
	//FiniteTimeAction* func2_2 = CallFunc::create([&](){ CCLOG("sprpos_%f_%f_3", getMainSprite()->getPosition().x, getMainSprite()->getPosition().y);getMainSprite()->runAction(MoveBy::create(m_stepTime, cocos2d::Vec2(-m_moverPoint.x, -m_moverPoint.y))); });
	FiniteTimeAction* func2_2 = CallFunc::create([&](){ getMainSprite()->runAction(MoveBy::create(m_stepTime, cocos2d::Vec2(-m_moverPoint.x, -m_moverPoint.y))); });

	FiniteTimeAction* func2_3 = CallFunc::create([&](){ SpriteBase::playAction(-1, Commen_ActionToDo::run, Commen_Direction::dir_left_up, -1); });
	//FiniteTimeAction* func2_4 = CallFunc::create([&](){ CCLOG("sprpos_%f_%f_4", getMainSprite()->getPosition().x, getMainSprite()->getPosition().y);getMainSprite()->runAction(MoveBy::create(m_stepTime, cocos2d::Vec2(-m_moverPoint.x, m_moverPoint.y))); });
	FiniteTimeAction* func2_4 = CallFunc::create([&](){ getMainSprite()->runAction(MoveBy::create(m_stepTime, cocos2d::Vec2(-m_moverPoint.x, m_moverPoint.y))); });

	//getMainSprite()->setPosition(oldPos); 
	FiniteTimeAction* endFunc = CallFunc::create([&](){ m_isAutoMove = false; playAction(-1, Commen_ActionToDo::stand, Commen_Direction::dir_left_down, -1);});

	Action* action = Sequence::create(func1, func2, DelayTime::create(m_stepTime+0.1f),\
									  func3, func4, DelayTime::create(m_stepTime+0.1f),\
		                              func2_1, func2_2, DelayTime::create(m_stepTime+0.1f),\
									  func2_3, func2_4 ,DelayTime::create(m_stepTime+0.1f),\
									  endFunc, NULL);
	action->setTag(TagType::autoAction);
	runAction(action);
}

void SpriteGuard::autoMoveShow_ex()
{
	main_node->stopAllActions();


	FiniteTimeAction* endFunc = CallFunc::create([&](){ this->beginAutoAct();});
	Action* action = Sequence::create(MoveBy::create(m_stepTime, Vec2(-m_moverPoint.x, m_moverPoint.y)), DelayTime::create(0.1f),\
									  MoveBy::create(m_stepTime, Vec2(-m_moverPoint.x, -m_moverPoint.y)), DelayTime::create(0.1f),\
									  MoveBy::create(m_stepTime, Vec2(m_moverPoint.x, -m_moverPoint.y)), DelayTime::create(0.1f),\
								      MoveBy::create(m_stepTime, Vec2(m_moverPoint.x, m_moverPoint.y)), DelayTime::create(0.1f),\
								      endFunc, NULL);
	action->setTag(TagType::autoAction);
	main_node->runAction(action);
}

//考虑把偏移弄到 mainNode
void SpriteGuard::setBasePosition(cocos2d::Point pos)
{
	m_offsetPos.x = pos.x;
	m_offsetPos.y = pos.y;

	if (getTypeId() != MAGIC_WEAPON_TYPE)
	{
		SpriteBase::setBasePosition(pos);
	}
	else
	{
		main_node->setPosition(pos.x, pos.y);
	}
}

//法宝设置位置的时候, 需要保持自身位置不动
void SpriteGuard::setPosition(float x, float y)
{
	main_node->stopActionByTag(TagType::resertAction);

	Vec2 curPos = main_node->getPosition();
	Vec2 rootPos = getPosition();
	Vec2 newCurPos = Vec2(curPos.x - (x - rootPos.x), curPos.y - (y - rootPos.y));

	Vec2 zeroPoint = Vec2::ZERO;
	float oldDistance = zeroPoint.distance(curPos);
	float newDis = zeroPoint.distance(newCurPos);

	//没有达到最远跟随距离
	if (newDis <= m_farLength && getTypeId() == MAGIC_WEAPON_TYPE && rootPos != Vec2::ZERO)
	{
		main_node->setPosition(newCurPos.x, newCurPos.y);
	}
	
	SpriteBase::setPosition(x, y);
}

//停止移动的时候, 先移动到起始点, 隔固定时间开始反着转起来
void SpriteGuard::resetSpriteAct()
{
	main_node->stopActionByTag(TagType::resertAction);
	Vec2 pos = m_offsetPos;
	float dis = pos.distance(main_node->getPosition());
	float times = dis / m_farLength * m_restTime;
	FiniteTimeAction* endFunc = CallFunc::create([&](){ this->beginAutoAct(); });
	Action* action = Sequence::create(MoveTo::create(times, m_offsetPos), endFunc ,NULL);
	action->setTag(TagType::resertAction);
	main_node->runAction(action);
}