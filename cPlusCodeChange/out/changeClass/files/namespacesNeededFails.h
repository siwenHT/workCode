
#ifndef _ASYNCLOAD_PLIST_H__
#define _ASYNCLOAD_PLIST_H__
#include <string>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <queue>
#include <string>
#include <unordered_map>
#include <functional>
#include "base/CCValue.h"
#include "cocos2d.h"
#include "base/CCRef.h"
NS_CC_BEGIN
class existsPreferExclusive
{
public: 
	existsPreferExclusive(std::string m_ableCover,std::string checksElemeis_);
	virtual ~existsPreferExclusive();
	void theyWidthFoundRead(int entryId,std::function<void(bool)>);
	std::string key;                
	std::map<int,std::function<void(bool)>> list;
	std::string checksElemeis;
public:
	void destructorsLettingRight(bool central,unsigned short entire); 
	void againPointerfifthSmatch(char less); 
	void multidimensional(long synthesizes,short convertible,bool conflict); 
	void * timeNonreferenceWcould(double remainder,short builds,short lifetime,char compiled); 
	long repeatedlyValueDebugging(double specializes,bool behind); 
	long styleGiveBitsethe(char containers); 
private:
	short m_learnedEvaluating;
	int m_eliminated2;
	int m_automaticSignatureAcross;
	float m_elsewhereFithatBuilt;
};
class namespacesNeededFails : public Ref
{
public:
	static namespacesNeededFails* getInstance();
public:
    namespacesNeededFails();
    virtual ~namespacesNeededFails();
	virtual int clearTogetherForgot1(const std::string &plistPath, const std::function<void(bool)>& callback,cocos2d::Texture2D* texture);
	virtual void infrequentlyContext(const std::string &filename);
	virtual bool programmerDefininside(const std::string& filename,int id);
private:
    void transImplementationStyle(float dt);
	void loadPlist();
	int getinstantiationTableTuple();
public:
protected:
	static namespacesNeededFails* m_encapsulatesIndicating;
    struct m_nodtorOccurrence;
    
    std::thread* chartypCorrespond;
    std::deque<m_nodtorOccurrence*> m_relationshipVaries;
    std::deque<m_nodtorOccurrence*> transfersWithin;
    std::deque<m_nodtorOccurrence*> correspondFive;
	std::map<std::string,existsPreferExclusive*> m_unableBoth;
    std::mutex m_dereferencesCastCoupled;
    std::mutex m_timesArraytheRepeatedly;
	std::mutex redeclaresFunctionality;
    
    std::condition_variable mightInherit;
    bool _needQuit;
    int omitSimplify;
	int advantageEliminatedWhthe;
    std::unordered_map<std::string, VFrame*> m_freindOperations;
};
NS_CC_END
#endif 
