#ifndef __TOLUA_CLIPBOARDHELPER_H__
#define __TOLUA_CLIPBOARDHELPER_H__
#include "tolua++.h" 
#include "ClipboardHelper.h"
int lua_ClipboardHelper_copyLua(lua_State* tolua_S)  
{  
    int argc = 0;  
    ClipboardHelper* cobj = nullptr;  
    bool ok  = true;  
      
#if COCOS2D_DEBUG >= 1  
    tolua_Error tolua_err;  
#endif  
      
      
      
    argc = lua_gettop(tolua_S)-1;  
    if (argc == 1)  
    {  
        std::string arg0;  
          
        ok &= luaval_to_std_string(tolua_S, 2,(std::string *)&arg0, "ClipboardHelper:copyLua");  
          
        if(!ok)  
        {  
            tolua_error(tolua_S,"", nullptr);  
            return 0;  
        }  
        cobj->copyLua(arg0);  
        lua_settop(tolua_S, 1);  
        return 1;  
    }  
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ClipboardHelper:ClipboardHelper",argc, 1);  
    return 0;  
      
#if COCOS2D_DEBUG >= 1  
    tolua_error(tolua_S,"",&tolua_err);  
#endif  
      
    return 0;  
}  
int lua_register_cocos2dx_ClipboardHelper(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ClipboardHelper");
	tolua_cclass(tolua_S,"ClipboardHelper","ClipboardHelper","cc.Node",NULL);
		tolua_beginmodule(tolua_S,"ClipboardHelper");
		tolua_function(tolua_S, "copyLua", lua_ClipboardHelper_copyLua);
	tolua_endmodule(tolua_S);
    return 1;
}
#endif 