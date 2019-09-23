
extern "C" {
#include "tolua_fix.h"
}
#include <map>
#include <string>
#include "cocos2d.h"
#include "CCLuaEngine.h"
#include "implementContainingMeans.h"
#include "cocos-ext.h"
using namespace cocos2d;
using namespace cocos2d::extension;
TOLUA_API int  tolua_implementContainingMeans_open (lua_State* tolua_S);
#ifdef __cplusplus
static int tolua_collect_startingCompile (lua_State* tolua_S)
{
 startingCompile* self = (startingCompile*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}
static int tolua_collect_implementContainingMeans (lua_State* tolua_S)
{
 implementContainingMeans* self = (implementContainingMeans*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}
#endif
static void tolua_reg_types (lua_State* tolua_S)
{
 
 tolua_usertype(tolua_S,"AppMsg");
 tolua_usertype(tolua_S,"startingCompile");
 tolua_usertype(tolua_S,"std::vector<int>");
 tolua_usertype(tolua_S,"implementContainingMeans");
}
#ifndef TOLUA_DISABLE_tolua_implementContainingMeans_implementContainingMeans_new00
static int tolua_implementContainingMeans_implementContainingMeans_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"implementContainingMeans",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   implementContainingMeans* tolua_ret = (implementContainingMeans*)  Mtolua_new((implementContainingMeans)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"implementContainingMeans");
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
#ifndef TOLUA_DISABLE_tolua_implementContainingMeans_implementContainingMeans_new00_local
static int tolua_implementContainingMeans_implementContainingMeans_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"implementContainingMeans",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   implementContainingMeans* tolua_ret = (implementContainingMeans*)  Mtolua_new((implementContainingMeans)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"implementContainingMeans");
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
#ifndef TOLUA_DISABLE_tolua_implementContainingMeans_implementContainingMeans_delete00
static int tolua_implementContainingMeans_implementContainingMeans_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"implementContainingMeans",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  implementContainingMeans* self = (implementContainingMeans*)  tolua_tousertype(tolua_S,1,0);
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
#ifndef TOLUA_DISABLE_tolua_implementContainingMeans_implementContainingMeans_pushBool00
static int tolua_implementContainingMeans_implementContainingMeans_pushBool00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"implementContainingMeans",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  implementContainingMeans* self = (implementContainingMeans*)  tolua_tousertype(tolua_S,1,0);
  int flag = tolua_toboolean(tolua_S,2,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pushBool'", NULL);
#endif
  {
   self->pushBool(flag >= 0?true:false);
  }
 }
 lua_settop(tolua_S, 1);
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pushBool'.",&tolua_err);
 return 0;
#endif
}
#endif 
#ifndef TOLUA_DISABLE_tolua_implementContainingMeans_implementContainingMeans_pushInt00
static int tolua_implementContainingMeans_implementContainingMeans_pushInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"implementContainingMeans",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  implementContainingMeans* self = (implementContainingMeans*)  tolua_tousertype(tolua_S,1,0);
  int value = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pushInt'", NULL);
#endif
  {
   self->pushInt(value);
  }
 }
 lua_settop(tolua_S, 1);
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pushInt'.",&tolua_err);
 return 0;
#endif
}
#endif 
#ifndef TOLUA_DISABLE_tolua_implementContainingMeans_implementContainingMeans_pushChar00
static int tolua_implementContainingMeans_implementContainingMeans_pushChar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"implementContainingMeans",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  implementContainingMeans* self = (implementContainingMeans*)  tolua_tousertype(tolua_S,1,0);
  char value = ((char)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pushChar'", NULL);
#endif
  {
   self->pushChar(value);
  }
 }
 lua_settop(tolua_S, 1);
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pushChar'.",&tolua_err);
 return 0;
#endif
}
#endif 
#ifndef TOLUA_DISABLE_tolua_implementContainingMeans_implementContainingMeans_pushUnChar00
static int tolua_implementContainingMeans_implementContainingMeans_pushUnChar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"implementContainingMeans",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  implementContainingMeans* self = (implementContainingMeans*)  tolua_tousertype(tolua_S,1,0);
  char value = ((char)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pushUChar'", NULL);
#endif
  {
   self->pushUChar(value);
  }
 }
 lua_settop(tolua_S, 1);
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pushUChar'.",&tolua_err);
 return 0;
