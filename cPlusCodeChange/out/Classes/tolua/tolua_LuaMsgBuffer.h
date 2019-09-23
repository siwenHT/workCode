
extern "C" {
#include "tolua_fix.h"
}
#include <map>
#include <string>
#include "cocos2d.h"
#include "CCLuaEngine.h"
#include "LuaMsgBuffer.h"
#include "cocos-ext.h"
using namespace cocos2d;
using namespace cocos2d::extension;
TOLUA_API int  tolua_LuaMsgBuffer_open (lua_State* tolua_S);
#ifdef __cplusplus
static int tolua_collect_LuaEventManager (lua_State* tolua_S)
{
 LuaEventManager* self = (LuaEventManager*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}
static int tolua_collect_LuaMsgBuffer (lua_State* tolua_S)
{
 LuaMsgBuffer* self = (LuaMsgBuffer*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}
#endif
static void tolua_reg_types (lua_State* tolua_S)
{
 
 tolua_usertype(tolua_S,"AppMsg");
 tolua_usertype(tolua_S,"LuaEventManager");
 tolua_usertype(tolua_S,"std::vector<int>");
 tolua_usertype(tolua_S,"LuaMsgBuffer");
}
#ifndef TOLUA_DISABLE_tolua_LuaMsgBuffer_LuaMsgBuffer_new00
static int tolua_LuaMsgBuffer_LuaMsgBuffer_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaMsgBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LuaMsgBuffer* tolua_ret = (LuaMsgBuffer*)  Mtolua_new((LuaMsgBuffer)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"LuaMsgBuffer");
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
#ifndef TOLUA_DISABLE_tolua_LuaMsgBuffer_LuaMsgBuffer_new00_local
static int tolua_LuaMsgBuffer_LuaMsgBuffer_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaMsgBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LuaMsgBuffer* tolua_ret = (LuaMsgBuffer*)  Mtolua_new((LuaMsgBuffer)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"LuaMsgBuffer");
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
#ifndef TOLUA_DISABLE_tolua_LuaMsgBuffer_LuaMsgBuffer_delete00
static int tolua_LuaMsgBuffer_LuaMsgBuffer_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaMsgBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaMsgBuffer* self = (LuaMsgBuffer*)  tolua_tousertype(tolua_S,1,0);
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
#ifndef TOLUA_DISABLE_tolua_LuaMsgBuffer_LuaMsgBuffer_pushBool00
static int tolua_LuaMsgBuffer_LuaMsgBuffer_pushBool00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaMsgBuffer",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaMsgBuffer* self = (LuaMsgBuffer*)  tolua_tousertype(tolua_S,1,0);
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
#ifndef TOLUA_DISABLE_tolua_LuaMsgBuffer_LuaMsgBuffer_pushInt00
static int tolua_LuaMsgBuffer_LuaMsgBuffer_pushInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaMsgBuffer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaMsgBuffer* self = (LuaMsgBuffer*)  tolua_tousertype(tolua_S,1,0);
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
#ifndef TOLUA_DISABLE_tolua_LuaMsgBuffer_LuaMsgBuffer_pushChar00
static int tolua_LuaMsgBuffer_LuaMsgBuffer_pushChar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaMsgBuffer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaMsgBuffer* self = (LuaMsgBuffer*)  tolua_tousertype(tolua_S,1,0);
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
#ifndef TOLUA_DISABLE_tolua_LuaMsgBuffer_LuaMsgBuffer_pushUnChar00
static int tolua_LuaMsgBuffer_LuaMsgBuffer_pushUnChar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaMsgBuffer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaMsgBuffer* self = (LuaMsgBuffer*)  tolua_tousertype(tolua_S,1,0);
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
#ifndef TOLUA_DISABLE_tolua_LuaMsgBuffer_LuaMsgBuffer_pushShort00
static int tolua_LuaMsgBuffer_LuaMsgBuffer_pushShort00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaMsgBuffer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaMsgBuffer* self = (LuaMsgBuffer*)  tolua_tousertype(tolua_S,1,0);
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
#ifndef TOLUA_DISABLE_tolua_LuaMsgBuffer_LuaMsgBuffer_pushDouble00
static int tolua_LuaMsgBuffer_LuaMsgBuffer_pushDouble00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaMsgBuffer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaMsgBuffer* self = (LuaMsgBuffer*)  tolua_tousertype(tolua_S,1,0);
  double value = ((double)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pushDouble'", NULL);
#endif
  {
   self->pushDouble(value);
  }
 }
 lua_settop(tolua_S, 1);
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pushDouble'.",&tolua_err);
 return 0;
#endif
}
#endif 
#ifndef TOLUA_DISABLE_tolua_LuaMsgBuffer_LuaMsgBuffer_pushChars00
static int tolua_LuaMsgBuffer_LuaMsgBuffer_pushChars00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaMsgBuffer",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaMsgBuffer* self = (LuaMsgBuffer*)  tolua_tousertype(tolua_S,1,0);
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
#ifndef TOLUA_DISABLE_tolua_LuaMsgBuffer_LuaMsgBuffer_pushString00
static int tolua_LuaMsgBuffer_LuaMsgBuffer_pushString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaMsgBuffer",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaMsgBuffer* self = (LuaMsgBuffer*)  tolua_tousertype(tolua_S,1,0);
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
#ifndef TOLUA_DISABLE_tolua_LuaMsgBuffer_LuaMsgBuffer_pushData00
static int tolua_LuaMsgBuffer_LuaMsgBuffer_pushData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaMsgBuffer",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaMsgBuffer* self = (LuaMsgBuffer*)  tolua_tousertype(tolua_S,1,0);
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
#ifndef TOLUA_DISABLE_tolua_LuaMsgBuffer_LuaMsgBuffer_popBool00
static int tolua_LuaMsgBuffer_LuaMsgBuffer_popBool00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaMsgBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaMsgBuffer* self = (LuaMsgBuffer*)  tolua_tousertype(tolua_S,1,0);
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
#ifndef TOLUA_DISABLE_tolua_LuaMsgBuffer_LuaMsgBuffer_popInt00
static int tolua_LuaMsgBuffer_LuaMsgBuffer_popInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaMsgBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaMsgBuffer* self = (LuaMsgBuffer*)  tolua_tousertype(tolua_S,1,0);
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
#ifndef TOLUA_DISABLE_tolua_LuaMsgBuffer_LuaMsgBuffer_popChar00
static int tolua_LuaMsgBuffer_LuaMsgBuffer_popChar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaMsgBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaMsgBuffer* self = (LuaMsgBuffer*)  tolua_tousertype(tolua_S,1,0);
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
#ifndef TOLUA_DISABLE_tolua_LuaMsgBuffer_LuaMsgBuffer_popUnChar00
static int tolua_LuaMsgBuffer_LuaMsgBuffer_popUnChar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaMsgBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaMsgBuffer* self = (LuaMsgBuffer*)  tolua_tousertype(tolua_S,1,0);
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
#ifndef TOLUA_DISABLE_tolua_LuaMsgBuffer_LuaMsgBuffer_popUnShort00
static int tolua_LuaMsgBuffer_LuaMsgBuffer_popUnShort00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaMsgBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaMsgBuffer* self = (LuaMsgBuffer*)  tolua_tousertype(tolua_S,1,0);
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
#ifndef TOLUA_DISABLE_tolua_LuaMsgBuffer_LuaMsgBuffer_popShort00
static int tolua_LuaMsgBuffer_LuaMsgBuffer_popShort00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaMsgBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaMsgBuffer* self = (LuaMsgBuffer*)  tolua_tousertype(tolua_S,1,0);
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
#ifndef TOLUA_DISABLE_tolua_LuaMsgBuffer_LuaMsgBuffer_popFloat00
static int tolua_LuaMsgBuffer_LuaMsgBuffer_popFloat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaMsgBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaMsgBuffer* self = (LuaMsgBuffer*)  tolua_tousertype(tolua_S,1,0);
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
#ifndef TOLUA_DISABLE_tolua_LuaMsgBuffer_LuaMsgBuffer_popDouble00
static int tolua_LuaMsgBuffer_LuaMsgBuffer_popDouble00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaMsgBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaMsgBuffer* self = (LuaMsgBuffer*)  tolua_tousertype(tolua_S,1,0);
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
#ifndef TOLUA_DISABLE_tolua_LuaMsgBuffer_LuaMsgBuffer_popLongLong00
static int tolua_LuaMsgBuffer_LuaMsgBuffer_popLongLong00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaMsgBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaMsgBuffer* self = (LuaMsgBuffer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'popLongLong'", NULL);
#endif
  {
   long long tolua_ret = (long long)  self->popLongLong();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'popLongLong'.",&tolua_err);
 return 0;
#endif
}
#endif 
#ifndef TOLUA_DISABLE_tolua_LuaMsgBuffer_LuaMsgBuffer_clear00
static int tolua_LuaMsgBuffer_LuaMsgBuffer_clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaMsgBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaMsgBuffer* self = (LuaMsgBuffer*)  tolua_tousertype(tolua_S,1,0);
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
#ifndef TOLUA_DISABLE_tolua_LuaMsgBuffer_LuaMsgBuffer_popString00
static int tolua_LuaMsgBuffer_LuaMsgBuffer_popString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaMsgBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaMsgBuffer* self = (LuaMsgBuffer*)  tolua_tousertype(tolua_S,1,0);
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
#ifndef TOLUA_DISABLE_tolua_LuaMsgBuffer_LuaMsgBuffer_popInts00
static int tolua_LuaMsgBuffer_LuaMsgBuffer_popInts00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaMsgBuffer",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"std::vector<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaMsgBuffer* self = (LuaMsgBuffer*)  tolua_tousertype(tolua_S,1,0);
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
#ifndef tolua_LuaMsgBuffer_LuaMsgBuffer_getProtoBody
static int tolua_LuaMsgBuffer_LuaMsgBuffer_getProtoBody(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"LuaMsgBuffer",0,&tolua_err) ||
		!tolua_isnumber(tolua_S,2,0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,3,&tolua_err)
		)
		goto tolua_lerror;
	else
#endif
	{
		LuaMsgBuffer* self = (LuaMsgBuffer*)  tolua_tousertype(tolua_S,1,0);
		short num = ((short)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
		if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getProtoBody'", NULL);
#endif
		{
			const char* ret = self->getProtoBody(num);
			lua_pushlightuserdata(tolua_S, (void*)ret);
			return 1;
		}
	}
	tolua_error(tolua_S,"#ferror in function 'getProtoBody'.",&tolua_err);
	return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'getProtoBody'.",&tolua_err);
	return 0;
#endif
}
#endif 
#ifndef TOLUA_DISABLE_tolua_LuaMsgBuffer_LuaEventManager_delete00
static int tolua_LuaMsgBuffer_LuaEventManager_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaEventManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaEventManager* self = (LuaEventManager*)  tolua_tousertype(tolua_S,1,0);
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
#ifndef TOLUA_DISABLE_tolua_LuaMsgBuffer_LuaEventManager_instance00
static int tolua_LuaMsgBuffer_LuaEventManager_instance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaEventManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LuaEventManager* tolua_ret = (LuaEventManager*)  LuaEventManager::instance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"LuaEventManager");
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
#ifndef TOLUA_DISABLE_tolua_LuaMsgBuffer_LuaEventManager_getLuaEvent00
static int tolua_LuaMsgBuffer_LuaEventManager_getLuaEvent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaEventManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaEventManager* self = (LuaEventManager*)  tolua_tousertype(tolua_S,1,0);
  int eventID = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLuaEvent'", NULL);
