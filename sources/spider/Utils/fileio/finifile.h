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
#ifndef __FINIFILE_H__
#define __FINIFILE_H__

#include <iostream>
#include <map>
#include "string.h"

using namespace std;

namespace spider
{
    namespace utils
    {
        typedef map<string,string> KeyItem;

        class FIniFile
        {
        public:
                    FIniFile    (void);
                    ~FIniFile   (void);
            int    GetVersion  (void);
            bool    Load (const char* pFileName);
            bool    Readbool    (const char* pSection, const char* pKey, bool   Default);
            int     ReadInt     (const char* pSection, const char* pKey, int    Default);
            double  ReadDouble  (const char* pSection, const char* pKey, double Default);
            string  ReadString  (const char* pSection, const char* pKey, const char*   pDefault);

            void    Writebool   (const char* pSection, const char* pKey, bool   Value);
            void    WriteInt    (const char* pSection, const char* pKey, int    Value);
            void    WriteDouble (const char* pSection, const char* pKey, double Value);
            void    WriteString (const char* pSection, const char* pKey, const char*  pValue);

            bool    WriteIniFile (const char* pFileName);
            bool	DelKey (const char* pSection, const char* pKey);
            void    Close();

        protected:
            map<string,KeyItem> lpAllItem;
            void    AddSection(string);
            void    AddKey     (string pSection, string pKey, string pValue);
            bool    FindKey(const char* pSection, const char* pKey);
        };
    }
}

#endif
