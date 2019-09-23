#ifndef _SPIRIT_BASE_H_
#define _SPIRIT_BASE_H_
#include "cocos2d.h"
#include "stringsLargeEspecially.h"
#include "auxiliaryEssential.h"
#include "listthPoints.h"
#include "withDesigned.h"
#include "exceptionNodefault.h"
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
}throwsPreviously;
typedef enum {
	ACTION_MOVE_TAG = 20,
	ACTION_FLY01_TAG = 21,
	ACTION_FLY02_TAG = 22,
	ACTION_SET_TILE_TAG = 23,
	ACTION_ATTACK_TAG = 24,
	ACTION_SUDDEN_TAG = 25,
	ACTION_SHADOW_TAG = 26,					
}contractTuple;
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
}extendedUsesMatch;
typedef enum {
	actionsThgenerates_EMPTY = 0,			 
	actionsThgenerates_ASSET = 1,			 
	actionsThgenerates_LOADED = 2,			     
	actionsThgenerates_ALL = 3,			     
}actionsThgenerates;
class copiedFlipsActual : public cocos2d::Node
{
public: 
	copiedFlipsActual();
	virtual ~copiedFlipsActual(void);
	virtual bool correctSettingIcase(cocos2d::Touch* thisPos);
	virtual void setitemContainersUnable(bool enabled);
	virtual bool initWithFile(const std::string&m_ableCover, std::string actorId = "");
	static copiedFlipsActual* create(const std::string&m_ableCover);
	static copiedFlipsActual* create(const std::string&m_ableCover, std::string actorId);
	static copiedFlipsActual* create(const std::string&m_ableCover,cocos2d::Size touch_size);
	void reset();
	void setknowPdataOrganize(const std::string&m_ableCover);
	void setconversionchapterModel(cocos2d::Point anchorPoint);
	virtual void setstartingBasicsNamespaces(cocos2d::Point pos);
	void leadsEntireConcludes();				
	void minimizeDiscussioofWithin4();
	void whenRespectiveExternfifth(float dt);
	int learnedInheritance(extendedUsesMatch type, int z);
	void getsIntendedCease(const auxiliaryEssential dir);
	void parametisPreventAddress(float times,stringsLargeEspecially action,auxiliaryEssential dir,int loop,float ltimes=0.0f,bool stopAnim = true);
	virtual void gradingLatestRedeclare(float times,stringsLargeEspecially action,auxiliaryEssential dir,int loop,float ltimes=0.0f);
	void distinctEndingLiteral(int standcut,int runcut, int attackcut, int gethitcut, int deathcut, int maxcut2,float times,auxiliaryEssential dir);
	void headExecutableUnique(const std::string&m_ableCover,int maxcut);
	void actionsEntryLanguage(const std::string&m_ableCover,int maxcut);
	void overloadedThemselves(const std::string&m_ableCover,int maxcut);
	void anotherWholeTypically(const std::string&m_ableCover,int maxcut);
	void bypassControlsTakes(const std::string&m_ableCover,int maxcut);
	void throughoutDigitsExtent(int m_alsoCompletesReferencwhat,int compareisbnLiterals,int seenDigitsPresented);
	void leavingNumberAccessible2(const std::string&m_ableCover,int maxcut);
	void redeclareIgnoredBackslash(const std::string&m_ableCover,int maxcut);
	void reflectCopyOstream(const std::string&m_ableCover,int maxcut_03,int maxcut_04);
	void indexedExpandsTopic(int m_pointsunlikeUnrelated,int max_run);
	void mubeImageDirection(int maxcut_mode1,int maxcut_mode2,int maxcut_mode3,int maxcut_mode4,int maxcut_mode5,int maxcut_mode6,int maxcut_mode7,int maxcut_mode8,int maxcut_mode9,int maxcut_mode10,int maxcut_mode11,int maxcut_mode12);
	void compileReviseConsider3(int maxcut1,int maxcut2,int maxcut3, int maxcut4,int maxcut5,int maxcut6,int maxcut7,int maxcut8,int maxcut9,int maxcut10,int maxcut11,int maxcut12);
	cocos2d::Vec2 getpointersSomewhereAssume(auxiliaryEssential dir);
	cocos2d::Vec2 getcandidateEqualDefined(auxiliaryEssential dir);
	int getnonconstBehind(cocos2d::Sprite* sp,auxiliaryEssential dir);
	virtual bool escapeSimplerThrows(float times,Vec2 pos,auxiliaryEssential dir);
	bool getIsHide() {return m_boHide;};          
	void setIsHide(bool hide);          
	void savedUnderstandingBegins(float time);
	virtual void standed();
	virtual void standedby(){};
	virtual void generatedDenotingStrblob(float times,cocos2d::Point pos,bool stand = true);
	virtual void matchesEndsDimension1(float times,cocos2d::Point pos,bool stand = true);
	virtual void sectionGuaranteeHighest(float times,int fly_mode,int handler,cocos2d::Vec2 newPos = cocos2d::Vec2::ZERO,auxiliaryEssential dir = dir_none,bool stand = true,bool auto_double_jump_check = false,bool checkSecondAction = false, int state = 0);
	virtual void moveToPos(float times,cocos2d::Point pos,bool stand = false);
	virtual void walkToPos(float times,cocos2d::Point pos,bool stand = true);
	virtual bool nestedOwhichBetween(float times,cocos2d::Point newpoint,bool hasEffect = false);
	virtual bool persistTupleValues1(float times,cocos2d::Point newpoint);
	virtual bool differAroundImpactHard(float times,cocos2d::Point newpoint);
	virtual void hasHurted(float delay,float times);
	virtual bool ownsPrecedeDerivation(float times,cocos2d::Point pos,auxiliaryEssential dir);
	virtual bool happensElemeisEachHappens(float times,cocos2d::Point pos,auxiliaryEssential dir = dir_none,bool stand = false);
	virtual bool colonAssignsVaries(float times,cocos2d::Point pos,auxiliaryEssential dir);
	virtual void gotoDeath(auxiliaryEssential dir);
	virtual bool deductionOfileNearly(float times,auxiliaryEssential dir){return false;};
	virtual bool seriesSalesRationale(float times,auxiliaryEssential dir){return false;};
	virtual bool integralEvaluating(float times,auxiliaryEssential dir);
	virtual void refresh();
	virtual void FixFlyPos(){};
	bool setsquaresConstitutesGuide(cocos2d::Point newpoint);
	auxiliaryEssential getoriginalSubsequent(cocos2d::Point newpoint);
	virtual void prvoidLeadsChoice(throwsPreviously toState);
	void previousDeclaring();
	bool setlockDesignedConsiderWmust(auxiliaryEssential dir);
	int setOpacity(int opac,bool update = true);
	int getOpacity();
	void rejectBypassSelects(int opac,float animTime);
	void prvoidSearchParts(float times);
	void setColor(const cocos2d::Color3B& color) override;
	void setGray(bool isgray);
	void setWhite(bool isgray);
	bool getbasicNumbersEverything();
	CC_SYNTHESIZE(throwsPreviously, m_askingExecuted, appeaanywhereScopedBasic);
	CC_SYNTHESIZE(withDesigned*, m_functionalthoughJumping, listedUndefinedparameters);
	CC_SYNTHESIZE(Node*, main_node, stringstheTheirExample);
	CC_SYNTHESIZE(cocos2d::Vec2, m_wantedEvaluated, treatedDescribeSeparately);
	CC_SYNTHESIZE(cocos2d::Vec2, m_correspondBlobptr, correctObtainOstream);	
	void setTypeId(extendedUsesMatch typeId,bool initDepend = true);
	extendedUsesMatch getTypeId(){ return m_type; };
	CC_SYNTHESIZE(bool, m_peopleSettingReplaces, explainingUnnecessary);	
	int getbraceTwinThposition(){ return m_mightRunsWords;};
	virtual void setbraceTwinThposition(int state){
		m_mightRunsWords = state;
	}
	void setOnRide(int ride_id);
	bool getOnRide();
	int getincompleteNodtorContained();
	bool getstrategyShownAbstractly();
	auxiliaryEssential getstreamConditionTechniques(){ return wholeSpecialObjectsth.dir; }
	stringsLargeEspecially getolderPermittedAllow(){ return wholeSpecialObjectsth.acttodo; }
	bool diskSelects;
	void setscopingHairBlueprint(int num){ callableLookupLimitation = num; }
	bool elementMattersApplication1();		
	virtual bool checkShow();	
	virtual void somewhatStopsCharacters();
	void imageTellAkin(char* fileName);	
	void qualifyingSaid4(cocos2d::Texture2D* a,std::string fileName);
	void logicalLabeledUnusual(bool suc);
	void replacementChapter();
	void differentlyPattern();
	CC_SYNTHESIZE(std::string, includeRealizing, publiclyExtensions);
	CC_SYNTHESIZE(std::string, allowedStrictly, computeBenefitEliminated);
	CC_SYNTHESIZE(std::string, describeMultidimensional, decrementsCerrRealBits);
	bool instancesSomewhat(throwsPreviously actionState);
	bool beControl();
	CC_SYNTHESIZE(std::string, m_actorId, nodefaultDoesPermitted);      
	CC_SYNTHESIZE(int, independentlyEnumerations, explainsPositionsCertain);  
	int getLocalZOrder();                        
	void setexhaustedIntvaluesAlready(int attackMode);   
	int getexhaustedIntvaluesAlready();
	void setlimitsThdefinesCounts4(int flyMode);
	void setResId(int resId);                    
	int getResId(void);                          
	virtual void setVisible(bool visible) override;
	void setthreeFilesOperand(bool visible);
	void setsubsetSufficientlyHere(bool visible);
	int specializesLvalueUnlike(int dir_id);
	CC_SYNTHESIZE(bool, normallyAlgorithmsPersist, selectsSpecialized);			
	CC_SYNTHESIZE(extendedUsesMatch, itselfProperlyRemoved, createConvertInclude);  
	CC_SYNTHESIZE(copiedFlipsActual*, m_father, Father);				
	CC_SYNTHESIZE(cocos2d::Vec2, m_convertingSequenceProvide, singleCollideTesting);           
	CC_SYNTHESIZE(bool, m_primaryIand, interactsCollections);
	CC_SYNTHESIZE(unsigned short, m_typcanPrevents, thinkPossibleFamiliar);        
	CC_SYNTHESIZE(bool, m_employeeInaccessible, controlCoveringExecution);              
	CC_SYNTHESIZE(bool, outsideBehaviorSections, chaptersSubsequent);	
	CC_SYNTHESIZE(bool, m_powerfulProtection, refersDestroyingSignals);
	CC_SYNTHESIZE(bool, m_frontAutomatically, requirementsUnlikeMissing);
	CC_SYNTHESIZE(bool, m_givenStatements, deallocatingRemains);
	void setwhisSynthesizesKindLeft(const bool isReorder);
	void makingTemplates(int handler);
	void wregexComputationalPasses();
	void inverselyStillHierarchy(int handler);
	void verifyStoredImportance();
	void readersTakesAdding(int handler);
	void describeMuensure();
	void tpassEnclosedReset(int handler);
	void cmatchPassedFamily();
	void suppliedUnderTakes(int handler);
	void learnHereOnalthoughHasptr4();
	void elsewhereExpandsConverted(int handler);
	void curliesOccur();
	void setRenderMode(int val);
	float getimplementsReviseSkim();
	virtual void cleanup() override;
	virtual bool getmatrixBrowsersAllowed() {return wholeSpecialObjectsth.isRepMode ; }
private :
	bool overrideThereManage(void);
	void setindirectNonexistentWish(void);
public: 
	
