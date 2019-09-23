#include "lua_assetsmanager.h"
#ifdef __cplusplus
extern "C" {
#endif
#include  "tolua_fix.h"
#ifdef __cplusplus
}
#endif
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "Md5.h"
#include "LuaBasicConversions.h"
#include "tolua++.h"
#include "CCLuaEngine.h"
#include "textureManager/TextureManager.h"
#include <cstring>  
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
#include <dirent.h>
#include <sys/stat.h>
#endif
USING_NS_CC;
USING_NS_CC_EXT;
static int lua_cocos2dx_getCurrentTime(lua_State* L)
{
    if (nullptr == L)
        return 0;
    
    int argc = lua_gettop(L);
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
    
    if (0 == argc)
    {
		struct timeval tv;
		gettimeofday(&tv,NULL);
		long ret = tv.tv_sec * 1000 + tv.tv_usec / 1000;
		tolua_pushnumber(L,ret);
        
        return 1;
    }
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(L,"#ferror in function 'getCurrentTime'.",&tolua_err);
    return 0;
#endif
}
static int lua_cocos2dx_createDownloadDir(lua_State* L)
{
    if (nullptr == L)
        return 0;
    
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
    int argc = lua_gettop(L);
    if (0 == argc)
    {
        std::string pathToSave = FileUtils::getInstance()->getWritablePath();
        pathToSave += "files";
        
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
        DIR *pDir = NULL;
        
        pDir = opendir (pathToSave.c_str());
        if (! pDir)
        {
            mkdir(pathToSave.c_str(), S_IRWXU | S_IRWXG | S_IRWXO);
        }else{
			closedir(pDir);
		}
#else
        if ((GetFileAttributesA(pathToSave.c_str())) == INVALID_FILE_ATTRIBUTES)
        {
            CreateDirectoryA(pathToSave.c_str(), 0);
        }
#endif
        tolua_pushstring(L, pathToSave.c_str());
        return 1;
    }
	if (1 == argc)
	{
#if COCOS2D_DEBUG >= 1
		if (!tolua_isstring(L, 1, 0, &tolua_err)) goto tolua_lerror;
#endif
		std::string add_path = tolua_tostring(L, 1, "");
		std::string pathToSave = FileUtils::getInstance()->getWritablePath();
		pathToSave += "files";
		pathToSave += "/";
		pathToSave += add_path;
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
		DIR *pDir = NULL;
		pDir = opendir (pathToSave.c_str());
		if (! pDir)
		{
			mkdir(pathToSave.c_str(), S_IRWXU | S_IRWXG | S_IRWXO);
		}else{
			closedir(pDir);
		}
#else
		if ((GetFileAttributesA(pathToSave.c_str())) == INVALID_FILE_ATTRIBUTES)
		{
			CreateDirectoryA(pathToSave.c_str(), 0);
		}
#endif
		tolua_pushstring(L, pathToSave.c_str());
		return 1;
	}
    
    CCLOG("'createDownloadDir' function wrong number of arguments: %d, was expecting %d\n", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(L,"#ferror in function 'createDownloadDir'.",&tolua_err);
	return 0;
#endif
}
static int lua_cocos2dx_createCopyfiles(lua_State* L)
{
	if (nullptr == L)
		return 0;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
	int argc = lua_gettop(L);
	if (2 == argc)
	{
#if COCOS2D_DEBUG >= 1
		if (!tolua_isstring(L, 1, 0, &tolua_err)) goto tolua_lerror;
		if (!tolua_isstring(L, 2, 0, &tolua_err)) goto tolua_lerror;
#endif
		std::string _storagePath = tolua_tostring(L, 1, "");
		std::string m_fileName = tolua_tostring(L, 2, "");
		if (_storagePath.size() > 0 && _storagePath[_storagePath.size() - 1] != '/')
		{
			_storagePath.append("/");
		}
		size_t startIndex = 0;
		size_t index = m_fileName.find("/", startIndex);
		while (index != std::string::npos)
		{
			const string dir = _storagePath + m_fileName.substr(0, index);
			FILE *out = fopen(dir.c_str(), "r");
			if (!out)
			{
				bool suc = true;
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
				mode_t processMask = umask(0);
				int ret = mkdir(dir.c_str(), S_IRWXU | S_IRWXG | S_IRWXO);
				umask(processMask);
				if (ret != 0 && (errno != EEXIST))
				{
					suc = false;
				}
				suc = true;
#else
				BOOL ret = CreateDirectoryA(dir.c_str(), NULL);
				if (!ret && ERROR_ALREADY_EXISTS != GetLastError())
				{
					suc = false;
				}
				suc = true;
#endif
				if (!suc)
				{
					CCLOG("can not create directory %s", dir.c_str());
					break;
				}
			}
			else
			{
				fclose(out);
			}
			startIndex = index + 1;
			index = m_fileName.find("/", startIndex);
		}
		lua_settop(L, 1);
		return 1;
	}
	CCLOG("'createCopyfiles' function wrong number of arguments: %d, was expecting %d\n", argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(L,"#ferror in function 'createCopyfiles'.",&tolua_err);
	return 0;
#endif
}
static int lua_cocos2dx_copyFile(lua_State* L)
{
	if (nullptr == L)
		return 0;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
	int argc = lua_gettop(L);
	if (2 == argc)
	{
#if COCOS2D_DEBUG >= 1
		if (!tolua_isstring(L, 1, 0, &tolua_err)) goto tolua_lerror;
		if (!tolua_isstring(L, 2, 0, &tolua_err)) goto tolua_lerror;
#endif
		std::string _souce = tolua_tostring(L, 1, "");
		std::string _target = tolua_tostring(L, 2, "");
		do 
		{
			cocos2d::Data data = cocos2d::FileUtils::getInstance()->getDataFromFile(_souce.c_str());
			if (data.isNull()){
				CCLOG("open src file :%s failed",_souce.c_str());
				break;
			}
			FILE *fp = fopen(_target.c_str(),"wb+");
			if(!fp){
				CCLOG("create new file  :%s failed",_target.c_str());
				break;
			}
			fwrite(data.getBytes(), sizeof(unsigned char), data.getSize(), fp);
			fclose(fp); 
		} while (0);
	
		lua_settop(L, 1);
		return 1;
	}
	CCLOG("'copyFile' function wrong number of arguments: %d, was expecting %d\n", argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(L,"#ferror in function 'copyFile'.",&tolua_err);
	return 0;
#endif
}
static int lua_cocos2dx_copyFile2(lua_State* L)
{
	if (nullptr == L)
		return 0;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
	int argc = lua_gettop(L);
	if (2 == argc)
	{
#if COCOS2D_DEBUG >= 1
		if (!tolua_isstring(L, 1, 0, &tolua_err)) goto tolua_lerror;
		if (!tolua_isstring(L, 2, 0, &tolua_err)) goto tolua_lerror;
#endif
		std::string _souce = tolua_tostring(L, 1, "");
		std::string _target = tolua_tostring(L, 2, "");
		do 
		{
			cocos2d::Data data = cocos2d::FileUtils::getInstance()->getDataFromFile(_souce.c_str());
			if (data.isNull()){
				CCLOG("open src file :%s failed",_souce.c_str());
				break;
			}
			FILE *fp = fopen(_target.c_str(),"wb+");
			if(!fp){
				CCLOG("create new file  :%s failed",_target.c_str());
				break;
			}
			fwrite(data.getBytes(), sizeof(unsigned char), data.getSize(), fp);
			fclose(fp);
		} while (0);
		lua_settop(L, 1);
		return 1;
	}
	CCLOG("'copyFile2' function wrong number of arguments: %d, was expecting %d\n", argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(L,"#ferror in function 'copyFile2'.",&tolua_err);
	return 0;
#endif
}
static int lua_cocos2dx_deleteDownloadDir(lua_State* L)
{
    if (nullptr == L)
        return 0;
    
    int argc = lua_gettop(L);
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
    if (1 == argc)
    {
#if COCOS2D_DEBUG >= 1
        if (!tolua_isstring(L, 1, 0, &tolua_err)) goto tolua_lerror;
#endif
        std::string pathToSave = tolua_tostring(L, 1, "");
		if (pathToSave.size() > 0 && pathToSave[pathToSave.size() - 1] != '/')
		{
			pathToSave.append("/");
		}
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
        
        
        
        
		cocos2d::FileUtils::getInstance()->removeDirectory(pathToSave);
#else
        std::string command = "rd /s /q ";
        
        command += "\"" + pathToSave + "\"";
        system(command.c_str());
#endif
        return 0;
    }
    
    CCLOG("'resetDownloadDir' function wrong number of arguments: %d, was expecting %d\n", argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(L,"#ferror in function 'resetDownloadDir'.",&tolua_err);
    return 0;
#endif
}
static int lua_cocos2dx_addSearchPath(lua_State* L)
{
    if (nullptr == L)
        return 0;
    
    int argc = lua_gettop(L);
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
    
    if (2 == argc)
    {
#if COCOS2D_DEBUG >= 1
        if (!tolua_isstring(L, 1, 0, &tolua_err) ||
            !tolua_isboolean(L, 2, 0, &tolua_err))
            goto tolua_lerror;
#endif
        std::string pathToSave = tolua_tostring(L, 1, "");
        bool before           =  (tolua_toboolean(L, 2, 0)) > 0?true:false;
        std::vector<std::string> searchPaths = FileUtils::getInstance()->getSearchPaths();
        if (before)
        {
            searchPaths.insert(searchPaths.begin(), pathToSave);
        }
        else
        {
            searchPaths.push_back(pathToSave);
        }
        
        FileUtils::getInstance()->setSearchPaths(searchPaths);
        
        return 0;
    }
    CCLOG("'addSearchPath' function wrong number of arguments: %d, was expecting %d\n", argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(L,"#ferror in function 'addSearchPath'.",&tolua_err);
    return 0;
#endif
}
static int lua_cocos2dx_getMd5(lua_State* L)
{
    if (nullptr == L)
        return 0;
    
    int argc = lua_gettop(L);
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
    
    if (1 == argc)
    {
#if COCOS2D_DEBUG >= 1
        if (!tolua_isstring(L, 1, 0, &tolua_err))           
            goto tolua_lerror;
#endif
        std::string src = tolua_tostring(L, 1, "");
        
        CMD5 iMD5(src.c_str());
		iMD5.GenerateMD5(src.c_str(), src.length());
	
		tolua_pushstring(L, iMD5.ToString().c_str());
		return 1;
    }
    CCLOG("'addSearchPath' function wrong number of arguments: %d, was expecting %d\n", argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(L,"#ferror in function 'getMd5'.",&tolua_err);
    return 0;
#endif
}
static int lua_cocos2dx_ObjIsExistInC(lua_State* tolua_S)
{
	int argc = 0;
	bool ok  = true;
	tolua_Error tolua_err;
	argc = lua_gettop(tolua_S);
	if (argc == 2) 
	{
		std::string className;
		do{
			ok &= luaval_to_std_string(tolua_S, 1, &className); 
			if (!ok) { break; }
			if (!tolua_isusertype(tolua_S,2,className.c_str(),0,&tolua_err)) goto tolua_lerror;
			void* cobj = tolua_tousertype(tolua_S,2,0);
			if (!cobj) 
			{
			
			
				int top = lua_gettop(tolua_S);
				int nResult = 0;
				try
				{
					lua_getglobal(tolua_S, "ObjIsExistInCError");
				
					if(!lua_isfunction(tolua_S, -1))
					{
						log("invalid function\n");
						goto RFEXIT;
					}
					nResult = lua_pcall(tolua_S, 0, 0, 0);
					if(nResult == 0)
					{
					}
					else
					{
						log("[LUA ERROR] %s", lua_tostring(tolua_S, - 1));
					}
				}
				catch (...) {
					log("[LUA ERROR]");
				}
RFEXIT:
			
				lua_settop(tolua_S, top);
				if(nResult != 0)
					log("[LuaEngine] call function %s(...) failed\n", "ObjIsExistInCError");  
				tolua_pushboolean(tolua_S,false);
			}else{
				tolua_pushboolean(tolua_S,true);
			}
			return 1;
		} while (0);
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ObjIsExistInC",argc, 1);
	return 0;
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_ObjIsExistInC'.",&tolua_err);
	return 0;
}
static int lua_cocos2dx_setCharIndexReplace(lua_State* L)
{
	if (nullptr == L)
		return 0;
	bool ok  = true;
	int argc = lua_gettop(L);
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
	if (1 == argc)
	{
		int arg0;
		do 
		{
			ok &= luaval_to_int32(L, 1, &arg0); 
			if (!ok) { break; }
            TextureManager::setCharIndexReplace(arg0);
			return 0;
		} while (0);
	}
	CCLOG("'setCharIndexReplace' function wrong number of arguments: %d, was expecting %d\n", argc, 1);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(L,"#ferror in function 'setCharIndexReplace'.",&tolua_err);
	return 0;
#endif
}
int register_assetsmanager_test_sample(lua_State* L)
{
    tolua_open(L);
    tolua_module(L, NULL, 0);
    tolua_beginmodule(L, NULL);
    tolua_function(L, "createDownloadDir", lua_cocos2dx_createDownloadDir);
    tolua_function(L, "deleteDownloadDir", lua_cocos2dx_deleteDownloadDir);
    tolua_function(L, "addSearchPath", lua_cocos2dx_addSearchPath);
	tolua_function(L, "getMD5", lua_cocos2dx_getMd5);
	tolua_function(L, "getCurrentTime", lua_cocos2dx_getCurrentTime);
	tolua_function(L, "createCopyfiles", lua_cocos2dx_createCopyfiles);
	tolua_function(L, "copyFile", lua_cocos2dx_copyFile);
	tolua_function(L, "copyFile2", lua_cocos2dx_copyFile2);
	tolua_function(L, "setCharIndexReplace", lua_cocos2dx_setCharIndexReplace);
	tolua_function(L, "ObjIsExistInC", lua_cocos2dx_ObjIsExistInC);
    tolua_endmodule(L);
    return 0;
}
