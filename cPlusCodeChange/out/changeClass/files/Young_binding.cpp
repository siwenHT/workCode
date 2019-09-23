
#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"
#include "tolua++.h"
#include "increasedTable_binding.h"
#include "sensibleApplication_binding.h"
#include "inspiredPass_binding.h"
#include "cocos2d.h"
extern "C"
{
int luaopen_cjson(lua_State *l);
int luaopen_cjson_safe(lua_State *l);
}
TOLUA_API int tolua_Young_open (lua_State *tolua_S)
{
	tolua_open(tolua_S);
	tolua_beginmodule(tolua_S, nullptr);
	
	
	
	
	
			tolua_increasedTable_open(tolua_S);
			tolua_sensibleApplication_open(tolua_S);
			tolua_inspiredPass_open(tolua_S);
	
	
	tolua_endmodule(tolua_S);
	return 0;
}
