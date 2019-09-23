
extern "C" {
#include "tolua_fix.h"
}
#include <map>
#include <string>
#include "cocos2d.h"
#include "CCLuaEngine.h"
#include "cocos-ext.h"
#include "andqueryApplies.h"
using namespace cocos2d;
using namespace cocos2d::extension;
TOLUA_API int  tolua_andqueryApplies_open (lua_State* tolua_S);
#ifdef __cplusplus
static int tolua_collect_andqueryApplies (lua_State* tolua_S)
{
 andqueryApplies* self = (andqueryApplies*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}
#endif
static void tolua_reg_types1 (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"andqueryApplies");
 tolua_usertype(tolua_S,"AppMsg");
 tolua_usertype(tolua_S,"difficultDoeth");
 tolua_usertype(tolua_S,"CCObject");
 tolua_usertype(tolua_S,"likelyDescribeField");
 tolua_usertype(tolua_S,"yieldsAnswerAlways");
}
#ifndef TOLUA_DISABLE_tolua_get_andqueryApplies_cSocket_ptr
static int tolua_get_andqueryApplies_cSocket_ptr(lua_State* tolua_S)
{
  andqueryApplies* self = (andqueryApplies*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cSocket'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->cSocket,"difficultDoeth");
 return 1;
}
#endif 
#ifndef TOLUA_DISABLE_tolua_set_andqueryApplies_cSocket_ptr
static int tolua_set_andqueryApplies_cSocket_ptr(lua_State* tolua_S)
{
  andqueryApplies* self = (andqueryApplies*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cSocket'",NULL);
  if (!tolua_isusertype(tolua_S,2,"difficultDoeth",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->cSocket = ((difficultDoeth*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif 
#ifndef TOLUA_DISABLE_tolua_andqueryApplies_andqueryApplies_getInstance00
static int tolua_andqueryApplies_andqueryApplies_getInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"andqueryApplies",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   andqueryApplies* tolua_ret = (andqueryApplies*)  andqueryApplies::getInstance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"andqueryApplies");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInstance'.",&tolua_err);
 return 0;
#endif
}
#endif 
#ifndef TOLUA_DISABLE_tolua_andqueryApplies_andqueryApplies_new00
static int tolua_andqueryApplies_andqueryApplies_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"andqueryApplies",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   andqueryApplies* tolua_ret = (andqueryApplies*)  Mtolua_new((andqueryApplies)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"andqueryApplies");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif 
#ifndef TOLUA_DISABLE_tolua_andqueryApplies_andqueryApplies_new00_local
static int tolua_andqueryApplies_andqueryApplies_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"andqueryApplies",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   andqueryApplies* tolua_ret = (andqueryApplies*)  Mtolua_new((andqueryApplies)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"andqueryApplies");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif 
#ifndef TOLUA_DISABLE_tolua_andqueryApplies_andqueryApplies_delete00
static int tolua_andqueryApplies_andqueryApplies_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"andqueryApplies",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  andqueryApplies* self = (andqueryApplies*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 lua_settop(tolua_S, 1);
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif 
#ifndef TOLUA_DISABLE_tolua_andqueryApplies_andqueryApplies_destructorDoesSplit00
static int tolua_andqueryApplies_andqueryApplies_destructorDoesSplit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"andqueryApplies",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  andqueryApplies* self = (andqueryApplies*)  tolua_tousertype(tolua_S,1,0);
  const char* ip = ((const char*)  tolua_tostring(tolua_S,2,0));
  int poush = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destructorDoesSplit'", NULL);
#endif
  {
   int tolua_ret = (int)  self->destructorDoesSplit(ip,poush);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'destructorDoesSplit'.",&tolua_err);
 return 0;
#endif
}
#endif 
#ifndef TOLUA_DISABLE_tolua_andqueryApplies_andqueryApplies_updateSelectsButton00
static int tolua_andqueryApplies_andqueryApplies_updateSelectsButton00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"andqueryApplies",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"yieldsAnswerAlways",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  andqueryApplies* self = (andqueryApplies*)  tolua_tousertype(tolua_S,1,0);
  yieldsAnswerAlways* luaBuff = ((yieldsAnswerAlways*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'updateSelectsButton'", NULL);
#endif
  {
   self->updateSelectsButton(*luaBuff);
  }
 }
 lua_settop(tolua_S, 1);
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'updateSelectsButton'.",&tolua_err);
 return 0;
#endif
}
#endif 
#ifndef TOLUA_DISABLE_tolua_andqueryApplies_andqueryApplies_aspectsTreeRequired00
static int tolua_andqueryApplies_andqueryApplies_aspectsTreeRequired00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"andqueryApplies",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  andqueryApplies* self = (andqueryApplies*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'aspectsTreeRequired'", NULL);
#endif
  {
   self->aspectsTreeRequired();
  }
 }
 lua_settop(tolua_S, 1);
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'aspectsTreeRequired'.",&tolua_err);
 return 0;
#endif
}
#endif 
#ifndef TOLUA_DISABLE_tolua_andqueryApplies_andqueryApplies_stillIndependentlyArgs00
static int tolua_andqueryApplies_andqueryApplies_stillIndependentlyArgs00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"andqueryApplies",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  andqueryApplies* self = (andqueryApplies*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stillIndependentlyArgs'", NULL);
#endif
  {
   self->stillIndependentlyArgs();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stillIndependentlyArgs'.",&tolua_err);
 return 0;
#endif
}
#endif 
#ifndef TOLUA_DISABLE_tolua_andqueryApplies_andqueryApplies_consistentExclusiveKnow00
static int tolua_andqueryApplies_andqueryApplies_consistentExclusiveKnow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"andqueryApplies",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"likelyDescribeField",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  andqueryApplies* self = (andqueryApplies*)  tolua_tousertype(tolua_S,1,0);
  char* szFunName = ((char*)  tolua_tostring(tolua_S,2,0));
  likelyDescribeField* pInParam = ((likelyDescribeField*)  tolua_tousertype(tolua_S,3,0));
  int nInNum = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'consistentExclusiveKnow'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->consistentExclusiveKnow(szFunName,pInParam,nInNum);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'consistentExclusiveKnow'.",&tolua_err);
 return 0;
#endif
}
#endif 
static int tolua_andqueryApplies_andqueryApplies_setbracketsBodyResulting(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"andqueryApplies",0,&tolua_err) ||
		!tolua_isboolean(tolua_S,2,0,&tolua_err)
		)
		goto tolua_lerror;
	else
#endif
	{
		andqueryApplies* self = (andqueryApplies*)  tolua_tousertype(tolua_S,1,0);
		bool isShow = tolua_toboolean(tolua_S, 2, true);
#ifndef TOLUA_RELEASE
		if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setbracketsBodyResulting'", NULL);
#endif
		{
			self->setbracketsBodyResulting(isShow);
		}
	}
	return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'setbracketsBodyResulting'.",&tolua_err);
	return 0;
#endif
}
TOLUA_API int tolua_andqueryApplies_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types1(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"andqueryApplies","andqueryApplies","CCObject",tolua_collect_andqueryApplies);
  #else
  tolua_cclass(tolua_S,"andqueryApplies","andqueryApplies","CCObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"andqueryApplies");
   tolua_variable(tolua_S,"cSocket",tolua_get_andqueryApplies_cSocket_ptr,tolua_set_andqueryApplies_cSocket_ptr);
   tolua_function(tolua_S,"getInstance",tolua_andqueryApplies_andqueryApplies_getInstance00);
   tolua_function(tolua_S,"new",tolua_andqueryApplies_andqueryApplies_new00);
   tolua_function(tolua_S,"new_local",tolua_andqueryApplies_andqueryApplies_new00_local);
   tolua_function(tolua_S,".call",tolua_andqueryApplies_andqueryApplies_new00_local);
   tolua_function(tolua_S,"delete",tolua_andqueryApplies_andqueryApplies_delete00);
   tolua_function(tolua_S,"destructorDoesSplit",tolua_andqueryApplies_andqueryApplies_destructorDoesSplit00);
   tolua_function(tolua_S,"updateSelectsButton",tolua_andqueryApplies_andqueryApplies_updateSelectsButton00);
   
   tolua_function(tolua_S,"aspectsTreeRequired",tolua_andqueryApplies_andqueryApplies_aspectsTreeRequired00);
   
   
   
   tolua_function(tolua_S,"stillIndependentlyArgs",tolua_andqueryApplies_andqueryApplies_stillIndependentlyArgs00);
   
   
   tolua_function(tolua_S,"consistentExclusiveKnow",tolua_andqueryApplies_andqueryApplies_consistentExclusiveKnow00);
   tolua_function(tolua_S,"setbracketsBodyResulting",tolua_andqueryApplies_andqueryApplies_setbracketsBodyResulting);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}
#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_andqueryApplies (lua_State* tolua_S) {
 return tolua_andqueryApplies_open(tolua_S);
};
#endif
