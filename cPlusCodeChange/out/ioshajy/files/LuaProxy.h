#ifndef __TOLUA_LUAPROXY_H__
#define __TOLUA_LUAPROXY_H__
extern "C" {
#include "lua.h"
#include "tolua++.h"
}
TOLUA_API int lua_LuaProxy(lua_State* tolua_S);
#endif 