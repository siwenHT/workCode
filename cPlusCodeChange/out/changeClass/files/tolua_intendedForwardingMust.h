
extern "C" {
#include "tolua_fix.h"
}
#include <map>
#include <string>
#include "cocos2d.h"
#include "CCLuaEngine.h"
#include "cocos-ext.h"
#include "intendedForwardingMust.h"
using namespace cocos2d;
using namespace cocos2d::extension;
TOLUA_API int  tolua_intendedForwardingMust_open (lua_State* tolua_S);
#ifdef __cplusplus
static int tolua_collect_intendedForwardingMust (lua_State* tolua_S)
{
 intendedForwardingMust* self = (intendedForwardingMust*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}
#endif
static void tolua_reg_types1 (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"intendedForwardingMust");
 tolua_usertype(tolua_S,"AppMsg");
 tolua_usertype(tolua_S,"threedConswhatReplaces");
 tolua_usertype(tolua_S,"CCObject");
 tolua_usertype(tolua_S,"becomeAlgorithms");
 tolua_usertype(tolua_S,"implementContainingMeans");
}
#ifndef TOLUA_DISABLE_tolua_get_intendedForwardingMust_cSocket_ptr
static int tolua_get_intendedForwardingMust_cSocket_ptr(lua_State* tolua_S)
{
  intendedForwardingMust* self = (intendedForwardingMust*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cSocket'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->cSocket,"threedConswhatReplaces");
 return 1;
}
#endif 
#ifndef TOLUA_DISABLE_tolua_set_intendedForwardingMust_cSocket_ptr
static int tolua_set_intendedForwardingMust_cSocket_ptr(lua_State* tolua_S)
{
  intendedForwardingMust* self = (intendedForwardingMust*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cSocket'",NULL);
  if (!tolua_isusertype(tolua_S,2,"threedConswhatReplaces",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->cSocket = ((threedConswhatReplaces*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif 
#ifndef TOLUA_DISABLE_tolua_intendedForwardingMust_intendedForwardingMust_getInstance00
static int tolua_intendedForwardingMust_intendedForwardingMust_getInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"intendedForwardingMust",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   intendedForwardingMust* tolua_ret = (intendedForwardingMust*)  intendedForwardingMust::getInstance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"intendedForwardingMust");
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
#ifndef TOLUA_DISABLE_tolua_intendedForwardingMust_intendedForwardingMust_new00
static int tolua_intendedForwardingMust_intendedForwardingMust_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"intendedForwardingMust",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   intendedForwardingMust* tolua_ret = (intendedForwardingMust*)  Mtolua_new((intendedForwardingMust)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"intendedForwardingMust");
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
#ifndef TOLUA_DISABLE_tolua_intendedForwardingMust_intendedForwardingMust_new00_local
static int tolua_intendedForwardingMust_intendedForwardingMust_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"intendedForwardingMust",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   intendedForwardingMust* tolua_ret = (intendedForwardingMust*)  Mtolua_new((intendedForwardingMust)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"intendedForwardingMust");
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
#ifndef TOLUA_DISABLE_tolua_intendedForwardingMust_intendedForwardingMust_delete00
static int tolua_intendedForwardingMust_intendedForwardingMust_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"intendedForwardingMust",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  intendedForwardingMust* self = (intendedForwardingMust*)  tolua_tousertype(tolua_S,1,0);
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
#ifndef TOLUA_DISABLE_tolua_intendedForwardingMust_intendedForwardingMust_specifiedVarying00
static int tolua_intendedForwardingMust_intendedForwardingMust_specifiedVarying00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"intendedForwardingMust",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  intendedForwardingMust* self = (intendedForwardingMust*)  tolua_tousertype(tolua_S,1,0);
  const char* ip = ((const char*)  tolua_tostring(tolua_S,2,0));
  int poush = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'specifiedVarying'", NULL);
#endif
  {
   int tolua_ret = (int)  self->specifiedVarying(ip,poush);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'specifiedVarying'.",&tolua_err);
 return 0;
#endif
}
#endif 
#ifndef TOLUA_DISABLE_tolua_intendedForwardingMust_intendedForwardingMust_intvaluesIteratorStyle00
static int tolua_intendedForwardingMust_intendedForwardingMust_intvaluesIteratorStyle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"intendedForwardingMust",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"implementContainingMeans",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  intendedForwardingMust* self = (intendedForwardingMust*)  tolua_tousertype(tolua_S,1,0);
  implementContainingMeans* luaBuff = ((implementContainingMeans*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'intvaluesIteratorStyle'", NULL);
#endif
  {
   self->intvaluesIteratorStyle(*luaBuff);
  }
 }
 lua_settop(tolua_S, 1);
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'intvaluesIteratorStyle'.",&tolua_err);
 return 0;
#endif
}
#endif 
#ifndef TOLUA_DISABLE_tolua_intendedForwardingMust_intendedForwardingMust_generatesHiddenMust00
static int tolua_intendedForwardingMust_intendedForwardingMust_generatesHiddenMust00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"intendedForwardingMust",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  intendedForwardingMust* self = (intendedForwardingMust*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'generatesHiddenMust'", NULL);
#endif
  {
   self->generatesHiddenMust();
  }
 }
 lua_settop(tolua_S, 1);
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'generatesHiddenMust'.",&tolua_err);
 return 0;
#endif
}
#endif 
#ifndef TOLUA_DISABLE_tolua_intendedForwardingMust_intendedForwardingMust_operatingDefinesPredicted00
static int tolua_intendedForwardingMust_intendedForwardingMust_operatingDefinesPredicted00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"intendedForwardingMust",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  intendedForwardingMust* self = (intendedForwardingMust*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operatingDefinesPredicted'", NULL);
#endif
  {
   self->operatingDefinesPredicted();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'operatingDefinesPredicted'.",&tolua_err);
 return 0;
#endif
}
#endif 
#ifndef TOLUA_DISABLE_tolua_intendedForwardingMust_intendedForwardingMust_typedefsCeaseSuccessful00
static int tolua_intendedForwardingMust_intendedForwardingMust_typedefsCeaseSuccessful00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"intendedForwardingMust",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"becomeAlgorithms",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  intendedForwardingMust* self = (intendedForwardingMust*)  tolua_tousertype(tolua_S,1,0);
  char* szFunName = ((char*)  tolua_tostring(tolua_S,2,0));
  becomeAlgorithms* pInParam = ((becomeAlgorithms*)  tolua_tousertype(tolua_S,3,0));
  int nInNum = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'typedefsCeaseSuccessful'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->typedefsCeaseSuccessful(szFunName,pInParam,nInNum);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'typedefsCeaseSuccessful'.",&tolua_err);
 return 0;
#endif
}
#endif 
static int tolua_intendedForwardingMust_intendedForwardingMust_setsourceRequestedEnough(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"intendedForwardingMust",0,&tolua_err) ||
		!tolua_isboolean(tolua_S,2,0,&tolua_err)
		)
		goto tolua_lerror;
	else
#endif
	{
		intendedForwardingMust* self = (intendedForwardingMust*)  tolua_tousertype(tolua_S,1,0);
		bool isShow = tolua_toboolean(tolua_S, 2, true);
#ifndef TOLUA_RELEASE
		if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setsourceRequestedEnough'", NULL);
#endif
		{
			self->setsourceRequestedEnough(isShow);
		}
	}
	return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'setsourceRequestedEnough'.",&tolua_err);
	return 0;
#endif
}
TOLUA_API int tolua_intendedForwardingMust_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types1(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"intendedForwardingMust","intendedForwardingMust","CCObject",tolua_collect_intendedForwardingMust);
  #else
  tolua_cclass(tolua_S,"intendedForwardingMust","intendedForwardingMust","CCObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"intendedForwardingMust");
   tolua_variable(tolua_S,"cSocket",tolua_get_intendedForwardingMust_cSocket_ptr,tolua_set_intendedForwardingMust_cSocket_ptr);
   tolua_function(tolua_S,"getInstance",tolua_intendedForwardingMust_intendedForwardingMust_getInstance00);
   tolua_function(tolua_S,"new",tolua_intendedForwardingMust_intendedForwardingMust_new00);
   tolua_function(tolua_S,"new_local",tolua_intendedForwardingMust_intendedForwardingMust_new00_local);
   tolua_function(tolua_S,".call",tolua_intendedForwardingMust_intendedForwardingMust_new00_local);
   tolua_function(tolua_S,"delete",tolua_intendedForwardingMust_intendedForwardingMust_delete00);
   tolua_function(tolua_S,"specifiedVarying",tolua_intendedForwardingMust_intendedForwardingMust_specifiedVarying00);
   tolua_function(tolua_S,"intvaluesIteratorStyle",tolua_intendedForwardingMust_intendedForwardingMust_intvaluesIteratorStyle00);
   
   tolua_function(tolua_S,"generatesHiddenMust",tolua_intendedForwardingMust_intendedForwardingMust_generatesHiddenMust00);
   
   
   
   tolua_function(tolua_S,"operatingDefinesPredicted",tolua_intendedForwardingMust_intendedForwardingMust_operatingDefinesPredicted00);
   
   
   tolua_function(tolua_S,"typedefsCeaseSuccessful",tolua_intendedForwardingMust_intendedForwardingMust_typedefsCeaseSuccessful00);
   tolua_function(tolua_S,"setsourceRequestedEnough",tolua_intendedForwardingMust_intendedForwardingMust_setsourceRequestedEnough);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}
#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_intendedForwardingMust (lua_State* tolua_S) {
 return tolua_intendedForwardingMust_open(tolua_S);
};
#endif
