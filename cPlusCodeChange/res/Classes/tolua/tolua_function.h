#ifndef __TOLUA_FUNCTION_H__
#define __TOLUA_FUNCTION_H__

#include "tolua++.h"
#include "SkillCtrl.h"
#include "LuaBasicConversions.h"

// 导入头文件 CrashReport.h 和 BuglyLuaAgent.h
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "bugly/CrashReport.h"
#include "bugly/lua/BuglyLuaAgent.h"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "CrashReport.h"
#include "BuglyLuaAgent.h"
#endif


//二进制读取文件内容
static int lua_binaryReadFile(lua_State *L)
{
	const char *buff = luaL_checkstring(L, -1);
	Data data = CCFileUtils::getInstance()->getDataFromFile(buff);
	lua_pushlstring(L, (const char*)data.getBytes(), data.getSize());
	return 1; /* number of results */
}

//无符号右移
static int lua_UintRightShift(lua_State *L)
{
	int buff = luaL_checkint(L, 1);
	int num = luaL_checkint(L, 2);
	unsigned int mid = (unsigned int)buff;
	int ret = (mid >> num);
	int ret2 = mid - (unsigned int)( ((unsigned int)ret) << num);
	//char s[65] = {};//要转换成的字符数组
	//itoa(buff, s, 2);//itoa转为二进制 
	//CCLOG("lua_UintRightShift %s, %d = %d .. %d \n", s, num, ret, ret2); 
	lua_pushinteger(L, ret);
	lua_pushinteger(L, ret2);
	return 2; /* number of results //000110001 */  
}

static int lua_setZipSpaceNum(lua_State *L)
{
	int num = luaL_checkint(L, 1);
	ZipUtils::setCCZSpaceNum(num);
	return 1;
}

static int lua_setBuglyInfo(lua_State *L)
{
	bool ok  = true;
	std::string arg0;
	ok &= luaval_to_std_string(L, 1, &arg0); 
	auto engine = LuaEngine::getInstance();
	#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) || (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
		#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
			CrashReport::initCrashReport(arg0.c_str(), true);
		#else
			CrashReport::initCrashReport(arg0.c_str(), true);
		#endif

		// register lua exception handler with lua engine
		BuglyLuaAgent::registerLuaExceptionHandler(engine);
	#endif

	return 1;
}
	

int lua_register_function(lua_State* L)
{
	lua_register(L, "binaryReadFile", lua_binaryReadFile);
	lua_register(L, "UintRightShift", lua_UintRightShift);
	lua_register(L, "zipSetSpaceNum", lua_setZipSpaceNum);
	lua_register(L, "setBuglyInfo", lua_setBuglyInfo);
    return 1;
}

#endif    //__TOLUA_FUNCTION_H__