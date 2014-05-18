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

#include <iostream>
#include "FScriptEngineManager.h"
#include "Utils/FUtils.h"
#include "FScriptLuaEngine.h"
#include "FScriptPythonEngine.h"
#include "FScriptJsEngine.h"
#include "FScriptProtocol.h"
#include <map>
#include "FCommon.h"

using namespace std;
using namespace spider::utils;
using namespace spider::script;

FScriptEngineManager* FScriptEngineManager::m_defaultManager = NULL;

/**
 @brief Get default FScriptEngineManager.
 @return default FScriptEngineManager.
*/
FScriptEngineManager* FScriptEngineManager::defaultManager()
{
    if(m_defaultManager == NULL)
    {
        m_defaultManager = new FScriptEngineManager();
        m_defaultManager->init();
    }
    return m_defaultManager;
}

FScriptEngineManager::FScriptEngineManager()
{
    this->m_scriptEngines = new map<string,FScriptProtocol*>();
}

FScriptEngineManager::~FScriptEngineManager()
{
    for(map<string,FScriptProtocol*>::iterator it = m_scriptEngines->begin();
        it != m_scriptEngines->end();++it)
    {
        delete it->second;
    }
    this->m_scriptEngines->clear();
    delete this->m_scriptEngines;
    this->m_scriptEngines = NULL;
}

void FScriptEngineManager::init()
{
    FIniFile* iniFile = new FIniFile();
    if(iniFile->Load("config/script.ini"))
    {
        bool useLua = iniFile->Readbool("config","lua",false);
        bool usePython = iniFile->Readbool("config","python",false);
        bool useJs = iniFile->Readbool("config","js",false);
        if(useLua) this->registScriptEngine(new FScriptLuaEngine());
    }
    delete iniFile;
    iniFile = NULL;
}

/**
 @brief regist script engine to FScriptEngineManager.
 @param scriptEngine holding the script engine,which may be python,lua,js.
*/
void FScriptEngineManager::registScriptEngine(FScriptProtocol* scriptEngine)
{
    if(scriptEngine == NULL)
    {
        FLog("registScriptEngine param is null!");
    }
    else
    {
        (*m_scriptEngines)[string(scriptEngine->getScriptType())] = scriptEngine;
    }
}

/**
 @brief Execute script code contained in the given string.
 @param codes holding the valid script code that should be executed.
 @return 0 if the string is executed correctly.
 @return other if the string is executed wrongly.
*/
int FScriptEngineManager::executeString(const char* language,const char* codes)
{
    int nRet = 0;
    string key = language;
    if(m_scriptEngines->find(key) != m_scriptEngines->end())
    {
        nRet = (*m_scriptEngines)[key]->executeString(codes);
    }
    return nRet;
}
/**
 @brief Execute a script file.
 @param filename String object holding the filename of the script file that is to be executed
*/
int FScriptEngineManager::executeScriptFile(const char* filename)
{
    int nRet = 0;
    for(map<string,FScriptProtocol*>::iterator it = m_scriptEngines->begin();
        it != m_scriptEngines->end();++it)
    {
        FScriptProtocol* scriptEngine = (FScriptProtocol*)(it->second);
        int temp = scriptEngine->executeScriptFile(filename);
        nRet = nRet > 0 ? nRet :temp;
    }
    return nRet;
}
/**
 @brief Execute a script file.
 @param filename String object holding the filename of the script file that is to be executed
 @param func String object holding the function of the script file that is to be executed
 @param format String object holding the param of the function that is to be executed
*/
int FScriptEngineManager::executeScriptFileFunc(const char* filename,const char* func,const char* format, ...)
{
    va_list args;
    va_start(args,format);
    vsprintf(m_buffer,format,args);
    va_end(args);
    int nRet = 0;
    for(map<string,FScriptProtocol*>::iterator it = m_scriptEngines->begin();
        it != m_scriptEngines->end();++it)
    {
        FScriptProtocol* scriptEngine = (FScriptProtocol*)(it->second);
        int temp = scriptEngine->executeScriptFileFunc(filename,func,m_buffer);
        nRet = nRet > 0 ? nRet :temp;
    }
    return nRet;
}
