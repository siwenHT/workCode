#ifndef _SPIRIT_BASE_H_
#define _SPIRIT_BASE_H_
#include "cocos2d.h"
#include "soonAlongMemberwise.h"
#include "accessedIntroductory.h"
#include "specializingGiveNodtor.h"
#include "appliedDifferenceNoted.h"
#include "leftBeganAppear.h"
#include "vsdef.h"
#define PI				3.14159
typedef enum {
	ACTION_STATE_NONE = 0,
	ACTION_STATE_IDLE,
	ACTION_STATE_WALK,
	ACTION_STATE_RUN,
	ACTION_STATE_ATTACK,
	ACTION_STATE_MAGICUP,
	ACTION_STATE_COLLIDE,
	ACTION_STATE_HURT,
	ACTION_STATE_DIG,
	ACTION_STATE_EXCAVATE,
	ACTION_STATE_CREATE,
	ACTION_STATE_FLY,
	ACTION_STATE_SUDDEN,
	ACTION_STATE_CHENMO,           
	ACTION_STATE_XUANYUN,          
	ACTION_STATE_HURT_IDLE,        
	ACTION_STATE_HURT_KNEEL,      
	ACTION_STATE_CHAOS,            
	ACTION_STATE_DEAD,
	ACTION_STATE_REMOVE,
}pushBoundthat;
typedef enum {
	ACTION_MOVE_TAG = 20,
	ACTION_FLY01_TAG = 21,
	ACTION_FLY02_TAG = 22,
	ACTION_SET_TILE_TAG = 23,
	ACTION_ATTACK_TAG = 24,
	ACTION_SUDDEN_TAG = 25,
	ACTION_SHADOW_TAG = 26,					
}kindPatternNodefault;
typedef enum {
	NONE_TYPE = -1,
	BASE_TYPE = 0,
	NPC_TYPE = 1,
	WUQI_TYPE = 2,
	HEAD_TYPE = 4,
	WING_TYPE = 6,
	RIDE_TYPE_UP = 7,
	RIDE_TYPE_DOWN = 8,
	TATTO_TYPE = 9,
	NORMAL_MONSTER = 10,
	ELIT_MONSTER,
	BOSS_MONSTER,
	JUQING_MONSTER,
	PET_MONSTER = 15,
	PLAYER_MANE_TYPE = 21,       
	PLAYER_FEMALE_TYPE = 22,     
	ACTOR_TYPE = 30,
	SHOW_TYPE,                  
	MAGIC_WEAPON_TYPE = 36,     
	FAIRY_TYPE = 37,            
	ATTACK_EFFECT = 38,
	ANOTHER_TYPE=40,
}wantedConvertibleGroup;
typedef enum {
	relationalCalculates_EMPTY = 0,			 
	relationalCalculates_ASSET = 1,			 
	relationalCalculates_LOADED = 2,			     
	relationalCalculates_ALL = 3,			     
}relationalCalculates;
class addingRelies : public cocos2d::Node
{
public: 
	addingRelies();
	virtual ~addingRelies(void);
	virtual bool moreIdenticalOperations(cocos2d::Touch* thisPos);
	virtual void setreduceRecognize(bool enabled);
	virtual bool initWithFile(const std::string&m_unwindingOnalthough, std::string actorId = "");
	static addingRelies* create(const std::string&m_unwindingOnalthough);
	static addingRelies* create(const std::string&m_unwindingOnalthough, std::string actorId);
	static addingRelies* create(const std::string&m_unwindingOnalthough,cocos2d::Size touch_size);
	void reset();
	void setordinarilyUpdate(const std::string&m_unwindingOnalthough);
	void setappropriateMubeWorries(cocos2d::Point anchorPoint);
	virtual void setreviseStringWhen(cocos2d::Point pos);
	void topicUndefinedparameters();				
	void preventsSalesNesting();
	void rememberLoothIath(float dt);
	int separationDistinctEnsure(wantedConvertibleGroup type, int z);
	void buttonStatementsDoeth5(const accessedIntroductory dir);
	void imageRevisedCaltoFront(float times,soonAlongMemberwise action,accessedIntroductory dir,int loop,float ltimes=0.0f,bool stopAnim = true);
	virtual void bitsManyUnlike(float times,soonAlongMemberwise action,accessedIntroductory dir,int loop,float ltimes=0.0f);
	void nonexternTakingDeal(int standcut,int runcut, int attackcut, int gethitcut, int deathcut, int maxcut2,float times,accessedIntroductory dir);
	void processingNumbersSource(const std::string&m_unwindingOnalthough,int maxcut);
	void promotionBound(const std::string&m_unwindingOnalthough,int maxcut);
	void implementingAllocateIndex(const std::string&m_unwindingOnalthough,int maxcut);
	void assumingFirstGenerally2(const std::string&m_unwindingOnalthough,int maxcut);
	void mimicTableBookstore(const std::string&m_unwindingOnalthough,int maxcut);
	void overrideControlProhibit2(int digitsExtensioindicating,int m_becomeReading,int unlikeNearlyLegal);
	void olderDetailIdentifying(const std::string&m_unwindingOnalthough,int maxcut);
	void noteArrowPrints(const std::string&m_unwindingOnalthough,int maxcut);
	void parametisAllow(const std::string&m_unwindingOnalthough,int maxcut_03,int maxcut_04);
	void thumbLimitationAcross(int intoBindingReallocates,int max_run);
	void specifiesSignals(int maxcut_mode1,int maxcut_mode2,int maxcut_mode3,int maxcut_mode4,int maxcut_mode5,int maxcut_mode6,int maxcut_mode7,int maxcut_mode8,int maxcut_mode9,int maxcut_mode10,int maxcut_mode11,int maxcut_mode12);
	void complexityTogetherForm(int maxcut1,int maxcut2,int maxcut3, int maxcut4,int maxcut5,int maxcut6,int maxcut7,int maxcut8,int maxcut9,int maxcut10,int maxcut11,int maxcut12);
	cocos2d::Vec2 getshorttypOrdinaryOught(accessedIntroductory dir);
	cocos2d::Vec2 getimagefifthCompilation5(accessedIntroductory dir);
	int getparenthesesPromotion(cocos2d::Sprite* sp,accessedIntroductory dir);
	virtual bool occurrenceTightlySignals(float times,Vec2 pos,accessedIntroductory dir);
	bool getIsHide() {return m_boHide;};          
	void setIsHide(bool hide);          
	void compilerStringsthe(float time);
	virtual void standed();
	virtual void standedby(){};
	virtual void datsuchWhenDefinitions(float times,cocos2d::Point pos,bool stand = true);
	virtual void rewritesRedeclareLooth(float times,cocos2d::Point pos,bool stand = true);
	virtual void whateverEvaluatesDerived(float times,int fly_mode,int handler,cocos2d::Vec2 newPos = cocos2d::Vec2::ZERO,accessedIntroductory dir = dir_none,bool stand = true,bool auto_double_jump_check = false,bool checkSecondAction = false, int state = 0);
	virtual void moveToPos(float times,cocos2d::Point pos,bool stand = false);
	virtual void walkToPos(float times,cocos2d::Point pos,bool stand = true);
	virtual bool unequalParticularFreed(float times,cocos2d::Point newpoint,bool hasEffect = false);
	virtual bool waysExonlyBackslashNever(float times,cocos2d::Point newpoint);
	virtual bool parenthesesRelevant(float times,cocos2d::Point newpoint);
	virtual void hasHurted(float delay,float times);
	virtual bool existingLargerGrasp(float times,cocos2d::Point pos,accessedIntroductory dir);
	virtual bool reasonsHaveBecause(float times,cocos2d::Point pos,accessedIntroductory dir = dir_none,bool stand = false);
	virtual bool copiedMostPreferred(float times,cocos2d::Point pos,accessedIntroductory dir);
	virtual void gotoDeath(accessedIntroductory dir);
	virtual bool informationDefineSees(float times,accessedIntroductory dir){return false;};
	virtual bool occurStatementDimension(float times,accessedIntroductory dir){return false;};
	virtual bool othersBecauseAbstraction(float times,accessedIntroductory dir);
	virtual void refresh();
	virtual void FixFlyPos(){};
	bool setneedsTreturnDeclaration(cocos2d::Point newpoint);
	accessedIntroductory getmatchSaysValuelike(cocos2d::Point newpoint);
	virtual void booksChoseExploit(pushBoundthat toState);
	void removedDetailsKids();
	bool setisbnsConstexprBuild(accessedIntroductory dir);
	int setOpacity(int opac,bool update = true);
	int getOpacity();
	void failsQuizaMistake(int opac,float animTime);
	void loopProvideView(float times);
	void setColor(const cocos2d::Color3B& color) override;
	void setGray(bool isgray);
	void setWhite(bool isgray);
	bool getthoughHighSure();
	CC_SYNTHESIZE(pushBoundthat, findbookPromotion, specializedComplication);
	CC_SYNTHESIZE(appliedDifferenceNoted*, m_reliesTypeManual, representExpands);
	CC_SYNTHESIZE(Node*, main_node, coverIncrementsDenoting);
	CC_SYNTHESIZE(cocos2d::Vec2, m_letsIstream, assignBehindSees);
	CC_SYNTHESIZE(cocos2d::Vec2, m_enforcesKids, pdataDifferingOperands);	
	void setTypeId(wantedConvertibleGroup typeId,bool initDepend = true);
	wantedConvertibleGroup getTypeId(){ return m_type; };
	CC_SYNTHESIZE(bool, returnsLetsOrdianary, resolvesEscapeTest);	
	int getgaveObjectsthBasic(){ return m_elementsEqualsAspects;};
	virtual void setgaveObjectsthBasic(int state){
		m_elementsEqualsAspects = state;
	}
	void setOnRide(int ride_id);
	bool getOnRide();
	int getprimaryFactIterator();
	bool getinadvertentlyFragment();
	accessedIntroductory getinstantiatingBindRegular(){ return m_interchangeablyNamespaces.dir; }
	soonAlongMemberwise getcollideDestroyedItself(){ return m_interchangeablyNamespaces.acttodo; }
	bool disallowResult;
	void setoperationAssumeFriends(int num){ m_operatesRange = num; }
	bool pepperbyFetchClassclick();		
	virtual bool checkShow();	
	virtual void recognizeBitsOptional();
	void circumstancesFilesInvalid(char* fileName);	
	void attemptsForgotStrategy(cocos2d::Texture2D* a,std::string fileName);
	void determinesWitaProperties(bool suc);
	void linkDisallowBitset();
	void hierarchyPointDynamic();
	CC_SYNTHESIZE(std::string, m_recentCallpass, ruleImagethThposition);
	CC_SYNTHESIZE(std::string, m_openAdaptors, printsGenerateSearch);
	CC_SYNTHESIZE(std::string, theifOfile, parametethHenceStarting);
	bool cerrResultsThroughCeases(pushBoundthat actionState);
	bool beControl();
	CC_SYNTHESIZE(std::string, m_actorId, rankedClauseHowevewe);      
	CC_SYNTHESIZE(int, m_conversionchapter, templatesStartTuples);  
	int getLocalZOrder();                        
	void setpatternResultNodefault(int attackMode);   
	int getpatternResultNodefault();
	void setprogrammingQualifying(int flyMode);
	void setResId(int resId);                    
	int getResId(void);                          
	virtual void setVisible(bool visible) override;
	void setshownRatherInitially(bool visible);
	void setcompilerStoprocessing(bool visible);
	int remainsDifferenbetween(int dir_id);
	CC_SYNTHESIZE(bool, m_predictCallpass, lookupRecompilingVector);			
	CC_SYNTHESIZE(wantedConvertibleGroup, scopingReuseBegun, friendsSimplifyDeleter);  
	CC_SYNTHESIZE(addingRelies*, m_father, Father);				
	CC_SYNTHESIZE(cocos2d::Vec2, m_preservingGreater, deductionNeverBehind);           
	CC_SYNTHESIZE(bool, m_constructingUnableIsbns, digitsParameteaWhat3);
	CC_SYNTHESIZE(unsigned short, m_resolvesLibraries, iandRelativeAssigns);        
	CC_SYNTHESIZE(bool, m_expandsBrace, averageIdentification);              
	CC_SYNTHESIZE(bool, m_indicatesCheck, invokesTheyLook);	
	CC_SYNTHESIZE(bool, m_advancedDenoting, defininsideWideThink);
	CC_SYNTHESIZE(bool, m_timesNonexistent, embodiesSolveReplaces);
	CC_SYNTHESIZE(bool, whsuggestInttypPrecede, oftenNotifyManual);
	void setprvoidExtensioindicating(const bool isReorder);
	void printedClosePeppers(int handler);
	void operationDesigning();
	void assignReliesSeparator(int handler);
	void compilationCerrIntended();
	void relativeEcmascriptBuilt(int handler);
	void tuplesCandidateTopics();
	void wilreferKnowsInvolved(int handler);
	void matrixExecutingCompilers();
	void strvecCurrentPushed(int handler);
	void unlessSupplyTreated();
	void effectEliminatedReference(int handler);
	void parametersunlikeRemoved();
	void setRenderMode(int val);
	float getthreeLoopsOperatingMatter();
	virtual void cleanup() override;
	virtual bool getmemberEscapeHowevewe() {return m_interchangeablyNamespaces.isRepMode ; }
private :
	bool expansionManyQuiza(void);
	void setcarsOnlyLetterWithout(void);
public: 
	
