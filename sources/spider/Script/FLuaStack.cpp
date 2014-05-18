/****************************************************************************
 Copyright (c) 2014 www.fio-tech.com

 http://www.fio-tech.com

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
#include "FLuaStack.h"
#include "FCommon.h"
#include "stdarg.h"
#include "lua_support/LuaUtils.h"
#include "lua_support/LuaNetwork.h"

using namespace spider::script;

FLuaStack::FLuaStack()
{
    this->m_state = luaL_newstate();
    luaL_openlibs(m_state);
    tolua_Network_open(m_state);
    tolua_Utils_open(m_state);
}

FLuaStack::~FLuaStack()
{
    lua_close(this->m_state);
    this->m_state = NULL;
}

int FLuaStack::executeString(const char* codes)
{
    int nRet =luaL_loadstring(m_state, codes);
    if(nRet == 0)
    {
        nRet = lua_pcall(m_state, 0, 0, 0);
    }
    if(nRet)
    {
        FLog("[LUA ERROR] %s",lua_tostring(m_state,-1));
        lua_pop(m_state,1);
        return 1;
    }
    return nRet;
}
/**
 @brief Execute a script file.
 @param filename String object holding the filename of the script file that is to be executed
 */
int FLuaStack::executeScriptFile(const char* filename)
{
    int nRet = luaL_dofile(m_state, filename);
    if(nRet != 0)
    {
        FLog("[LUA ERROR] %s",lua_tostring(m_state,-1));
        lua_pop(m_state,1);
    }
    return nRet;
}
 /**
 @brief Execute a script file.
 @param filename String object holding the filename of the script file that is to be executed
 @param func String object holding the function of the script file that is to be executed
 @param format String object holding the param of the function that is to be executed
 */
 int FLuaStack::executeScriptFileFunc(const char* filename,const char* func,const char* format, ...)
 {
    va_list args;
    va_start(args,format);
    vsprintf(m_buffer,format,args);
    va_end(args);
    return 0;
 }
 /**
 @brief Add a path to find script files in
 @param path to be added to the script path
 */
void FLuaStack::addSearchPath(const char* path)
{
    lua_getglobal(m_state, "package");                                  /* L: package */
    lua_getfield(m_state, -1, "path");                /* get package.path, L: package path */
    const char* cur_path =  lua_tostring(m_state, -1);
    lua_pushfstring(m_state, "%s;%s/?.lua", cur_path, path);            /* L: package path newpath */
    lua_setfield(m_state, -3, "path");          /* package.path = newpath, L: package path */
    lua_pop(m_state, 2);
}
/** function for c++ call back lua funtion */
int FLuaStack::executeEventWithArgs(int nHandler, std::vector<void *>* pArgs)
{
    return 0;
}