#endif
}
#endif 
#ifndef TOLUA_DISABLE_tolua_implementContainingMeans_implementContainingMeans_pushShort00
static int tolua_implementContainingMeans_implementContainingMeans_pushShort00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"implementContainingMeans",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  implementContainingMeans* self = (implementContainingMeans*)  tolua_tousertype(tolua_S,1,0);
  short value = ((short)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pushShort'", NULL);
#endif
  {
   self->pushShort(value);
  }
 }
 lua_settop(tolua_S, 1);
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pushShort'.",&tolua_err);
 return 0;
#endif
}
#endif 
#ifndef TOLUA_DISABLE_tolua_implementContainingMeans_implementContainingMeans_whenStoringContrpasses00
static int tolua_implementContainingMeans_implementContainingMeans_whenStoringContrpasses00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"implementContainingMeans",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  implementContainingMeans* self = (implementContainingMeans*)  tolua_tousertype(tolua_S,1,0);
  double value = ((double)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'whenStoringContrpasses'", NULL);
#endif
  {
   self->whenStoringContrpasses(value);
  }
 }
 lua_settop(tolua_S, 1);
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'whenStoringContrpasses'.",&tolua_err);
 return 0;
#endif
}
#endif 
#ifndef TOLUA_DISABLE_tolua_implementContainingMeans_implementContainingMeans_pushChars00
static int tolua_implementContainingMeans_implementContainingMeans_pushChars00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"implementContainingMeans",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  implementContainingMeans* self = (implementContainingMeans*)  tolua_tousertype(tolua_S,1,0);
  const char* str = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pushChars'", NULL);
#endif
  {
   self->pushChars(str);
  }
 }
 lua_settop(tolua_S, 1);
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pushChars'.",&tolua_err);
 return 0;
#endif
}
#endif 
#ifndef TOLUA_DISABLE_tolua_implementContainingMeans_implementContainingMeans_pushString00
static int tolua_implementContainingMeans_implementContainingMeans_pushString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"implementContainingMeans",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  implementContainingMeans* self = (implementContainingMeans*)  tolua_tousertype(tolua_S,1,0);
  std::string str = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pushString'", NULL);
#endif
  {
   self->pushString(str);
   tolua_pushcppstring(tolua_S,(const char*)str);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pushString'.",&tolua_err);
 return 0;
#endif
}
#endif 
#ifndef TOLUA_DISABLE_tolua_implementContainingMeans_implementContainingMeans_pushData00
static int tolua_implementContainingMeans_implementContainingMeans_pushData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"implementContainingMeans",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  implementContainingMeans* self = (implementContainingMeans*)  tolua_tousertype(tolua_S,1,0);
  void* pData = ((void*)  tolua_touserdata(tolua_S,2,0));
  int lengh = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pushData'", NULL);
#endif
  {
   self->pushData(pData,lengh);
  }
 }
 lua_settop(tolua_S, 1);
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pushData'.",&tolua_err);
 return 0;
