#ifndef __TOLUA_LABELNODEC_H__
#define __TOLUA_LABELNODEC_H__
#include "tolua++.h"
#include "LabelNodeC.h"
#include "LuaBasicConversions.h"
int lua_LabelNodeC_create(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"LabelNodeC",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
        do 
		{
			bool arg0;
			ok &= luaval_to_boolean(tolua_S, 2,&arg0);
			LabelNodeC* ret = LabelNodeC::create(arg0);
			do {
				if (NULL != ret){
					object_to_luaval<LabelNodeC>(tolua_S, "LabelNodeC",(LabelNodeC*)ret);
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
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_LabelNodeC_setAdditionalKerning(lua_State* tolua_S)
{
	LabelNodeC* cobj = nullptr;
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"LabelNodeC",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (LabelNodeC*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
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
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_LabelNodeC_setDimensions(lua_State* tolua_S)
{
	LabelNodeC* cobj = nullptr;
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"LabelNodeC",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (LabelNodeC*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
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
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_LabelNodeC_setString(lua_State* tolua_S)
{
	LabelNodeC* cobj = nullptr;
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"LabelNodeC",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (LabelNodeC*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
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
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_LabelNodeC_getString(lua_State* tolua_S)
{
	LabelNodeC* cobj = nullptr;
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"LabelNodeC",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (LabelNodeC*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
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
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_LabelNodeC_setHorizontalAlignment(lua_State* tolua_S)
{
	LabelNodeC* cobj = nullptr;
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"LabelNodeC",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (LabelNodeC*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
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
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_LabelNodeC_setVerticalAlignment(lua_State* tolua_S)
{
	LabelNodeC* cobj = nullptr;
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"LabelNodeC",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (LabelNodeC*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
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
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_LabelNodeC_setLineBreakWithoutSpace(lua_State* tolua_S)
{
	LabelNodeC* cobj = nullptr;
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"LabelNodeC",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (LabelNodeC*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
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
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_LabelNodeC_setMaxLineWidth(lua_State* tolua_S)
{
	LabelNodeC* cobj = nullptr;
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"LabelNodeC",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (LabelNodeC*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
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
			cobj->setMaxLineWidth(arg1);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setMaxLineWidth",argc, 1);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_LabelNodeC_setSystemFontSize(lua_State* tolua_S)
{
	LabelNodeC* cobj = nullptr;
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"LabelNodeC",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (LabelNodeC*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
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
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_LabelNodeC_setColor(lua_State* tolua_S)
{
	LabelNodeC* cobj = nullptr;
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"LabelNodeC",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (LabelNodeC*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
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
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_LabelNodeC_getColor(lua_State* tolua_S)
{
	LabelNodeC* cobj = nullptr;
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"LabelNodeC",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (LabelNodeC*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
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
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_LabelNodeC_setOutLineSize(lua_State* tolua_S)
{
	LabelNodeC* cobj = nullptr;
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"LabelNodeC",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (LabelNodeC*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
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
			cobj->setOutLineSize(arg1);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setOutLineSize",argc, 1);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_LabelNodeC_setOutLineColor(lua_State* tolua_S)
{
	LabelNodeC* cobj = nullptr;
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"LabelNodeC",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (LabelNodeC*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
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
			cobj->setOutLineColor(arg1);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setOutLineColor",argc, 1);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_LabelNodeC_setLabelChild(lua_State* tolua_S)
{
	LabelNodeC* cobj = nullptr;
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"LabelNodeC",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (LabelNodeC*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		do 
		{
			cocos2d::Label* arg0;
			ok &= luaval_to_object<cocos2d::Label>(tolua_S, 2, "cc.Label",&arg0, "lua_LabelNodeC_setLabelChild");
			if (!ok) { break; }
			cobj->setLabelChild(arg0);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setLabelChild",argc, 1);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_LabelNodeC_getLabelChild(lua_State* tolua_S)
{
	LabelNodeC* cobj = nullptr;
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"LabelNodeC",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (LabelNodeC*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 0)
	{
		do 
		{
			cocos2d::Label* ret = cobj->getLabelChild();
			object_to_luaval<cocos2d::Label>(tolua_S, "cc.Node",(cocos2d::Label*)ret);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "getLabelChild",argc, 1);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_register_cocos2dx_LabelNodeC(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"LabelNodeC");
	tolua_cclass(tolua_S,"LabelNodeC","LabelNodeC","cc.Node",NULL);
		tolua_beginmodule(tolua_S,"LabelNodeC");
			tolua_function(tolua_S, "create", lua_LabelNodeC_create);
		
			tolua_function(tolua_S, "setAdditionalKerning", lua_LabelNodeC_setAdditionalKerning);
			tolua_function(tolua_S, "setDimensions", lua_LabelNodeC_setDimensions);
			tolua_function(tolua_S, "setString", lua_LabelNodeC_setString);
			tolua_function(tolua_S, "getString", lua_LabelNodeC_getString);
			tolua_function(tolua_S, "setHorizontalAlignment", lua_LabelNodeC_setHorizontalAlignment);
			tolua_function(tolua_S, "setVerticalAlignment", lua_LabelNodeC_setVerticalAlignment);
			tolua_function(tolua_S, "setLineBreakWithoutSpace", lua_LabelNodeC_setLineBreakWithoutSpace);
			tolua_function(tolua_S, "setMaxLineWidth", lua_LabelNodeC_setMaxLineWidth);
			tolua_function(tolua_S, "setSystemFontSize", lua_LabelNodeC_setSystemFontSize);
			tolua_function(tolua_S, "setColor", lua_LabelNodeC_setColor);
			tolua_function(tolua_S, "getColor", lua_LabelNodeC_getColor);
			tolua_function(tolua_S, "setOutLineSize", lua_LabelNodeC_setOutLineSize);
			tolua_function(tolua_S, "setOutLineColor", lua_LabelNodeC_setOutLineColor);
			tolua_function(tolua_S, "setLabelChild", lua_LabelNodeC_setLabelChild);
			tolua_function(tolua_S, "getLabelChild", lua_LabelNodeC_getLabelChild);
		tolua_endmodule(tolua_S);
    return 1;
}
#endif    