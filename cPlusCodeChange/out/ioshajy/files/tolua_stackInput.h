#ifndef __TOLUA_LABELNODEC_H__
#define __TOLUA_LABELNODEC_H__
#include "tolua++.h"
#include "stackInput.h"
#include "LuaBasicConversions.h"
int lua_stackInput_create(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"stackInput",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
        do 
		{
			bool arg0;
			ok &= luaval_to_boolean(tolua_S, 2,&arg0);
			stackInput* ret = stackInput::create(arg0);
			do {
				if (NULL != ret){
					object_to_luaval<stackInput>(tolua_S, "stackInput",(stackInput*)ret);
				}
				else
					lua_pushnil(tolua_S);
				} while (0);
			 return 1;
		} while (0);
	}
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_stackInput_create'.",&tolua_err);
#endif
    return 0;
}
int lua_stackInput_setAdditionalKerning(lua_State* tolua_S)
{
	stackInput* cobj = nullptr;
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"stackInput",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (stackInput*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_stackInput_setAdditionalKerning'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		do 
		{
			double arg1;
			ok &= luaval_to_number(tolua_S, 2,&arg1);
			if (!ok) { return 0; }
			cobj->setAdditionalKerning(arg1);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setAdditionalKerning",argc, 1);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_stackInput_setAdditionalKerning'.",&tolua_err);
#endif
	return 0;
}
int lua_stackInput_setDimensions(lua_State* tolua_S)
{
	stackInput* cobj = nullptr;
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"stackInput",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (stackInput*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_stackInput_setDimensions'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 2)
	{
		do 
		{
			double arg1;
			double arg2;
			ok &= luaval_to_number(tolua_S, 2,&arg1);
			if (!ok) { return 0; }
			ok &= luaval_to_number(tolua_S, 3,&arg2);
			if (!ok) { return 0; }
			cobj->setDimensions(arg1,arg2);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setDimensions",argc, 1);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_stackInput_setDimensions'.",&tolua_err);
#endif
	return 0;
}
int lua_stackInput_setString(lua_State* tolua_S)
{
	stackInput* cobj = nullptr;
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"stackInput",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (stackInput*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_stackInput_setString'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		do 
		{
			std::string arg1;
			ok &= luaval_to_std_string(tolua_S, 2,&arg1);
			if (!ok) { return 0; }
			cobj->setString(arg1);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setString",argc, 1);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_stackInput_setString'.",&tolua_err);
#endif
	return 0;
}
int lua_stackInput_getString(lua_State* tolua_S)
{
	stackInput* cobj = nullptr;
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"stackInput",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (stackInput*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_stackInput_getString'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 0)
	{
		do 
		{
			std::string arg1 = cobj->getString();
			tolua_pushcppstring(tolua_S,arg1);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "getString",argc, 1);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_stackInput_getString'.",&tolua_err);
#endif
	return 0;
}
int lua_stackInput_setHorizontalAlignment(lua_State* tolua_S)
{
	stackInput* cobj = nullptr;
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"stackInput",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (stackInput*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_stackInput_setHorizontalAlignment'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		do 
		{
			int arg1;
			ok &= luaval_to_int32(tolua_S, 2,&arg1);
			if (!ok) { return 0; }
			cobj->setHorizontalAlignment((TextHAlignment)arg1);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setHorizontalAlignment",argc, 1);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_stackInput_setHorizontalAlignment'.",&tolua_err);
#endif
	return 0;
}
int lua_stackInput_setVerticalAlignment(lua_State* tolua_S)
{
	stackInput* cobj = nullptr;
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"stackInput",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (stackInput*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_stackInput_setVerticalAlignment'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		do 
		{
			int arg1;
			ok &= luaval_to_int32(tolua_S, 2,&arg1);
			if (!ok) { return 0; }
			cobj->setVerticalAlignment((TextVAlignment)arg1);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setVerticalAlignment",argc, 1);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_stackInput_setVerticalAlignment'.",&tolua_err);
#endif
	return 0;
}
int lua_stackInput_setLineBreakWithoutSpace(lua_State* tolua_S)
{
	stackInput* cobj = nullptr;
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"stackInput",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (stackInput*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_stackInput_setLineBreakWithoutSpace'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		do 
		{
			bool arg1;
			ok &= luaval_to_boolean(tolua_S, 2,&arg1);
			if (!ok) { return 0; }
			cobj->setLineBreakWithoutSpace(arg1);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setLineBreakWithoutSpace",argc, 1);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_stackInput_setLineBreakWithoutSpace'.",&tolua_err);
#endif
	return 0;
}
int lua_stackInput_setbackCoveredPointers(lua_State* tolua_S)
{
	stackInput* cobj = nullptr;
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"stackInput",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (stackInput*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_stackInput_setbackCoveredPointers'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		do 
		{
			double arg1;
			ok &= luaval_to_number(tolua_S, 2,&arg1);
			if (!ok) { return 0; }
			cobj->setbackCoveredPointers(arg1);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setbackCoveredPointers",argc, 1);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_stackInput_setbackCoveredPointers'.",&tolua_err);
#endif
	return 0;
}
int lua_stackInput_setSystemFontSize(lua_State* tolua_S)
{
	stackInput* cobj = nullptr;
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"stackInput",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (stackInput*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_stackInput_setSystemFontSize'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		do 
		{
			double arg1;
			ok &= luaval_to_number(tolua_S, 2,&arg1);
			if (!ok) { return 0; }
			cobj->setSystemFontSize(arg1);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setSystemFontSize",argc, 1);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_stackInput_setSystemFontSize'.",&tolua_err);
#endif
	return 0;
}
int lua_stackInput_setColor(lua_State* tolua_S)
{
	stackInput* cobj = nullptr;
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"stackInput",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (stackInput*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_stackInput_setColor'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		do 
		{
			cocos2d::Color3B arg1;
			ok &= luaval_to_color3b(tolua_S, 2,&arg1);
			if (!ok) { return 0; }
			cobj->setColor(arg1);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setColor",argc, 1);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_stackInput_setColor'.",&tolua_err);
#endif
	return 0;
}
int lua_stackInput_getColor(lua_State* tolua_S)
{
	stackInput* cobj = nullptr;
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"stackInput",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (stackInput*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_stackInput_getColor'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 0)
	{
		do 
		{
			const cocos2d::Color3B& ret = cobj->getColor();
			color3b_to_luaval(tolua_S, ret);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "getColor",argc, 1);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_stackInput_getColor'.",&tolua_err);
#endif
	return 0;
}
int lua_stackInput_setnearlyDealingReplacement(lua_State* tolua_S)
{
	stackInput* cobj = nullptr;
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"stackInput",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (stackInput*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_stackInput_setnearlyDealingReplacement'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		do 
		{
			double arg1;
			ok &= luaval_to_number(tolua_S, 2,&arg1);
			if (!ok) { return 0; }
			cobj->setnearlyDealingReplacement(arg1);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setnearlyDealingReplacement",argc, 1);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_stackInput_setnearlyDealingReplacement'.",&tolua_err);
#endif
	return 0;
}
int lua_stackInput_setcallSerialWestoreChoice(lua_State* tolua_S)
{
	stackInput* cobj = nullptr;
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"stackInput",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (stackInput*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_stackInput_setcallSerialWestoreChoice'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		do 
		{
			cocos2d::Color4B arg1;
			ok &= luaval_to_color4b(tolua_S, 2,&arg1);
			if (!ok) { return 0; }
			cobj->setcallSerialWestoreChoice(arg1);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setcallSerialWestoreChoice",argc, 1);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_stackInput_setcallSerialWestoreChoice'.",&tolua_err);
#endif
	return 0;
}
int lua_stackInput_setfindbookRequested(lua_State* tolua_S)
{
	stackInput* cobj = nullptr;
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"stackInput",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (stackInput*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_stackInput_setfindbookRequested'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		do 
		{
			cocos2d::Label* arg0;
			ok &= luaval_to_object<cocos2d::Label>(tolua_S, 2, "cc.Label",&arg0, "lua_stackInput_setfindbookRequested");
			if (!ok) { break; }
			cobj->setfindbookRequested(arg0);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setfindbookRequested",argc, 1);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_stackInput_setfindbookRequested'.",&tolua_err);
#endif
	return 0;
}
int lua_stackInput_getfindbookRequested(lua_State* tolua_S)
{
	stackInput* cobj = nullptr;
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"stackInput",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (stackInput*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_stackInput_getfindbookRequested'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 0)
	{
		do 
		{
			cocos2d::Label* ret = cobj->getfindbookRequested();
			object_to_luaval<cocos2d::Label>(tolua_S, "cc.Node",(cocos2d::Label*)ret);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "getfindbookRequested",argc, 1);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_stackInput_getfindbookRequested'.",&tolua_err);
#endif
	return 0;
}
int lua_register_cocos2dx_stackInput(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"stackInput");
	tolua_cclass(tolua_S,"stackInput","stackInput","cc.Node",NULL);
		tolua_beginmodule(tolua_S,"stackInput");
			tolua_function(tolua_S, "create", lua_stackInput_create);
		
			tolua_function(tolua_S, "setAdditionalKerning", lua_stackInput_setAdditionalKerning);
			tolua_function(tolua_S, "setDimensions", lua_stackInput_setDimensions);
			tolua_function(tolua_S, "setString", lua_stackInput_setString);
			tolua_function(tolua_S, "getString", lua_stackInput_getString);
			tolua_function(tolua_S, "setHorizontalAlignment", lua_stackInput_setHorizontalAlignment);
			tolua_function(tolua_S, "setVerticalAlignment", lua_stackInput_setVerticalAlignment);
			tolua_function(tolua_S, "setLineBreakWithoutSpace", lua_stackInput_setLineBreakWithoutSpace);
			tolua_function(tolua_S, "setbackCoveredPointers", lua_stackInput_setbackCoveredPointers);
			tolua_function(tolua_S, "setSystemFontSize", lua_stackInput_setSystemFontSize);
			tolua_function(tolua_S, "setColor", lua_stackInput_setColor);
			tolua_function(tolua_S, "getColor", lua_stackInput_getColor);
			tolua_function(tolua_S, "setnearlyDealingReplacement", lua_stackInput_setnearlyDealingReplacement);
			tolua_function(tolua_S, "setcallSerialWestoreChoice", lua_stackInput_setcallSerialWestoreChoice);
			tolua_function(tolua_S, "setfindbookRequested", lua_stackInput_setfindbookRequested);
			tolua_function(tolua_S, "getfindbookRequested", lua_stackInput_getfindbookRequested);
		tolua_endmodule(tolua_S);
    return 1;
}
#endif    