	listthPoints wholeSpecialObjectsth;
	bool everyFunctionfunction;
	float m_couldMismatched;
	int m_loop;
	int tokensVariableInteresting;
	int m_whifPassingIncreased;
	int movingRemovedNote;
	int indeedFlag;
	int m_mightRunsWords;
	extendedUsesMatch m_type;
	extendedUsesMatch happensReadyAlso;
private:
	bool m_statementsReadNotify;
	bool m_initializerAllocates;
	bool m_meansAkin;
	bool m_extendMachine;
	bool outerBehind;
	bool m_preferAttemptedOmitting;
	bool m_suchMemberwise;
	bool derivedContadeclarations;
	bool recursiveConcludesArgs;
	bool m_curtokArrayCompiler;			
	bool m_essentiallyActuasize;
	int callableLookupLimitation;
	int m_functionality;
	int m_opact;
	cocos2d::Rect sequenceLooksSignature;
	std::string rolesPreceding;				
	char m_actionPvrPath[128];
	char m_defaultActionPath[128];
	bool m_isWhite;
	bool failsTrans;
private:
	void loadPlist();
    cocos2d::Animation* setNowAct(const char *sprite_url,int count,int dir_id);
	cocos2d::Animation* getcomputingSlowDoubledLegal();
	cocos2d::Animate* includesThemKnows(int RepeatNum);
	void getgeneralMainNumber(char* d);
	void getreadingMeddleComplex(char *a);
	void getpositionPartiallyMust(char *d, char *s, int num, bool old = false);
protected:
	std::map<std::string,cocos2d::EventListenerCustom*> fromGivenNumbered;			
	std::vector<std::string> m_promotesTuple;									
	actionsThgenerates shouldInstantionControl;														    
	bool m_ischeck;																
	bool writeInteraction;															
	bool differentManipulateLarger;														
	bool m_argumepassedAssigns;														
	bool m_groupDoubledPrevious;
	bool m_lookupOriginal;
	bool abstractCentral;														
	int manageModify;
	int independentlyPackBook;
	int techniqueResource;
	int m_mismatchedRationale;
	int tyhaveAdvance;
	int m_cerrQualifying;
	int m_yourUninitialized;
	cocos2d::Sprite* languagePrefi;												
	int m_resId;
	int unchangedIntended;
	int m_wroteRatherRecently;
	int m_simplyElemeisAggregate;
	int m_rememberExecutes;
	int m_cmatchSeparatorMatter;
	int m_especiallyIath;
	std::string flagWords;					
	bool encapsulationArguments;
	bool m_boHide;
	bool m_variableSmart;
	std::unordered_map<std::string,int> m_obtainOmitting;							
	std::vector<cocos2d::SpriteFrame*> m_whversionEncapsulates;					
public:
static	double expectsProgramNature(short number,long lookup,bool view); 
	void givenTransactioThdefines(int unrelated); 
	short functionalthoughFully(char executable,int form,long less,bool whappears); 
	char nestedAnotherAndquery(void * destructors,float indexed,short given,float condition); 
	void * reviewControlIdentifying(long choice,bool listed); 
	long colorBrownSiteLink(short simplify,unsigned short answer); 
static	bool rationaleManageFixed(short ulong,float permitted); 
	long incompleteWantEnough1(long generate); 
private:
	char m_incompleteParametis;
	char m_explainWideCharacters;
	int m_blobInformHelpful;
	char m_looksAfterCentral;
};
#endif
