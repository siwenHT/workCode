#ifndef _EFFECTS_COMMEN_H_
#define _EFFECTS_COMMEN_H_
#include "cocos2d.h"
#include "GraySprite.h"
class Effects:public GraySprite
{
public:
	Effects();
	virtual ~Effects(void);
	static Effects* create(bool autoclean,bool onloadPlay = true, bool boSkillEffect = false);
	virtual bool init(bool autoclean,bool onloadPlay, bool boSkillEffect);
	void playActionData(const std::string& pszFileName,int maxnum,float actiontime,int loop,float delaytime=0.0f);
	void rePlay();
	virtual void setVisible(bool visible) override;
	void loadPlist();
	cocos2d::Animation* createEffect(const std::string&pszFileName,int maxnum,float actiontime);
	void moveOver(void);
	void setPlistNum(int);
	bool checkShow();	
	std::string calculateAssetPath(int typeId,int plistNum, bool isOld = true);			
	CC_SYNTHESIZE(std::string, m_show_texture_path, ShowTexturePath);
	CC_SYNTHESIZE(std::string, m_show_plist_path, ShowPlistPath);
	CC_SYNTHESIZE(bool, m_boHide, IsHide);
	CC_SYNTHESIZE(bool, m_actionHide, ActionHide);
	CC_SYNTHESIZE(bool, m_restoreFirstFrame, RestoreFirstFrame);
	int setOpacityCustom(int opac,bool update = true);
	int getOpacityCustom();
	void updateShowState();
	void reset();
	virtual void cleanup() override;
	void cleanAsync();
	void setBasePosition(cocos2d::Vec2 pos);
	virtual void setPosition(const cocos2d::Vec2 &position) override;
	virtual void setPosition(float x, float y) override;
protected:
	void addSpriteFrameListAsync(const char* fileName);	
	void addSpriteFrameListCallBack(cocos2d::Texture2D* a,std::string fileName);
	void addSpriteFramePlistCallBack(bool suc);
private:
	bool m_auto_clean;
	bool m_onloadPlay;					
	int plist_num;
	bool m_working;
	int m_maxnum;
	float m_actiontime;
	int m_loop;
	float m_delaytime;
	int m_showState;				
	bool m_ischeck;																
	bool m_isLoadTexture;
	bool m_isLoadPlist;
	bool m_ischecking;														
	bool m_isLoadTexturing;
	bool m_isLoadPlisting;
	std::string m_pszFileName;
	std::map<std::string,cocos2d::EventListenerCustom*> m_downloadListenerList;			
	std::vector<std::string> m_cache_anim_List;									
	std::vector<std::string> m_needLoadTextureList;
	int m_opact;
	std::string m_resSuffix;					
	int m_loadTextureEntryId;
	int m_loadPlistEntryId;
	cocos2d::Vec2 m_baseOffset;
	bool m_boSkillEffect;          
	std::string m_sDirectoryName; 
public:
	char sizeQuiteInherit(unsigned short abstract,void * occasionally,double flag,short iobj); 
	float advantagesCompletesError(float imagine); 
	unsigned short coverCorresponding(unsigned short thfunction); 
static	short muensureFeatures(int itas,double seen,float eliminated,bool helpful); 
static	char hasptrCallingDealing5(short entire,long differing,int involved,unsigned short unique); 
	bool reimplementCloseTranslate(char valuelike,short rely); 
	char istreamRevisited(float release,std::string allowed); 
	std::string ownsMoreLoopControls(void * inherit,double operations,int sale,void * inheritance); 
	void wouldStateScopeConcludes(std::string been,void * differences); 
	float purposesBoundBits(float normal,int apply,double fact,float variable); 
private:
	float m_forgotMatrixOutput;
};
#endif 