#endif
}
#endif 
#ifndef TOLUA_DISABLE_tolua_implementContainingMeans_implementContainingMeans_popBool00
static int tolua_implementContainingMeans_implementContainingMeans_popBool00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"implementContainingMeans",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  implementContainingMeans* self = (implementContainingMeans*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'popBool'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->popBool();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'popBool'.",&tolua_err);
 return 0;
#endif
}
#endif 
#ifndef TOLUA_DISABLE_tolua_implementContainingMeans_implementContainingMeans_popInt00
static int tolua_implementContainingMeans_implementContainingMeans_popInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"implementContainingMeans",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  implementContainingMeans* self = (implementContainingMeans*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'popInt'", NULL);
#endif
  {
   int tolua_ret = (int)  self->popInt();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'popInt'.",&tolua_err);
 return 0;
#endif
}
#endif 
#ifndef TOLUA_DISABLE_tolua_implementContainingMeans_implementContainingMeans_popChar00
static int tolua_implementContainingMeans_implementContainingMeans_popChar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"implementContainingMeans",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  implementContainingMeans* self = (implementContainingMeans*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'popChar'", NULL);
#endif
  {
   char tolua_ret = (char)  self->popChar();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'popChar'.",&tolua_err);
 return 0;
#endif
}
#endif 
#ifndef TOLUA_DISABLE_tolua_implementContainingMeans_implementContainingMeans_popUnChar00
static int tolua_implementContainingMeans_implementContainingMeans_popUnChar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"implementContainingMeans",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  implementContainingMeans* self = (implementContainingMeans*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'popUChar'", NULL);
#endif
  {
   unsigned char tolua_ret = (unsigned char)  self->popUChar();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'popUChar'.",&tolua_err);
 return 0;
#endif
}
#endif 
#ifndef TOLUA_DISABLE_tolua_implementContainingMeans_implementContainingMeans_popUnShort00
static int tolua_implementContainingMeans_implementContainingMeans_popUnShort00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"implementContainingMeans",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  implementContainingMeans* self = (implementContainingMeans*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'popUShort'", NULL);
#endif
  {
   unsigned short tolua_ret = (unsigned short)  self->popUShort();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'popUShort'.",&tolua_err);
 return 0;
#endif
}
#endif 
#ifndef TOLUA_DISABLE_tolua_implementContainingMeans_implementContainingMeans_popShort00
static int tolua_implementContainingMeans_implementContainingMeans_popShort00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"implementContainingMeans",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  implementContainingMeans* self = (implementContainingMeans*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'popShort'", NULL);
#endif
  {
   short tolua_ret = (short)  self->popShort();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'popShort'.",&tolua_err);
 return 0;
#endif
}
#endif 
#ifndef TOLUA_DISABLE_tolua_implementContainingMeans_implementContainingMeans_popFloat00
static int tolua_implementContainingMeans_implementContainingMeans_popFloat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"implementContainingMeans",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  implementContainingMeans* self = (implementContainingMeans*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'popFloat'", NULL);
#endif
  {
   float tolua_ret = (float)  self->popFloat();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'popFloat'.",&tolua_err);
 return 0;
#endif
}
#endif 
#ifndef TOLUA_DISABLE_tolua_implementContainingMeans_implementContainingMeans_popDouble00
static int tolua_implementContainingMeans_implementContainingMeans_popDouble00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"implementContainingMeans",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  implementContainingMeans* self = (implementContainingMeans*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'popDouble'", NULL);
#endif
  {
   double tolua_ret = (double)  self->popDouble();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'popDouble'.",&tolua_err);
 return 0;
#endif
}
#endif 
#ifndef TOLUA_DISABLE_tolua_implementContainingMeans_implementContainingMeans_pointerwhenTopicsPeople00
static int tolua_implementContainingMeans_implementContainingMeans_pointerwhenTopicsPeople00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"implementContainingMeans",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  implementContainingMeans* self = (implementContainingMeans*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pointerwhenTopicsPeople'", NULL);
#endif
  {
   long long tolua_ret = (long long)  self->pointerwhenTopicsPeople();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pointerwhenTopicsPeople'.",&tolua_err);
 return 0;
#endif
}
#endif 
#ifndef TOLUA_DISABLE_tolua_implementContainingMeans_implementContainingMeans_clear00
static int tolua_implementContainingMeans_implementContainingMeans_clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"implementContainingMeans",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  implementContainingMeans* self = (implementContainingMeans*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clear'", NULL);
#endif
  {
   self->clear();
  }
 }
 lua_settop(tolua_S, 1);
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clear'.",&tolua_err);
 return 0;
#endif
}
#endif 
#ifndef TOLUA_DISABLE_tolua_implementContainingMeans_implementContainingMeans_popString00
static int tolua_implementContainingMeans_implementContainingMeans_popString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"implementContainingMeans",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  implementContainingMeans* self = (implementContainingMeans*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'popString'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->popString();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'popString'.",&tolua_err);
 return 0;
#endif
}
#endif 
#ifndef TOLUA_DISABLE_tolua_implementContainingMeans_implementContainingMeans_popInts00
static int tolua_implementContainingMeans_implementContainingMeans_popInts00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"implementContainingMeans",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"std::vector<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  implementContainingMeans* self = (implementContainingMeans*)  tolua_tousertype(tolua_S,1,0);
  std::vector<int>* ints = ((std::vector<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'popInts'", NULL);
#endif
  {
   self->popInts(*ints);
  }
 }
 lua_settop(tolua_S, 1);
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'popInts'.",&tolua_err);
 return 0;
#endif
}
#endif 
#ifndef tolua_implementContainingMeans_implementContainingMeans_getdifferentlyCopiedSpace
static int tolua_implementContainingMeans_implementContainingMeans_getdifferentlyCopiedSpace(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"implementContainingMeans",0,&tolua_err) ||
		!tolua_isnumber(tolua_S,2,0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,3,&tolua_err)
		)
		goto tolua_lerror;
	else
#endif
	{
		implementContainingMeans* self = (implementContainingMeans*)  tolua_tousertype(tolua_S,1,0);
		short num = ((short)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
		if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getdifferentlyCopiedSpace'", NULL);
#endif
		{
			const char* ret = self->getdifferentlyCopiedSpace(num);
			lua_pushlightuserdata(tolua_S, (void*)ret);
			return 1;
		}
	}
	tolua_error(tolua_S,"#ferror in function 'getdifferentlyCopiedSpace'.",&tolua_err);
	return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'getdifferentlyCopiedSpace'.",&tolua_err);
	return 0;
#endif
}
#endif 
#ifndef TOLUA_DISABLE_tolua_implementContainingMeans_startingCompile_delete00
static int tolua_implementContainingMeans_startingCompile_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"startingCompile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  startingCompile* self = (startingCompile*)  tolua_tousertype(tolua_S,1,0);
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
#ifndef TOLUA_DISABLE_tolua_implementContainingMeans_startingCompile_instance00
static int tolua_implementContainingMeans_startingCompile_instance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"startingCompile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   startingCompile* tolua_ret = (startingCompile*)  startingCompile::instance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"startingCompile");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'instance'.",&tolua_err);
 return 0;
#endif
}
#endif 
#ifndef TOLUA_DISABLE_tolua_implementContainingMeans_startingCompile_getlvalueBehavesProcessing00
static int tolua_implementContainingMeans_startingCompile_getlvalueBehavesProcessing00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"startingCompile",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  startingCompile* self = (startingCompile*)  tolua_tousertype(tolua_S,1,0);
  int eventID = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getlvalueBehavesProcessing'", NULL);
#endif
  {
   implementContainingMeans& tolua_ret = (implementContainingMeans&)  self->getlvalueBehavesProcessing(eventID);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"implementContainingMeans");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getlvalueBehavesProcessing'.",&tolua_err);
 return 0;
#endif
}
#endif 
#ifndef TOLUA_DISABLE_tolua_implementContainingMeans_startingCompile_getlargestWorksStores00
static int tolua_implementContainingMeans_startingCompile_getlargestWorksStores00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"startingCompile",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  startingCompile* self = (startingCompile*)  tolua_tousertype(tolua_S,1,0);
  int eventID = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getlargestWorksStores'", NULL);
#endif
  {
   implementContainingMeans& tolua_ret = (implementContainingMeans&)  self->getlargestWorksStores(eventID);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"implementContainingMeans");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getlargestWorksStores'.",&tolua_err);
 return 0;
#endif
}
#endif 
#ifndef TOLUA_DISABLE_tolua_implementContainingMeans_startingCompile_getappeaanywhereCurlyOkay00
static int tolua_implementContainingMeans_startingCompile_getappeaanywhereCurlyOkay00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"startingCompile",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  startingCompile* self = (startingCompile*)  tolua_tousertype(tolua_S,1,0);
  int eventID = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getappeaanywhereCurlyOkay'", NULL);
#endif
  {
   implementContainingMeans& tolua_ret = (implementContainingMeans&)  self->getappeaanywhereCurlyOkay(eventID);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"implementContainingMeans");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getappeaanywhereCurlyOkay'.",&tolua_err);
 return 0;
#endif
}
#endif 
#ifndef TOLUA_DISABLE_tolua_implementContainingMeans_implementContainingMeans_readByFmt
static int tolua_implementContainingMeans_implementContainingMeans_readByFmt(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"implementContainingMeans",0,&tolua_err) ||
	  !tolua_isstring(tolua_S,2,0,&tolua_err) 
 )
  goto tolua_lerror;
 else
