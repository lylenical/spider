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
#include "FScriptLuaEngine.h"
#include <iostream>
#include "FLuaStack.h"
#include "stdarg.h"
#include <string>

using namespace std;
using namespace spider::script;

FScriptLuaEngine* FScriptLuaEngine::m_defaultEngine = NULL;

FScriptLuaEngine::FScriptLuaEngine()
{
    this->m_defaultStack = new FLuaStack();
}

FScriptLuaEngine::~FScriptLuaEngine()
{
    delete this->m_defaultStack;
    this->m_defaultStack = NULL;
}

/**
 @brief Get default FScriptLuaEngine.
 @return default FScriptLuaEngine.
*/
FScriptLuaEngine* FScriptLuaEngine::defaultEngine()
{
    if(m_defaultEngine == NULL)
        m_defaultEngine = new FScriptLuaEngine();
    return m_defaultEngine;
}
/**
 @brief Execute script code contained in the given string.
 @param codes holding the valid script code that should be executed.
 @return 0 if the string is executed correctly.
 @return other if the string is executed wrongly.
*/
int FScriptLuaEngine::executeString(const char* codes)
{
    return FScriptLuaEngine::defaultStack()->executeString(codes);
}
/**
 @brief Execute a script file.
 @param filename String object holding the filename of the script file that is to be executed
 */
int FScriptLuaEngine::executeScriptFile(const char* filename)
{
    string path = filename;
    path = path + ".lua";
    return FScriptLuaEngine::defaultStack()->executeScriptFile(path.c_str());
}

/**
 @brief Execute a script file.
 @param filename String object holding the filename of the script file that is to be executed
 @param func String object holding the function of the script file that is to be executed
 @param format String object holding the param of the function that is to be executed
 */
int FScriptLuaEngine::executeScriptFileFunc(const char* filename,const char* func,const char* format, ...)
{
    va_list args;
    va_start(args,format);
    int ret = FScriptLuaEngine::defaultStack()->executeScriptFileFunc(filename,func,format,args);
    va_end(args);
    return ret;
}
/**
 @brief Add a path to find script files in
 @param path to be added to the script path
*/
void FScriptLuaEngine::addSearchPath(const char* path)
{
    return FScriptLuaEngine::defaultStack()->addSearchPath(path);
}
/** function for c++ call back lua funtion */
int FScriptLuaEngine::executeEventWithArgs(int nHandler, std::vector<void *>* pArgs)
{
    return FScriptLuaEngine::defaultStack()->executeEventWithArgs(nHandler,pArgs);
}
