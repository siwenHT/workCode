#ifndef __TOLUA_CLIPBOARDHELPER_H__
#define __TOLUA_CLIPBOARDHELPER_H__
#include "tolua++.h" 
#include "placedPerson.h"
int lua_placedPerson_copyLua(lua_State* tolua_S)  
{  
    int argc = 0;  
    placedPerson* cobj = nullptr;  
    bool ok  = true;  
      
#if COCOS2D_DEBUG >= 1  
    tolua_Error tolua_err;  
#endif  
      
      
      
    argc = lua_gettop(tolua_S)-1;  
    if (argc == 1)  
    {  
        std::string arg0;  
          
        ok &= luaval_to_std_string(tolua_S, 2,(std::string *)&arg0, "placedPerson:copyLua");  
          
        if(!ok)  
        {  
            tolua_error(tolua_S,"invalid arguments in function 'lua_placedPerson_copyLua'", nullptr);  
            return 0;  
        }  
        cobj->copyLua(arg0);  
        lua_settop(tolua_S, 1);  
        return 1;  
    }  
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "placedPerson:placedPerson",argc, 1);  
    return 0;  
      
#if COCOS2D_DEBUG >= 1  
    tolua_error(tolua_S,"#ferror in function 'lua_placedPerson_copyLua'.",&tolua_err);  
#endif  
      
    return 0;  
}  
int lua_register_cocos2dx_placedPerson(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"placedPerson");
	tolua_cclass(tolua_S,"placedPerson","placedPerson","cc.Node",NULL);
		tolua_beginmodule(tolua_S,"placedPerson");
		tolua_function(tolua_S, "copyLua", lua_placedPerson_copyLua);
	tolua_endmodule(tolua_S);
    return 1;
}
#endif 