#endif
 {
  implementContainingMeans* self = (implementContainingMeans*)  tolua_tousertype(tolua_S,1,0);
  lua_State* pState =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'readByFmt'", NULL);
#endif
  {
	const char *fmt = tolua_tostring(pState,2,0);
	const char *beg_fmt = fmt;
	int count = 0;
	while (*fmt)
	{
		char c = *fmt++;
		switch (c)
		{
			case 'b': { tolua_pushboolean(tolua_S, (bool)self->popBool()); } break;
			case 'i': { tolua_pushnumber(tolua_S, (lua_Number)self->popInt()); } break;
			case 'c': { tolua_pushnumber(tolua_S, (lua_Number)self->popChar()); } break;
			case 's': { tolua_pushnumber(tolua_S, (lua_Number)self->popShort()); } break;
			case 'd': { tolua_pushnumber(tolua_S, (lua_Number)self->popDouble()); } break;
			case 'f': { tolua_pushnumber(tolua_S, (lua_Number)self->popFloat()); } break;
			case 'S': { tolua_pushcppstring(tolua_S, (const char*)self->popString()); } break;
			case 'l': { tolua_pushnumber(tolua_S, (lua_Number)self->pointerwhenTopicsPeople()); } break;
			case 'I': { tolua_pushnumber(tolua_S, (lua_Number)self->popIInt()); } break;
			default: break;
		}
	
		count++;
	 }
	return count;
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'readByFmt'.",&tolua_err);
 return 0;
#endif
}
#endif 
#ifndef TOLUA_DISABLE_tolua_implementContainingMeans_implementContainingMeans_writeByFmt
static int tolua_implementContainingMeans_implementContainingMeans_writeByFmt(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"implementContainingMeans",0,&tolua_err) ||
	  !tolua_isstring(tolua_S,2,0,&tolua_err) 
 )
  goto tolua_lerror;
 else
