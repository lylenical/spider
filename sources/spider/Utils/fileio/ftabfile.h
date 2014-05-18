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

#ifndef __FTABFILE_H__
#define __FTABFILE_H__

#include <map>
#include <vector>
#include <iostream>
#include <string>

using namespace std;
namespace spider
{
    namespace utils
    {
        typedef std::vector<std::string> ROWLINE;

        class FTabFile{
        public:
            int			m_Width;
            int			m_Height;
            std::vector<std::string> colList;
            std::vector<std::string> rowList;
            std::map<int,ROWLINE> allMap;
        private:
            //bool		GetValue(int nRow, int nColumn, const char* lpRString, DWORD dwSize);
            int			Str2Col(const char* szColumn);
        public:
            FTabFile();
            ~FTabFile();
            bool		Load(const char* FileName);
            bool		Save(const char* FileName);
            bool		LoadPack(const char* FileName);
            int			FindRow(const char* szRow);//返回以1为起点的值
            int			FindColumn(const char* szColumn);//返回以1为起点的值
            string		Col2Str(int nCol);
            int			GetWidth() { return m_Width;};
            int			GetHeight() { return m_Height;};
            string		GetString(int nRow, const char* szColumn, const char* lpDefault);
            string		GetString(int nRow, int nColumn, const char* lpDefault);
            string		GetString(const char* szRow, const char* szColumn, const char* lpDefault);
            int 		GetInteger(int nRow, const char* szColumn, int nDefault);
            int	    	GetInteger(int nRow, int nColumn, int nDefault);
            int		    GetInteger(const char* szRow, const char* szColumn, int nDefault);
            float		GetFloat(int nRow, const char* szColumn, float fDefault);
            float		GetFloat(int nRow, int nColumn, float fDefault);
            float		GetFloat(const char* szRow, const char* szColumn, float fDefault);
            void		Clear();
        };
    }
}

#endif