#endif
  {
   LuaMsgBuffer& tolua_ret = (LuaMsgBuffer&)  self->getLuaEvent(eventID);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"LuaMsgBuffer");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLuaEvent'.",&tolua_err);
 return 0;
#endif
}
#endif 
#ifndef TOLUA_DISABLE_tolua_LuaMsgBuffer_LuaEventManager_getLuaEventEx00
static int tolua_LuaMsgBuffer_LuaEventManager_getLuaEventEx00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaEventManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaEventManager* self = (LuaEventManager*)  tolua_tousertype(tolua_S,1,0);
  int eventID = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLuaEventEx'", NULL);
#endif
  {
   LuaMsgBuffer& tolua_ret = (LuaMsgBuffer&)  self->getLuaEventEx(eventID);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"LuaMsgBuffer");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLuaEventEx'.",&tolua_err);
 return 0;
#endif
}
#endif 
#ifndef TOLUA_DISABLE_tolua_LuaMsgBuffer_LuaEventManager_getLuaEventExEx00
static int tolua_LuaMsgBuffer_LuaEventManager_getLuaEventExEx00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaEventManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaEventManager* self = (LuaEventManager*)  tolua_tousertype(tolua_S,1,0);
  int eventID = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLuaEventExEx'", NULL);
#endif
  {
   LuaMsgBuffer& tolua_ret = (LuaMsgBuffer&)  self->getLuaEventExEx(eventID);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"LuaMsgBuffer");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLuaEventExEx'.",&tolua_err);
 return 0;