#endif
 {
  implementContainingMeans* self = (implementContainingMeans*)  tolua_tousertype(tolua_S,1,0);
  lua_State* pState =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'writeByFmt'", NULL);
#endif
  {
	int n = lua_gettop(tolua_S)-1;
	const char *fmt = tolua_tostring(pState,2,0);
	const char *beg_fmt = fmt;
	int index = 1;
	int count = 0;
	while (*fmt && index < n)
	{
		char c = *fmt++;
		switch (c)
		{
			case 'b': { 
				int flag = tolua_toboolean(tolua_S,2+index,0);
				self->pushBool(flag>0?true:false); 
				} break;
			case 'i': { self->pushInt((int)  tolua_tonumber(tolua_S,2+index,0)); } break;
			case 'c': { self->pushChar((char)  tolua_tonumber(tolua_S,2+index,0)); } break;
			case 's': { self->pushShort((short)  tolua_tonumber(tolua_S,2+index,0)); } break;
			case 'd': { self->whenStoringContrpasses((double)  tolua_tonumber(tolua_S,2+index,0)); } break;
			case 'C': { self->pushChars((const char*)  tolua_tostring(tolua_S,2+index,0)); } break;
			case 'l': { self->exceptionRespective((long long)  tolua_tonumber(tolua_S,2+index,0)); } break;
			case 'S': 
				{ 
					std::string str = ((std::string)  tolua_tocppstring(tolua_S,2+index,0));
					self->pushString(str); 
					tolua_pushcppstring(tolua_S,(const char*)str); 
					count++;
				} break;
		
			default: break;
		}
		++index;
	 }
	return count;
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'writeByFmt'.",&tolua_err);
 return 0;
#endif
}
#endif 
TOLUA_API int tolua_implementContainingMeans_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_constant(tolua_S,"LUA_V_UINT",LUA_V_UINT);
  tolua_constant(tolua_S,"LUA_V_LONG",LUA_V_LONG);
  tolua_constant(tolua_S,"LUA_V_FLOAT",LUA_V_FLOAT);
  tolua_constant(tolua_S,"LUA_V_STRING",LUA_V_STRING);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"implementContainingMeans","implementContainingMeans","",tolua_collect_implementContainingMeans);
  #else
  tolua_cclass(tolua_S,"implementContainingMeans","implementContainingMeans","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"implementContainingMeans");
  tolua_function(tolua_S,"new",tolua_implementContainingMeans_implementContainingMeans_new00);
  tolua_function(tolua_S,"new_local",tolua_implementContainingMeans_implementContainingMeans_new00_local);
  tolua_function(tolua_S,".call",tolua_implementContainingMeans_implementContainingMeans_new00_local);
  tolua_function(tolua_S,"delete",tolua_implementContainingMeans_implementContainingMeans_delete00);
  tolua_function(tolua_S,"pushBool",tolua_implementContainingMeans_implementContainingMeans_pushBool00);
  tolua_function(tolua_S,"pushInt",tolua_implementContainingMeans_implementContainingMeans_pushInt00);
  tolua_function(tolua_S,"pushChar",tolua_implementContainingMeans_implementContainingMeans_pushChar00);
  tolua_function(tolua_S,"pushUChar",tolua_implementContainingMeans_implementContainingMeans_pushUnChar00);
  tolua_function(tolua_S,"pushShort",tolua_implementContainingMeans_implementContainingMeans_pushShort00);
  tolua_function(tolua_S,"whenStoringContrpasses",tolua_implementContainingMeans_implementContainingMeans_whenStoringContrpasses00);
  tolua_function(tolua_S,"pushChars",tolua_implementContainingMeans_implementContainingMeans_pushChars00);
  tolua_function(tolua_S,"pushString",tolua_implementContainingMeans_implementContainingMeans_pushString00);
  tolua_function(tolua_S,"pushData",tolua_implementContainingMeans_implementContainingMeans_pushData00);
  tolua_function(tolua_S,"popBool",tolua_implementContainingMeans_implementContainingMeans_popBool00);
  tolua_function(tolua_S,"popInt",tolua_implementContainingMeans_implementContainingMeans_popInt00);
  tolua_function(tolua_S,"popChar",tolua_implementContainingMeans_implementContainingMeans_popChar00);
  tolua_function(tolua_S,"popUChar",tolua_implementContainingMeans_implementContainingMeans_popUnChar00);
  tolua_function(tolua_S,"popUShort",tolua_implementContainingMeans_implementContainingMeans_popUnShort00);
  tolua_function(tolua_S,"popShort",tolua_implementContainingMeans_implementContainingMeans_popShort00);
  tolua_function(tolua_S,"popFloat",tolua_implementContainingMeans_implementContainingMeans_popFloat00);
  tolua_function(tolua_S,"popDouble",tolua_implementContainingMeans_implementContainingMeans_popDouble00);
  tolua_function(tolua_S,"pointerwhenTopicsPeople",tolua_implementContainingMeans_implementContainingMeans_pointerwhenTopicsPeople00);
  tolua_function(tolua_S,"clear",tolua_implementContainingMeans_implementContainingMeans_clear00);
  tolua_function(tolua_S,"popString",tolua_implementContainingMeans_implementContainingMeans_popString00);
  tolua_function(tolua_S,"getdifferentlyCopiedSpace",tolua_implementContainingMeans_implementContainingMeans_getdifferentlyCopiedSpace);
  
  tolua_function(tolua_S,"popInts",tolua_implementContainingMeans_implementContainingMeans_popInts00);
  
   tolua_function(tolua_S,"readByFmt",tolua_implementContainingMeans_implementContainingMeans_readByFmt);
   tolua_function(tolua_S,"writeByFmt",tolua_implementContainingMeans_implementContainingMeans_writeByFmt);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"startingCompile","startingCompile","",tolua_collect_startingCompile);
  #else
  tolua_cclass(tolua_S,"startingCompile","startingCompile","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"startingCompile");
  
  tolua_function(tolua_S,"instance",tolua_implementContainingMeans_startingCompile_instance00);
  tolua_function(tolua_S,"getlvalueBehavesProcessing",tolua_implementContainingMeans_startingCompile_getlvalueBehavesProcessing00);
  tolua_function(tolua_S,"getlargestWorksStores",tolua_implementContainingMeans_startingCompile_getlargestWorksStores00);
  tolua_function(tolua_S,"getappeaanywhereCurlyOkay",tolua_implementContainingMeans_startingCompile_getappeaanywhereCurlyOkay00);
   
   
   
   
   
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}
#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_implementContainingMeans (lua_State* tolua_S) {
 return tolua_implementContainingMeans_open(tolua_S);
};
#endif
