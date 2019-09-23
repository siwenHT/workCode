#ifndef __TOLUA_LABELNODEC_H__
#define __TOLUA_LABELNODEC_H__
#include "tolua++.h"
#include "generatedSureGreater.h"
#include "LuaBasicConversions.h"
int lua_generatedSureGreater_create(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"generatedSureGreater",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
        do 
		{
			bool arg0;
			ok &= luaval_to_boolean(tolua_S, 2,&arg0);
			generatedSureGreater* ret = generatedSureGreater::create(arg0);
			do {
				if (NULL != ret){
					object_to_luaval<generatedSureGreater>(tolua_S, "generatedSureGreater",(generatedSureGreater*)ret);
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
    tolua_error(tolua_S,"#ferror in function 'lua_generatedSureGreater_create'.",&tolua_err);
#endif
    return 0;
}
int lua_generatedSureGreater_setAdditionalKerning(lua_State* tolua_S)
{
	generatedSureGreater* cobj = nullptr;
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"generatedSureGreater",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (generatedSureGreater*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_generatedSureGreater_setAdditionalKerning'", NULL);
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
	tolua_error(tolua_S,"#ferror in function 'lua_generatedSureGreater_setAdditionalKerning'.",&tolua_err);
#endif
	return 0;
}
int lua_generatedSureGreater_setDimensions(lua_State* tolua_S)
{
	generatedSureGreater* cobj = nullptr;
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"generatedSureGreater",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (generatedSureGreater*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_generatedSureGreater_setDimensions'", NULL);
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
	tolua_error(tolua_S,"#ferror in function 'lua_generatedSureGreater_setDimensions'.",&tolua_err);
#endif
	return 0;
}
int lua_generatedSureGreater_setString(lua_State* tolua_S)
{
	generatedSureGreater* cobj = nullptr;
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"generatedSureGreater",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (generatedSureGreater*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_generatedSureGreater_setString'", NULL);
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
	tolua_error(tolua_S,"#ferror in function 'lua_generatedSureGreater_setString'.",&tolua_err);
#endif
	return 0;
}
int lua_generatedSureGreater_getString(lua_State* tolua_S)
{
	generatedSureGreater* cobj = nullptr;
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"generatedSureGreater",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (generatedSureGreater*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_generatedSureGreater_getString'", NULL);
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
	tolua_error(tolua_S,"#ferror in function 'lua_generatedSureGreater_getString'.",&tolua_err);
#endif
	return 0;
}
int lua_generatedSureGreater_setHorizontalAlignment(lua_State* tolua_S)
{
	generatedSureGreater* cobj = nullptr;
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"generatedSureGreater",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (generatedSureGreater*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_generatedSureGreater_setHorizontalAlignment'", NULL);
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
	tolua_error(tolua_S,"#ferror in function 'lua_generatedSureGreater_setHorizontalAlignment'.",&tolua_err);
#endif
	return 0;
}
int lua_generatedSureGreater_setVerticalAlignment(lua_State* tolua_S)
{
	generatedSureGreater* cobj = nullptr;
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"generatedSureGreater",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (generatedSureGreater*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_generatedSureGreater_setVerticalAlignment'", NULL);
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
	tolua_error(tolua_S,"#ferror in function 'lua_generatedSureGreater_setVerticalAlignment'.",&tolua_err);
#endif
	return 0;
}
int lua_generatedSureGreater_setLineBreakWithoutSpace(lua_State* tolua_S)
{
	generatedSureGreater* cobj = nullptr;
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"generatedSureGreater",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (generatedSureGreater*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_generatedSureGreater_setLineBreakWithoutSpace'", NULL);
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
	tolua_error(tolua_S,"#ferror in function 'lua_generatedSureGreater_setLineBreakWithoutSpace'.",&tolua_err);
#endif
	return 0;
}
int lua_generatedSureGreater_setpreservingSpecifed(lua_State* tolua_S)
{
	generatedSureGreater* cobj = nullptr;
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"generatedSureGreater",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (generatedSureGreater*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_generatedSureGreater_setpreservingSpecifed'", NULL);
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
			cobj->setpreservingSpecifed(arg1);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setpreservingSpecifed",argc, 1);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_generatedSureGreater_setpreservingSpecifed'.",&tolua_err);
#endif
	return 0;
}
int lua_generatedSureGreater_setSystemFontSize(lua_State* tolua_S)
{
	generatedSureGreater* cobj = nullptr;
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"generatedSureGreater",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (generatedSureGreater*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_generatedSureGreater_setSystemFontSize'", NULL);
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
	tolua_error(tolua_S,"#ferror in function 'lua_generatedSureGreater_setSystemFontSize'.",&tolua_err);
#endif
	return 0;
}
int lua_generatedSureGreater_setColor(lua_State* tolua_S)
{
	generatedSureGreater* cobj = nullptr;
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"generatedSureGreater",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (generatedSureGreater*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_generatedSureGreater_setColor'", NULL);
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
	tolua_error(tolua_S,"#ferror in function 'lua_generatedSureGreater_setColor'.",&tolua_err);
#endif
	return 0;
}
int lua_generatedSureGreater_getColor(lua_State* tolua_S)
{
	generatedSureGreater* cobj = nullptr;
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"generatedSureGreater",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (generatedSureGreater*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_generatedSureGreater_getColor'", NULL);
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
	tolua_error(tolua_S,"#ferror in function 'lua_generatedSureGreater_getColor'.",&tolua_err);
#endif
	return 0;
}
int lua_generatedSureGreater_setbeganMemberwiseCeases(lua_State* tolua_S)
{
	generatedSureGreater* cobj = nullptr;
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"generatedSureGreater",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (generatedSureGreater*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_generatedSureGreater_setbeganMemberwiseCeases'", NULL);
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
			cobj->setbeganMemberwiseCeases(arg1);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setbeganMemberwiseCeases",argc, 1);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_generatedSureGreater_setbeganMemberwiseCeases'.",&tolua_err);
#endif
	return 0;
}
int lua_generatedSureGreater_setrepeatedlyDealProvided(lua_State* tolua_S)
{
	generatedSureGreater* cobj = nullptr;
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"generatedSureGreater",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (generatedSureGreater*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_generatedSureGreater_setrepeatedlyDealProvided'", NULL);
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
			cobj->setrepeatedlyDealProvided(arg1);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setrepeatedlyDealProvided",argc, 1);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_generatedSureGreater_setrepeatedlyDealProvided'.",&tolua_err);
#endif
	return 0;
}
int lua_generatedSureGreater_setinstantiationPeppers(lua_State* tolua_S)
{
	generatedSureGreater* cobj = nullptr;
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"generatedSureGreater",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (generatedSureGreater*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_generatedSureGreater_setinstantiationPeppers'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		do 
		{
			cocos2d::Label* arg0;
			ok &= luaval_to_object<cocos2d::Label>(tolua_S, 2, "cc.Label",&arg0, "lua_generatedSureGreater_setinstantiationPeppers");
			if (!ok) { break; }
			cobj->setinstantiationPeppers(arg0);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setinstantiationPeppers",argc, 1);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_generatedSureGreater_setinstantiationPeppers'.",&tolua_err);
#endif
	return 0;
}
int lua_generatedSureGreater_getinstantiationPeppers(lua_State* tolua_S)
{
	generatedSureGreater* cobj = nullptr;
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"generatedSureGreater",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (generatedSureGreater*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_generatedSureGreater_getinstantiationPeppers'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 0)
	{
		do 
		{
			cocos2d::Label* ret = cobj->getinstantiationPeppers();
			object_to_luaval<cocos2d::Label>(tolua_S, "cc.Node",(cocos2d::Label*)ret);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "getinstantiationPeppers",argc, 1);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_generatedSureGreater_getinstantiationPeppers'.",&tolua_err);
#endif
	return 0;
}
int lua_register_cocos2dx_generatedSureGreater(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"generatedSureGreater");
	tolua_cclass(tolua_S,"generatedSureGreater","generatedSureGreater","cc.Node",NULL);
		tolua_beginmodule(tolua_S,"generatedSureGreater");
			tolua_function(tolua_S, "create", lua_generatedSureGreater_create);
		
			tolua_function(tolua_S, "setAdditionalKerning", lua_generatedSureGreater_setAdditionalKerning);
			tolua_function(tolua_S, "setDimensions", lua_generatedSureGreater_setDimensions);
			tolua_function(tolua_S, "setString", lua_generatedSureGreater_setString);
			tolua_function(tolua_S, "getString", lua_generatedSureGreater_getString);
			tolua_function(tolua_S, "setHorizontalAlignment", lua_generatedSureGreater_setHorizontalAlignment);
			tolua_function(tolua_S, "setVerticalAlignment", lua_generatedSureGreater_setVerticalAlignment);
			tolua_function(tolua_S, "setLineBreakWithoutSpace", lua_generatedSureGreater_setLineBreakWithoutSpace);
			tolua_function(tolua_S, "setpreservingSpecifed", lua_generatedSureGreater_setpreservingSpecifed);
			tolua_function(tolua_S, "setSystemFontSize", lua_generatedSureGreater_setSystemFontSize);
			tolua_function(tolua_S, "setColor", lua_generatedSureGreater_setColor);
			tolua_function(tolua_S, "getColor", lua_generatedSureGreater_getColor);
			tolua_function(tolua_S, "setbeganMemberwiseCeases", lua_generatedSureGreater_setbeganMemberwiseCeases);
			tolua_function(tolua_S, "setrepeatedlyDealProvided", lua_generatedSureGreater_setrepeatedlyDealProvided);
			tolua_function(tolua_S, "setinstantiationPeppers", lua_generatedSureGreater_setinstantiationPeppers);
			tolua_function(tolua_S, "getinstantiationPeppers", lua_generatedSureGreater_getinstantiationPeppers);
		tolua_endmodule(tolua_S);
    return 1;
}
#endif    