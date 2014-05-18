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
#include "ftabfile.h"
#include <string>
#include <iostream>
#include <fstream>
#include "stdlib.h"
#include "fstring.h"

using namespace std;
using namespace spider::utils;

FTabFile::FTabFile(){
    m_Width = 0;
    m_Height = 0;
}

FTabFile::~FTabFile(){
    Clear();
}

bool FTabFile::Load(const char* FileName){
    ifstream fin(FileName);
    if(!fin){
        return false;
    }
    string strTemp;
    string delim = "\t";
    int row = 0;
    vector<string> strlist;
    while(getline(fin,strTemp)){
        strlist.clear();
        split(strTemp,delim,strlist);
        replace_all(strTemp,"\r\n","");
        replace_all(strTemp,"\n","");
        if(row == 1){
            for(int i=0;i<(int)strlist.size();i++){
                colList.push_back(strlist.at(i));
            }
        }
        rowList.push_back(strlist[0]);
        allMap[row] = strlist;
        row ++;
    }
    m_Width = colList.size();
    m_Height = allMap.size();
    return true;
}

bool FTabFile::Save(const char* FileName){
    return false;
}

bool FTabFile::LoadPack(const char* FileName){
    return false;
}

int FTabFile::FindRow(const char* szRow){
    for(int i=0;i<(int)rowList.size();i++){
        if(rowList[i] == szRow){
            return i;
        }
    }
    return -1;
}

int FTabFile::FindColumn(const char* szColumn){
    for(int i=0;i<(int)colList.size();i++){
        if(colList[i] == szColumn){
            return i;
        }
    }
    return -1;
}

string FTabFile::Col2Str(int nCol){
    if(nCol >= 0){
        if((int)colList.size() > nCol){
            return colList[nCol].c_str();
        }
        else{
            return string();
        }
    }
    else{
        nCol = -nCol;
        if((int)colList.size() > nCol){
            return colList[colList.size()-nCol].c_str();
        }
        else{
            return string();
        }
    }
}

string FTabFile::GetString(int nRow, const char* szColumn, const char* lpDefault){
    int nCol = FindColumn(szColumn);
    return GetString(nRow,nCol,lpDefault);
}

string FTabFile::GetString(int nRow, int nColumn, const char* lpDefault){
    if(nRow < 0 || (int)allMap.size() <= nRow){
        return string(lpDefault);
    }
    if(nColumn < 0 || (int)colList.size() <= nColumn){
        return string(lpDefault);
    }
    try{
        return allMap[nRow][nColumn];
    }
    catch(...){
        return string(lpDefault);
    }
}

string FTabFile::GetString(const char* szRow, const char* szColumn, const char* lpDefault){
    int nRow = FindRow(szRow);
    int nCol = FindColumn(szColumn);
    return GetString(nRow,nCol,lpDefault);
}

int FTabFile::GetInteger(int nRow, const char* szColumn, int nDefault){
    int nCol = FindColumn(szColumn);
    return GetInteger(nRow,nCol,nDefault);
}

int FTabFile::GetInteger(int nRow, int nColumn, int nDefault){
    if(nRow < 0 || (int)allMap.size() <= nRow){
        return nDefault;
    }
    if(nColumn < 0 || (int)colList.size() <= nColumn){
        return nDefault;
    }
    try{
        return atoi(allMap[nRow][nColumn].c_str());
    }
    catch(...){
        return nDefault;
    }
}

int FTabFile::GetInteger(const char* szRow, const char* szColumn, int nDefault){
    int nRow = FindRow(szRow);
    int nCol = FindColumn(szColumn);
    return GetInteger(nRow,nCol,nDefault);
}

float FTabFile::GetFloat(int nRow, const char* szColumn, float fDefault){
    int nCol = FindColumn(szColumn);
    return GetFloat(nRow,nCol,fDefault);
}

float FTabFile::GetFloat(int nRow, int nColumn, float fDefault){
    if(nRow < 0 || (int)allMap.size() <= nRow){
        return fDefault;
    }
    if(nColumn < 0 || (int)colList.size() <= nColumn){
        return fDefault;
    }
    try{
        return atof(allMap[nRow][nColumn].c_str());
    }
    catch(...){
        return fDefault;
    }
}

float FTabFile::GetFloat(const char* szRow, const char* szColumn, float fDefault){
    int nRow = FindRow(szRow);
    int nCol = FindColumn(szColumn);
    return GetFloat(nRow,nCol,fDefault);
}

void FTabFile::Clear(){
    allMap.clear();
    colList.clear();
}