#endif
}
#endif 
#ifndef TOLUA_DISABLE_tolua_LuaMsgBuffer_LuaMsgBuffer_readByFmt
static int tolua_LuaMsgBuffer_LuaMsgBuffer_readByFmt(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaMsgBuffer",0,&tolua_err) ||
	  !tolua_isstring(tolua_S,2,0,&tolua_err) 
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaMsgBuffer* self = (LuaMsgBuffer*)  tolua_tousertype(tolua_S,1,0);
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
			case 'l': { tolua_pushnumber(tolua_S, (lua_Number)self->popLongLong()); } break;
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
#ifndef TOLUA_DISABLE_tolua_LuaMsgBuffer_LuaMsgBuffer_writeByFmt
static int tolua_LuaMsgBuffer_LuaMsgBuffer_writeByFmt(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaMsgBuffer",0,&tolua_err) ||
	  !tolua_isstring(tolua_S,2,0,&tolua_err) 
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaMsgBuffer* self = (LuaMsgBuffer*)  tolua_tousertype(tolua_S,1,0);
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
			case 'd': { self->pushDouble((double)  tolua_tonumber(tolua_S,2+index,0)); } break;
			case 'C': { self->pushChars((const char*)  tolua_tostring(tolua_S,2+index,0)); } break;
			case 'l': { self->pushLongLong((long long)  tolua_tonumber(tolua_S,2+index,0)); } break;
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
TOLUA_API int tolua_LuaMsgBuffer_open (lua_State* tolua_S)
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
  tolua_cclass(tolua_S,"LuaMsgBuffer","LuaMsgBuffer","",tolua_collect_LuaMsgBuffer);
  #else
  tolua_cclass(tolua_S,"LuaMsgBuffer","LuaMsgBuffer","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"LuaMsgBuffer");
  tolua_function(tolua_S,"new",tolua_LuaMsgBuffer_LuaMsgBuffer_new00);
  tolua_function(tolua_S,"new_local",tolua_LuaMsgBuffer_LuaMsgBuffer_new00_local);
  tolua_function(tolua_S,".call",tolua_LuaMsgBuffer_LuaMsgBuffer_new00_local);
  tolua_function(tolua_S,"delete",tolua_LuaMsgBuffer_LuaMsgBuffer_delete00);
  tolua_function(tolua_S,"pushBool",tolua_LuaMsgBuffer_LuaMsgBuffer_pushBool00);
  tolua_function(tolua_S,"pushInt",tolua_LuaMsgBuffer_LuaMsgBuffer_pushInt00);
  tolua_function(tolua_S,"pushChar",tolua_LuaMsgBuffer_LuaMsgBuffer_pushChar00);
  tolua_function(tolua_S,"pushUChar",tolua_LuaMsgBuffer_LuaMsgBuffer_pushUnChar00);
  tolua_function(tolua_S,"pushShort",tolua_LuaMsgBuffer_LuaMsgBuffer_pushShort00);
  tolua_function(tolua_S,"pushDouble",tolua_LuaMsgBuffer_LuaMsgBuffer_pushDouble00);
  tolua_function(tolua_S,"pushChars",tolua_LuaMsgBuffer_LuaMsgBuffer_pushChars00);
  tolua_function(tolua_S,"pushString",tolua_LuaMsgBuffer_LuaMsgBuffer_pushString00);
  tolua_function(tolua_S,"pushData",tolua_LuaMsgBuffer_LuaMsgBuffer_pushData00);
  tolua_function(tolua_S,"popBool",tolua_LuaMsgBuffer_LuaMsgBuffer_popBool00);
  tolua_function(tolua_S,"popInt",tolua_LuaMsgBuffer_LuaMsgBuffer_popInt00);
  tolua_function(tolua_S,"popChar",tolua_LuaMsgBuffer_LuaMsgBuffer_popChar00);
  tolua_function(tolua_S,"popUChar",tolua_LuaMsgBuffer_LuaMsgBuffer_popUnChar00);
  tolua_function(tolua_S,"popUShort",tolua_LuaMsgBuffer_LuaMsgBuffer_popUnShort00);
  tolua_function(tolua_S,"popShort",tolua_LuaMsgBuffer_LuaMsgBuffer_popShort00);
  tolua_function(tolua_S,"popFloat",tolua_LuaMsgBuffer_LuaMsgBuffer_popFloat00);
  tolua_function(tolua_S,"popDouble",tolua_LuaMsgBuffer_LuaMsgBuffer_popDouble00);
  tolua_function(tolua_S,"popLongLong",tolua_LuaMsgBuffer_LuaMsgBuffer_popLongLong00);
  tolua_function(tolua_S,"clear",tolua_LuaMsgBuffer_LuaMsgBuffer_clear00);
  tolua_function(tolua_S,"popString",tolua_LuaMsgBuffer_LuaMsgBuffer_popString00);
  tolua_function(tolua_S,"getProtoBody",tolua_LuaMsgBuffer_LuaMsgBuffer_getProtoBody);
  
  tolua_function(tolua_S,"popInts",tolua_LuaMsgBuffer_LuaMsgBuffer_popInts00);
  
   tolua_function(tolua_S,"readByFmt",tolua_LuaMsgBuffer_LuaMsgBuffer_readByFmt);
   tolua_function(tolua_S,"writeByFmt",tolua_LuaMsgBuffer_LuaMsgBuffer_writeByFmt);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"LuaEventManager","LuaEventManager","",tolua_collect_LuaEventManager);
  #else
  tolua_cclass(tolua_S,"LuaEventManager","LuaEventManager","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"LuaEventManager");
  
  tolua_function(tolua_S,"instance",tolua_LuaMsgBuffer_LuaEventManager_instance00);
  tolua_function(tolua_S,"getLuaEvent",tolua_LuaMsgBuffer_LuaEventManager_getLuaEvent00);
  tolua_function(tolua_S,"getLuaEventEx",tolua_LuaMsgBuffer_LuaEventManager_getLuaEventEx00);
  tolua_function(tolua_S,"getLuaEventExEx",tolua_LuaMsgBuffer_LuaEventManager_getLuaEventExEx00);
   
   
   
   
   
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}
#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_LuaMsgBuffer (lua_State* tolua_S) {
 return tolua_LuaMsgBuffer_open(tolua_S);
};
#endif
