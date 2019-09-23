#include "mubeParametethat.h"
#include "selectDeterminesSomewhere.h"
USING_NS_CC;
mubeParametethat::mubeParametethat()
{
	m_showsPreserving = 8;
	m_appearGivePointers = cocos2d::Vec2(50, 50);
	manualChecksTilde = 3;
	m_unchangedUser = false;
	m_stunninglyPairwise = 100;
	m_wilreferTwinCannot = 10;
}
mubeParametethat *mubeParametethat::create(const std::string&m_ableCover,std::string actorflag)
{
    mubeParametethat *pRet = new mubeParametethat();
    if (pRet && pRet->initWithFile(m_ableCover, actorflag))
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
mubeParametethat::~mubeParametethat(void)
{
	stopAllActions();
}
void mubeParametethat::gradingLatestRedeclare(float times,stringsLargeEspecially action,auxiliaryEssential dir,int loop,float ltimes)
{
	if (getTypeId() == MAGIC_WEAPON_TYPE) 
	{
		fifthCalculatePast(times, action, dir, loop, ltimes);
		return;
	}
	if (m_unchangedUser)
		return;
	if (action != stringsLargeEspecially::stand && action != stringsLargeEspecially::ACTION_NONE)
	{
		stopActionByTag(TagType::generateRolesJumpingion);
	}
	else
	{
		generateRolesJumping();
	}
	copiedFlipsActual::gradingLatestRedeclare(times, action, dir, loop, ltimes);
}
void mubeParametethat::fifthCalculatePast(float times,stringsLargeEspecially action,auxiliaryEssential dir,int loop,float ltimes)
{
	stopActionByTag(TagType::generateRolesJumpingion);
	main_node->stopActionByTag(TagType::resertAction);
	main_node->stopActionByTag(TagType::autoAction);
	if (action == stringsLargeEspecially::stand || action == stringsLargeEspecially::ACTION_NONE)
	{
		prefixedCoupledSignature();
	}
	if (action != stringsLargeEspecially::stand)
		action = stringsLargeEspecially::ACTION_NONE;
	dir = auxiliaryEssential::dir_up;
	copiedFlipsActual::gradingLatestRedeclare(times, action, dir, loop, ltimes);
}
void mubeParametethat::setaggregateQuizMaking(cocos2d::Vec2 pos, float autoTime, float stepTime, float restTime, float farL)
{
	m_appearGivePointers = pos;
	m_showsPreserving = autoTime;
	manualChecksTilde = stepTime;
	m_wilreferTwinCannot = restTime;
	m_stunninglyPairwise = farL;
}
void mubeParametethat::standed()
{
	selectDeterminesSomewhere selectdeterminessomewhere_e;
	selectdeterminessomewhere_e.correspondFindsSpecifiers(373,398,nullptr);

	if(everyFunctionfunction&&instancesSomewhat(ACTION_STATE_IDLE))
	{
	
		stopActionByTag(ACTION_MOVE_TAG);
		stopActionByTag(ACTION_FLY01_TAG);
		stopActionByTag(ACTION_FLY02_TAG);
		stopActionByTag(ACTION_ATTACK_TAG);
		stopActionByTag(ACTION_SUDDEN_TAG);
		stopActionByTag(ACTION_SHADOW_TAG);
		gradingLatestRedeclare(m_couldMismatched,stand,wholeSpecialObjectsth.dir,0);
	}
}
void mubeParametethat::generateRolesJumping()
{
	stopActionByTag(TagType::generateRolesJumpingion);
	FiniteTimeAction* actbackfun = CallFunc::create([&](){
		if (getTypeId() == MAGIC_WEAPON_TYPE)
		{
			this->solutionUnlessVariable();
			return;
		}
	
		this->solutionUnlessVariable();
	});
	Action* act = Sequence::create(DelayTime::create(m_showsPreserving), actbackfun, NULL);
	act->setTag(TagType::generateRolesJumpingion);
	runAction(act);
}
void mubeParametethat::solutionUnlessVariable()
{
	if (getTypeId() == MAGIC_WEAPON_TYPE)
	{
		eachCabeAutomatically();
		return;
	}
	getlistedUndefinedparameters()->stopAllActions();
	m_unchangedUser = true;
	FiniteTimeAction* func1 = CallFunc::create([&](){ copiedFlipsActual::gradingLatestRedeclare(-1, stringsLargeEspecially::run, auxiliaryEssential::dir_right_up, -1); });
	FiniteTimeAction* func2 = CallFunc::create([&](){ getlistedUndefinedparameters()->runAction(MoveBy::create(manualChecksTilde, cocos2d::Vec2(m_appearGivePointers.x, m_appearGivePointers.y))); });
	FiniteTimeAction* func3 = CallFunc::create([&](){ copiedFlipsActual::gradingLatestRedeclare(-1, stringsLargeEspecially::run, auxiliaryEssential::dir_right_down, -1); });
	FiniteTimeAction* func4 = CallFunc::create([&](){ getlistedUndefinedparameters()->runAction(MoveBy::create(manualChecksTilde, cocos2d::Vec2(m_appearGivePointers.x, -m_appearGivePointers.y))); });
	FiniteTimeAction* func2_1 = CallFunc::create([&](){ copiedFlipsActual::gradingLatestRedeclare(-1, stringsLargeEspecially::run, auxiliaryEssential::dir_left_down, -1); });
	FiniteTimeAction* func2_2 = CallFunc::create([&](){ getlistedUndefinedparameters()->runAction(MoveBy::create(manualChecksTilde, cocos2d::Vec2(-m_appearGivePointers.x, -m_appearGivePointers.y))); });
	FiniteTimeAction* func2_3 = CallFunc::create([&](){ copiedFlipsActual::gradingLatestRedeclare(-1, stringsLargeEspecially::run, auxiliaryEssential::dir_left_up, -1); });
	FiniteTimeAction* func2_4 = CallFunc::create([&](){ getlistedUndefinedparameters()->runAction(MoveBy::create(manualChecksTilde, cocos2d::Vec2(-m_appearGivePointers.x, m_appearGivePointers.y))); });
	FiniteTimeAction* endFunc = CallFunc::create([&](){ m_unchangedUser = false; gradingLatestRedeclare(-1, stringsLargeEspecially::stand, auxiliaryEssential::dir_left_down, -1);});
	Action* action = Sequence::create(func1, func2, DelayTime::create(manualChecksTilde+0.1f),\
									  func3, func4, DelayTime::create(manualChecksTilde+0.1f),\
		                              func2_1, func2_2, DelayTime::create(manualChecksTilde+0.1f),\
									  func2_3, func2_4 ,DelayTime::create(manualChecksTilde+0.1f),\
									  endFunc, NULL);
	action->setTag(TagType::autoAction);
	runAction(action);
}
void mubeParametethat::eachCabeAutomatically()
{
	main_node->stopAllActions();
	FiniteTimeAction* endFunc = CallFunc::create([&](){ this->generateRolesJumping();});
	Action* action = Sequence::create(MoveBy::create(manualChecksTilde, Vec2(-m_appearGivePointers.x, m_appearGivePointers.y)), DelayTime::create(0.1f),\
									  MoveBy::create(manualChecksTilde, Vec2(-m_appearGivePointers.x, -m_appearGivePointers.y)), DelayTime::create(0.1f),\
									  MoveBy::create(manualChecksTilde, Vec2(m_appearGivePointers.x, -m_appearGivePointers.y)), DelayTime::create(0.1f),\
								      MoveBy::create(manualChecksTilde, Vec2(m_appearGivePointers.x, m_appearGivePointers.y)), DelayTime::create(0.1f),\
								      endFunc, NULL);
	action->setTag(TagType::autoAction);
	main_node->runAction(action);
}
void mubeParametethat::setstartingBasicsNamespaces(cocos2d::Point pos)
{
	m_convertingSequenceProvide.x = pos.x;
	m_convertingSequenceProvide.y = pos.y;
	if (getTypeId() != MAGIC_WEAPON_TYPE)
	{
		copiedFlipsActual::setstartingBasicsNamespaces(pos);
	}
	else
	{
		main_node->setPosition(pos.x, pos.y);
	}
}
void mubeParametethat::setPosition(float x, float y)
{
	main_node->stopActionByTag(TagType::resertAction);
	Vec2 curPos = main_node->getPosition();
	Vec2 rootPos = getPosition();
	Vec2 newCurPos = Vec2(curPos.x - (x - rootPos.x), curPos.y - (y - rootPos.y));
	Vec2 zeroPoint = Vec2::ZERO;
	float oldDistance = zeroPoint.distance(curPos);
	float newDis = zeroPoint.distance(newCurPos);
	if (newDis <= m_stunninglyPairwise && getTypeId() == MAGIC_WEAPON_TYPE && rootPos != Vec2::ZERO)
	{
		main_node->setPosition(newCurPos.x, newCurPos.y);
	}
	copiedFlipsActual::setPosition(x, y);
}
void mubeParametethat::prefixedCoupledSignature()
{
	main_node->stopActionByTag(TagType::resertAction);
	Vec2 pos = m_convertingSequenceProvide;
	float dis = pos.distance(main_node->getPosition());
	float times = dis / m_stunninglyPairwise * m_wilreferTwinCannot;
	FiniteTimeAction* endFunc = CallFunc::create([&](){ this->generateRolesJumping(); });
	Action* action = Sequence::create(MoveTo::create(times, m_convertingSequenceProvide), endFunc ,NULL);
	action->setTag(TagType::resertAction);
	main_node->runAction(action);
}