	specializingGiveNodtor m_interchangeablyNamespaces;
	bool m_incrementallyPostfix;
	float m_coutIdentical;
	int m_loop;
	int m_remainsPosition;
	int happensView;
	int m_intuitiveDecrements;
	int m_factReside;
	int m_elementsEqualsAspects;
	wantedConvertibleGroup m_type;
	wantedConvertibleGroup handlesKeyword;
private:
	bool generatingCountsHandling;
	bool surprisinglyThrough;
	bool causeValueduring;
	bool m_fairlyInitializersNeeded;
	bool m_instantiatedRequiresCast;
	bool m_indicateLiteral;
	bool computeIntending;
	bool m_loopAffects;
	bool m_hiddenRefersInitially;
	bool omitToolsDerivation;			
	bool m_patternsDelegate;
	int m_operatesRange;
	int m_sizeAttempt;
	int m_opact;
	cocos2d::Rect disallowSuccessful;
	std::string m_particularEyesAbstraction;				
	char m_actionPvrPath[128];
	char m_defaultActionPath[128];
	bool m_isWhite;
	bool m_positionMismatched;
private:
	void loadPlist();
    cocos2d::Animation* setNowAct(const char *sprite_url,int count,int dir_id);
	cocos2d::Animation* getmainHeadIdentical();
	cocos2d::Animate* expectationsVariadicMeans(int RepeatNum);
	void getfriendsAllocateUlong(char* d);
	void getchangingNeitherWhose(char *a);
	void getnothingFlagCould(char *d, char *s, int num, bool old = false);
protected:
	std::map<std::string,cocos2d::EventListenerCustom*> m_seriesHappen;			
	std::vector<std::string> rolesNamed;									
	relationalCalculates m_updateSimplerLetting;														    
	bool m_ischeck;																
	bool striparameterNumbers;															
	bool elementsStunninglySame;														
	bool m_dynamicallyThat;														
	bool m_attemptParametethat;
	bool destroyingTotal;
	bool lettersLinkage;														
	int typesThosmembers;
	int m_memoryAbstractly;
	int m_suitedIndicateVarying;
	int attemptsCollections;
	int destructorsAlternatively;
	int m_addsNumber;
	int m_subscriptUpdateLookup;
	cocos2d::Sprite* m_currentlyBlock;												
	int m_resId;
	int m_dataSeen;
	int numberedNormallyElemtype;
	int m_alsoGeneratesKnew;
	int hasptrHelp;
	int m_assumesEncapsulation;
	int m_nothingSelected;
	std::string m_colonStoplight;					
	bool m_exitRepeat;
	bool m_boHide;
	bool assigningUnderstand;
	std::unordered_map<std::string,int> numberedGrades;							
	std::vector<cocos2d::SpriteFrame*> m_threeLimits;					
public:
	short divideWouldBetterResult(long lifetime,void * despite,char aside); 
	void tediousEncapsulates(int named); 
	double askedOptionsConceptually(char empty,void * sale,int whether,unsigned short pointerlike); 
	char versionInttypAccessible(float prefer,unsigned short accessible,float turns,void * assume); 
	int hidesFriendshipMembers(float marker,float included,void * suppress); 
	void programmingSectionsSchema(float problem); 
	void functionfunctionNext(short verify,void * entire); 
	void considerDescribeUnequal(long overall,bool similarly); 
	void classesFullyTypically(double violations,short prefi,double same,short compilers); 
	int algorithmConstsFind4(float abstract,long revise); 
	void * treatedOnceEachLook(bool hence); 
	unsigned short definedErrorsDigits(float versions,short normal,bool driven); 
private:
	char m_resourcesResultWithout;
	void * m_whappearsWestoreUntil;
};
#endif
