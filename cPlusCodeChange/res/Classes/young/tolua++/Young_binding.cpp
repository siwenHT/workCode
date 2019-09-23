
#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

#include "GUI/ScrollView/YScrollView_binding.h"
#include "GUI/ScrollView/YGirdViewCell_binding.h"
#include "GUI/ScrollView/YGirdView_binding.h"


#include "cocos2d.h"
extern "C"
{
int luaopen_cjson(lua_State *l);
int luaopen_cjson_safe(lua_State *l);
}

/* Open function */
TOLUA_API int tolua_Young_open (lua_State *tolua_S)
{
	//CCLOG( "before tolua_Young_open: top = %d", lua_gettop(tolua_S) );
/*	
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID	) 
	luaopen_cjson(tolua_S);
	lua_pushstring(tolua_S, "safe");
	luaopen_cjson_safe(tolua_S);
	lua_rawset(tolua_S, -3);
	lua_pop(tolua_S, 1);
#endif
	*/
	tolua_open(tolua_S);

	// push '_G'
	tolua_beginmodule(tolua_S, nullptr);
		// _G["Young"] = {}
		//tolua_module(tolua_S, "Young", false);
		
		// push 'Young'
		//tolua_beginmodule(tolua_S, "Young");
			tolua_YScrollView_open(tolua_S);
			tolua_YGirdViewCell_open(tolua_S);
			tolua_YGirdView_open(tolua_S);
		// pop 'Young'
		//tolua_endmodule(tolua_S);
	// pop '_G'
	tolua_endmodule(tolua_S);
	//CCLOG( "after tolua_Young_open: top = %d", lua_gettop(tolua_S) );
	return 0;
}

