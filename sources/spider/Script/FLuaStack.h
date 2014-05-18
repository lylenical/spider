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
#ifndef __FLuaStack_H__
#define __FLuaStack_H__

extern "C" {
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}
#include "tolua++.h"
#include <vector>

namespace spider
{
    namespace script
    {
        class FLuaStack
        {
        public:
            FLuaStack();
            virtual ~FLuaStack();
            /**
             @brief Execute a code string.
             @param codes String object holding the code string
            */
            virtual int executeString(const char* codes);
            /**
             @brief Execute a script file.
             @param filename String object holding the filename of the script file that is to be executed
            */
            virtual int executeScriptFile(const char* filename);
            /**
             @brief Execute a script file.
             @param filename String object holding the filename of the script file that is to be executed
             @param func String object holding the function of the script file that is to be executed
             @param format String object holding the param of the function that is to be executed
            */
            virtual int executeScriptFileFunc(const char* filename,const char* func,const char* format, ...);
            /**
             @brief Add a path to find script files in
             @param path to be added to the script path
            */
            virtual void addSearchPath(const char* path);
            /** function for c++ call back lua funtion */
            virtual int executeEventWithArgs(int nHandler, std::vector<void *>* pArgs);
        private:
            lua_State* m_state;
            char m_buffer[1024];
        };
    }
}

#endif
