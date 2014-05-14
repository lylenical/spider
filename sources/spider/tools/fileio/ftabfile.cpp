/*
 * date:2011-7-22
 * auther:liangrongze
 * desc:工具库，表格文件
*/

#include "ftabfile.h"
#include <string>
#include <iostream>
#include <fstream>
#include "stdlib.h"
#include "fstring.h"


using namespace std;

CFTabFile::CFTabFile(){
    m_Width = 0;
    m_Height = 0;
}

CFTabFile::~CFTabFile(){
    Clear();
}

bool CFTabFile::Load(const char* FileName){
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

bool CFTabFile::Save(const char* FileName){
    return false;
}

bool CFTabFile::LoadPack(const char* FileName){
    return false;
}

int CFTabFile::FindRow(const char* szRow){
    for(int i=0;i<(int)rowList.size();i++){
        if(rowList[i] == szRow){
            return i;
        }
    }
    return -1;
}

int CFTabFile::FindColumn(const char* szColumn){
    for(int i=0;i<(int)colList.size();i++){
        if(colList[i] == szColumn){
            return i;
        }
    }
    return -1;
}

string CFTabFile::Col2Str(int nCol){
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

string CFTabFile::GetString(int nRow, const char* szColumn, const char* lpDefault){
    int nCol = FindColumn(szColumn);
    return GetString(nRow,nCol,lpDefault);
}

string CFTabFile::GetString(int nRow, int nColumn, const char* lpDefault){
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

string CFTabFile::GetString(const char* szRow, const char* szColumn, const char* lpDefault){
    int nRow = FindRow(szRow);
    int nCol = FindColumn(szColumn);
    return GetString(nRow,nCol,lpDefault);
}

int CFTabFile::GetInteger(int nRow, const char* szColumn, int nDefault){
    int nCol = FindColumn(szColumn);
    return GetInteger(nRow,nCol,nDefault);
}

int CFTabFile::GetInteger(int nRow, int nColumn, int nDefault){
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

int CFTabFile::GetInteger(const char* szRow, const char* szColumn, int nDefault){
    int nRow = FindRow(szRow);
    int nCol = FindColumn(szColumn);
    return GetInteger(nRow,nCol,nDefault);
}

float CFTabFile::GetFloat(int nRow, const char* szColumn, float fDefault){
    int nCol = FindColumn(szColumn);
    return GetFloat(nRow,nCol,fDefault);
}

float CFTabFile::GetFloat(int nRow, int nColumn, float fDefault){
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

float CFTabFile::GetFloat(const char* szRow, const char* szColumn, float fDefault){
    int nRow = FindRow(szRow);
    int nCol = FindColumn(szColumn);
    return GetFloat(nRow,nCol,fDefault);
}

void CFTabFile::Clear(){
    allMap.clear();
    colList.clear();
}

