
#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"
#include "tolua++.h"
#include "fieldComparesImprovements_binding.h"
#include "abstractNines_binding.h"
#include "skipRepresentation_binding.h"
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
	
	
	
	
	
			tolua_fieldComparesImprovements_open(tolua_S);
			tolua_abstractNines_open(tolua_S);
			tolua_skipRepresentation_open(tolua_S);
	
	
	tolua_endmodule(tolua_S);
	return 0;
}
