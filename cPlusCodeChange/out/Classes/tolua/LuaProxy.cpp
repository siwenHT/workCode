#include "LuaProxy.h"
#include "tolua_MapView.h"
#include "tolua_SpriteBase.h"
#include "tolua_ClipboardHelper.h"
#include "tolua_CCEffects.h"
#include "tolua_BtnContainer.h"
#include "tolua_MenuButton.h"
#include "tolua_OperateLayer.h"
#include "tolua_SkillCtrl.h"
#include "tolua_MakeNumbers.h"
#include "tolua_LuaMsgBuffer.h"
#include "tolua_LuaSocket.h"
#include "tolua_AsyncDowdload.h"
#include "tolua_TextureManager.h"
#include "tolua_ActorActionManageC.h"
#include "tolua_AsyncFileOp.h"
#include "tolua_LabelNodeC.h"
#include "Young.h"
#include "tolua_pbc.h"
#include "tolua_function.h"
TOLUA_API int lua_LuaProxy(lua_State* l){
	tolua_open(l);
	tolua_module(l, NULL, 0);
	tolua_beginmodule(l, NULL);
	lua_register_cocos2dx_MapView(l);
	lua_register_cocos2dx_MapBackLayer(l);
	lua_register_cocos2dx_SpriteBase(l);
	lua_register_cocos2dx_SpriteMonster(l);
	lua_register_cocos2dx_SpritePlayer(l);
	lua_register_cocos2dx_GraySprite(l);
	lua_register_cocos2dx_SpriteBlur(l);
	lua_register_cocos2dx_TouchSprite(l);
	lua_register_cocos2dx_Touch9Sprite(l);
	lua_register_cocos2dx_SpriteGuard(l);
	lua_register_cocos2dx_Effects(l);
	lua_register_cocos2dx_BtnContainer(l);
	lua_register_cocos2dx_MenuButton(l);
	lua_register_cocos2dx_OperateLayer(l);
	lua_register_cocos2dx_SkillCtrl(l);
	lua_register_cocos2dx_AsyncDownloadManager(l);
	lua_register_cocos2dx_TextureManager(l);
	lua_register_cocos2dx_ActorActionManageC(l);
	lua_register_cocos2dx_LabelNodeC(l);
	lua_register_cocos2dx_MakeNumbers(l);
	lua_register_cocos2dx_ClipboardHelper(l);
	tolua_LuaSocket_open(l);
	tolua_LuaMsgBuffer_open(l);
	lua_register_cocos2dx_AsyncFileOp(l);
	tolua_Young_open(l);
	luaopen_protobuf_c(l);
	lua_register_function(l);
	tolua_endmodule(l);
	return 1;
}
