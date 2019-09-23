#ifndef __TOLUA_FUNCTION_H__
#define __TOLUA_FUNCTION_H__

#include "tolua++.h"
#include "SkillCtrl.h"
#include "LuaBasicConversions.h"

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
	

int lua_register_function(lua_State* L)
{
	lua_register(L, "binaryReadFile", lua_binaryReadFile);
	lua_register(L, "UintRightShift", lua_UintRightShift);
	lua_register(L, "zipSetSpaceNum", lua_setZipSpaceNum);
    return 1;
}

#endif    //__TOLUA_FUNCTION_H__