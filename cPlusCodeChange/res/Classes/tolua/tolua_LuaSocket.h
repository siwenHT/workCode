/*
** Lua binding: LuaSocket
** Generated automatically by tolua++-1.0.92 on 03/24/14 15:29:48.
*/

/****************************************************************************
 Copyright (c) 2011 cocos2d-x.org

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

extern "C" {
#include "tolua_fix.h"
}

#include <map>
#include <string>
#include "cocos2d.h"
#include "CCLuaEngine.h"
#include "cocos-ext.h"
#include "LuaSocket.h"

using namespace cocos2d;
using namespace cocos2d::extension;

/* Exported function */
TOLUA_API int  tolua_LuaSocket_open (lua_State* tolua_S);


/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_LuaSocket (lua_State* tolua_S)
{
 LuaSocket* self = (LuaSocket*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}
#endif


/* function to register type */
static void tolua_reg_types1 (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"LuaSocket");
 tolua_usertype(tolua_S,"AppMsg");
 tolua_usertype(tolua_S,"ODSocket");
 tolua_usertype(tolua_S,"CCObject");
 tolua_usertype(tolua_S,"CLuaParam");
 tolua_usertype(tolua_S,"LuaMsgBuffer");
}

/* get function: cSocket of class  LuaSocket */
#ifndef TOLUA_DISABLE_tolua_get_LuaSocket_cSocket_ptr
static int tolua_get_LuaSocket_cSocket_ptr(lua_State* tolua_S)
{
  LuaSocket* self = (LuaSocket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cSocket'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->cSocket,"ODSocket");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: cSocket of class  LuaSocket */
#ifndef TOLUA_DISABLE_tolua_set_LuaSocket_cSocket_ptr
static int tolua_set_LuaSocket_cSocket_ptr(lua_State* tolua_S)
{
  LuaSocket* self = (LuaSocket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cSocket'",NULL);
  if (!tolua_isusertype(tolua_S,2,"ODSocket",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->cSocket = ((ODSocket*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInstance of class  LuaSocket */
#ifndef TOLUA_DISABLE_tolua_LuaSocket_LuaSocket_getInstance00
static int tolua_LuaSocket_LuaSocket_getInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaSocket",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LuaSocket* tolua_ret = (LuaSocket*)  LuaSocket::getInstance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"LuaSocket");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  LuaSocket */
#ifndef TOLUA_DISABLE_tolua_LuaSocket_LuaSocket_new00
static int tolua_LuaSocket_LuaSocket_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaSocket",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LuaSocket* tolua_ret = (LuaSocket*)  Mtolua_new((LuaSocket)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"LuaSocket");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  LuaSocket */
#ifndef TOLUA_DISABLE_tolua_LuaSocket_LuaSocket_new00_local
static int tolua_LuaSocket_LuaSocket_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaSocket",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LuaSocket* tolua_ret = (LuaSocket*)  Mtolua_new((LuaSocket)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"LuaSocket");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  LuaSocket */
#ifndef TOLUA_DISABLE_tolua_LuaSocket_LuaSocket_delete00
static int tolua_LuaSocket_LuaSocket_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaSocket",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaSocket* self = (LuaSocket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 lua_settop(tolua_S, 1);
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: openSocket of class  LuaSocket */
#ifndef TOLUA_DISABLE_tolua_LuaSocket_LuaSocket_openSocket00
static int tolua_LuaSocket_LuaSocket_openSocket00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaSocket",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaSocket* self = (LuaSocket*)  tolua_tousertype(tolua_S,1,0);
  const char* ip = ((const char*)  tolua_tostring(tolua_S,2,0));
  int poush = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'openSocket'", NULL);
#endif
  {
   int tolua_ret = (int)  self->openSocket(ip,poush);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sendSocket of class  LuaSocket */
#ifndef TOLUA_DISABLE_tolua_LuaSocket_LuaSocket_sendSocket00
static int tolua_LuaSocket_LuaSocket_sendSocket00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaSocket",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"LuaMsgBuffer",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaSocket* self = (LuaSocket*)  tolua_tousertype(tolua_S,1,0);
  LuaMsgBuffer* luaBuff = ((LuaMsgBuffer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sendSocket'", NULL);
#endif
  {
   self->sendSocket(*luaBuff);
  }
 }
 lua_settop(tolua_S, 1);
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSocket of class  LuaSocket */
//#ifndef TOLUA_DISABLE_tolua_LuaSocket_LuaSocket_getSocket00
//static int tolua_LuaSocket_LuaSocket_getSocket00(lua_State* tolua_S)
//{
//#ifndef TOLUA_RELEASE
// tolua_Error tolua_err;
// if (
//     !tolua_isusertype(tolua_S,1,"LuaSocket",0,&tolua_err) ||
//     !tolua_isnoobj(tolua_S,2,&tolua_err)
// )
//  goto tolua_lerror;
// else
//#endif
// {
//  LuaSocket* self = (LuaSocket*)  tolua_tousertype(tolua_S,1,0);
//#ifndef TOLUA_RELEASE
//  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSocket'", NULL);
//#endif
//  {
//   char* tolua_ret = (char*)  self->getSocket();
//   tolua_pushstring(tolua_S,(const char*)tolua_ret);
//  }
// }
// return 1;
//#ifndef TOLUA_RELEASE
// tolua_lerror:
// tolua_error(tolua_S,"",&tolua_err);
// return 0;
//#endif
//}
//#endif //#ifndef TOLUA_DISABLE

/* method: closeSocket of class  LuaSocket */
#ifndef TOLUA_DISABLE_tolua_LuaSocket_LuaSocket_closeSocket00
static int tolua_LuaSocket_LuaSocket_closeSocket00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaSocket",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaSocket* self = (LuaSocket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'closeSocket'", NULL);
#endif
  {
   self->closeSocket();
  }
 }
 lua_settop(tolua_S, 1);
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE


/* method: callback of class  LuaSocket */
//#ifndef TOLUA_DISABLE_tolua_LuaSocket_LuaSocket_callback00
//static int tolua_LuaSocket_LuaSocket_callback00(lua_State* tolua_S)
//{
//#ifndef TOLUA_RELEASE
// tolua_Error tolua_err;
// if (
//     !tolua_isusertype(tolua_S,1,"LuaSocket",0,&tolua_err) ||
//     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
//     !tolua_isnoobj(tolua_S,3,&tolua_err)
// )
//  goto tolua_lerror;
// else
//#endif
// {
//  LuaSocket* self = (LuaSocket*)  tolua_tousertype(tolua_S,1,0);
//  float delta = ((float)  tolua_tonumber(tolua_S,2,0));
//#ifndef TOLUA_RELEASE
//  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'callback'", NULL);
//#endif
//  {
//   self->callback(delta);
//  }
// }
// return 0;
//#ifndef TOLUA_RELEASE
// tolua_lerror:
// tolua_error(tolua_S,"",&tolua_err);
// return 0;
//#endif
//}
//#endif //#ifndef TOLUA_DISABLE

///* method: sendThread of class  LuaSocket */
//#ifndef TOLUA_DISABLE_tolua_LuaSocket_LuaSocket_sendThread00
//static int tolua_LuaSocket_LuaSocket_sendThread00(lua_State* tolua_S)
//{
//#ifndef TOLUA_RELEASE
// tolua_Error tolua_err;
// if (
//     !tolua_isusertype(tolua_S,1,"LuaSocket",0,&tolua_err) ||
//     !tolua_isnoobj(tolua_S,2,&tolua_err)
// )
//  goto tolua_lerror;
// else
//#endif
// {
//  LuaSocket* self = (LuaSocket*)  tolua_tousertype(tolua_S,1,0);
//#ifndef TOLUA_RELEASE
//  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sendThread'", NULL);
//#endif
//  {
//   self->sendThread();
//  }
// }
// return 0;
//#ifndef TOLUA_RELEASE
// tolua_lerror:
// tolua_error(tolua_S,"",&tolua_err);
// return 0;
//#endif
//}
//#endif //#ifndef TOLUA_DISABLE

/* method: readThread of class  LuaSocket */
#ifndef TOLUA_DISABLE_tolua_LuaSocket_LuaSocket_readThread00
static int tolua_LuaSocket_LuaSocket_readThread00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaSocket",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaSocket* self = (LuaSocket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'readThread'", NULL);
#endif
  {
   self->readThread();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: runLuaFunc of class  LuaSocket */
#ifndef TOLUA_DISABLE_tolua_LuaSocket_LuaSocket_runLuaFunc00
static int tolua_LuaSocket_LuaSocket_runLuaFunc00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaSocket",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CLuaParam",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaSocket* self = (LuaSocket*)  tolua_tousertype(tolua_S,1,0);
  char* szFunName = ((char*)  tolua_tostring(tolua_S,2,0));
  CLuaParam* pInParam = ((CLuaParam*)  tolua_tousertype(tolua_S,3,0));
  int nInNum = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'runLuaFunc'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->runLuaFunc(szFunName,pInParam,nInNum);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

static int tolua_LuaSocket_LuaSocket_setCplusShowMsgID(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"LuaSocket",0,&tolua_err) ||
		!tolua_isboolean(tolua_S,2,0,&tolua_err)
		)
		goto tolua_lerror;
	else
#endif
	{
		LuaSocket* self = (LuaSocket*)  tolua_tousertype(tolua_S,1,0);
		bool isShow = tolua_toboolean(tolua_S, 2, true);
#ifndef TOLUA_RELEASE
		if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setCplusShowMsgID'", NULL);
#endif
		{
			self->setCplusShowMsgID(isShow);
		}
	}
	return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
	return 0;
#endif
}

/* Open function */
TOLUA_API int tolua_LuaSocket_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types1(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"LuaSocket","LuaSocket","CCObject",tolua_collect_LuaSocket);
  #else
  tolua_cclass(tolua_S,"LuaSocket","LuaSocket","CCObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"LuaSocket");
   tolua_variable(tolua_S,"cSocket",tolua_get_LuaSocket_cSocket_ptr,tolua_set_LuaSocket_cSocket_ptr);
   tolua_function(tolua_S,"getInstance",tolua_LuaSocket_LuaSocket_getInstance00);
   tolua_function(tolua_S,"new",tolua_LuaSocket_LuaSocket_new00);
   tolua_function(tolua_S,"new_local",tolua_LuaSocket_LuaSocket_new00_local);
   tolua_function(tolua_S,".call",tolua_LuaSocket_LuaSocket_new00_local);
   tolua_function(tolua_S,"delete",tolua_LuaSocket_LuaSocket_delete00);
   tolua_function(tolua_S,"openSocket",tolua_LuaSocket_LuaSocket_openSocket00);
   tolua_function(tolua_S,"sendSocket",tolua_LuaSocket_LuaSocket_sendSocket00);
   //tolua_function(tolua_S,"getSocket",tolua_LuaSocket_LuaSocket_getSocket00);
   tolua_function(tolua_S,"closeSocket",tolua_LuaSocket_LuaSocket_closeSocket00);
   //tolua_function(tolua_S,"creadFuancuan",tolua_LuaSocket_LuaSocket_creadFuancuan00);
   //tolua_function(tolua_S,"callback",tolua_LuaSocket_LuaSocket_callback00);
   //tolua_function(tolua_S,"sendThread",tolua_LuaSocket_LuaSocket_sendThread00);
   tolua_function(tolua_S,"readThread",tolua_LuaSocket_LuaSocket_readThread00);
   //tolua_function(tolua_S,"initSendBuf",tolua_LuaSocket_LuaSocket_initSendBuf00);
   //tolua_function(tolua_S,"releaseSendBuf",tolua_LuaSocket_LuaSocket_releaseSendBuf00);
   tolua_function(tolua_S,"runLuaFunc",tolua_LuaSocket_LuaSocket_runLuaFunc00);
   tolua_function(tolua_S,"setCplusShowMsgID",tolua_LuaSocket_LuaSocket_setCplusShowMsgID);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_LuaSocket (lua_State* tolua_S) {
 return tolua_LuaSocket_open(tolua_S);
};
#endif

