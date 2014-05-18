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
#ifndef __FSCRIPTPROTOCOL_H__
#define __FSCRIPTPROTOCOL_H__

#include <vector>

namespace spider
{
    namespace script
    {
        class FScriptProtocol
        {
        public:
            virtual ~FScriptProtocol(){}
            /** Get script type */
            virtual const char* getScriptType() = 0;
            /**
             @brief Execute script code contained in the given string.
             @param codes holding the valid script code that should be executed.
             @return 0 if the string is executed correctly.
             @return other if the string is executed wrongly.
             */
            virtual int executeString(const char* codes) = 0;
            /**
             @brief Execute a script file.
             @param filename String object holding the filename of the script file that is to be executed
             */
            virtual int executeScriptFile(const char* filename) = 0;
            /**
             @brief Execute a script file.
             @param filename String object holding the filename of the script file that is to be executed
             @param func String object holding the function of the script file that is to be executed
             @param format String object holding the param of the function that is to be executed
             */
            virtual int executeScriptFileFunc(const char* filename,const char* func,const char* format, ...) = 0;
             /**
             @brief Add a path to find script files in
             @param path to be added to the script path
             */
            virtual void addSearchPath(const char* path) = 0;
            /** function for c++ call back lua funtion */
            virtual int executeEventWithArgs(int nHandler, std::vector<void *>* pArgs){ return 0; }
        };
    }
}

#endif
