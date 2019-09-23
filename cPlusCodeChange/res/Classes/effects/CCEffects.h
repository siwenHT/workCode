#ifndef _EFFECTS_COMMEN_H_
#define _EFFECTS_COMMEN_H_
#include "cocos2d.h"
#include "GraySprite.h"
class Effects:public GraySprite
{
public:
	Effects();
	virtual ~Effects(void);
	//onloadPlay 加载完成后立即播放 默认为真
	static Effects* create(bool autoclean,bool onloadPlay = true, bool boSkillEffect = false);
	virtual bool init(bool autoclean,bool onloadPlay, bool boSkillEffect);
	void playActionData(const std::string& pszFileName,int maxnum,float actiontime,int loop,float delaytime=0.0f);
	void rePlay();
	virtual void setVisible(bool visible) override;

	void loadPlist();
	cocos2d::Animation* createEffect(const std::string&pszFileName,int maxnum,float actiontime);
	void moveOver(void);
	void setPlistNum(int);
	bool checkShow();		//检测资源是否齐全
	std::string calculateAssetPath(int typeId,int plistNum, bool isOld = true);				//计算m_plistPath，m_pvrPath的路径  typeId=1表增plist  2表示pvr

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
	void addSpriteFrameListAsync(const char* fileName);		//异步加载plist文件
	void addSpriteFrameListCallBack(cocos2d::Texture2D* a,std::string fileName);
	void addSpriteFramePlistCallBack(bool suc);

private:
	//执行的最后动作
	bool m_auto_clean;
	bool m_onloadPlay;						//是否加载完重新播放
	int plist_num;
	bool m_working;

	int m_maxnum;
	float m_actiontime;
	int m_loop;
	float m_delaytime;

	int m_showState;					//0表示无资源 1表示有资源未加载 2表示有资源且都已加载
	bool m_ischeck;																	//是否检查过显示（本地是否有资源文件，是否需要下载）
	bool m_isLoadTexture;
	bool m_isLoadPlist;

	bool m_ischecking;															//是否加载过资源
	bool m_isLoadTexturing;	
	bool m_isLoadPlisting;
	std::string m_pszFileName;
	std::map<std::string,cocos2d::EventListenerCustom*> m_downloadListenerList;				//下载事件监听列表 键值对
	std::vector<std::string> m_cache_anim_List;										//缓存的动画Key值列表 在析构函数里面，将缓存去除
	std::vector<std::string> m_needLoadTextureList;	

	int m_opact;
	std::string m_resSuffix;						//资源类型

	int m_loadTextureEntryId;
	int m_loadPlistEntryId;

	cocos2d::Vec2 m_baseOffset;

	bool m_boSkillEffect;          // 是否是技能特效特效
	std::string m_sDirectoryName; // 特效目录名
};

#endif //_EFFECTS_COMMEN_