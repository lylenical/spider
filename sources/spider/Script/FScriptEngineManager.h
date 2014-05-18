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
#ifndef __FSCRIPTENGINEMANAGER_H__
#define __FSCRIPTENGINEMANAGER_H__

#include <map>

using namespace std;

namespace spider
{
    namespace script
    {
        class FScriptProtocol;
        class FScriptEngineManager
        {
        public:
            ~FScriptEngineManager();
            /**
             @brief Get default FScriptEngineManager.
             @return default FScriptEngineManager.
            */
            static FScriptEngineManager* defaultManager();
            /**
             @brief Execute script code contained in the given string.
             @param codes holding the valid script code that should be executed.
             @return 0 if the string is executed correctly.
             @return other if the string is executed wrongly.
             */
            int executeString(const char* language,const char* codes);
            /**
             @brief Execute a script file.
             @param filename String object holding the filename of the script file that is to be executed
             */
            int executeScriptFile(const char* filename);
            /**
             @brief Execute a script file.
             @param filename String object holding the filename of the script file that is to be executed
             @param func String object holding the function of the script file that is to be executed
             @param format String object holding the param of the function that is to be executed
             */
            int executeScriptFileFunc(const char* filename,const char* func,const char* format, ...);
        private:
            FScriptEngineManager();
            void init();
            /**
             @brief regist script engine to FScriptEngineManager.
             @param scriptEngine holding the script engine,which may be python,lua,js.
            */
            void registScriptEngine(FScriptProtocol* scriptEngine);

        private:
            map<string,FScriptProtocol*>* m_scriptEngines;
            static FScriptEngineManager* m_defaultManager;
            char m_buffer[1024];
        };
    }
}

#endif
