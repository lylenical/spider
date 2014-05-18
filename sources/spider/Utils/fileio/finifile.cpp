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
#include "stdio.h"
#include <iostream>
#include "string.h"
#include "finifile.h"
#include <vector>
#include <fstream>
#include "stdlib.h"
#include "fstring.h"

using namespace std;
using namespace spider::utils;

FIniFile::FIniFile (){

}

FIniFile::~FIniFile (){
}

int FIniFile::GetVersion (void){
    return 0x0001;
}

bool FIniFile::Load (const char* FileName){
    ifstream fin(FileName);
    if(!fin){
        return false;
    }
    string strTemp;
    string section;
    string delim = "=";
    size_t index = 0;
    vector<string> strlist;
    while(getline(fin,strTemp)){
        strlist.clear();
        trim(strTemp);
        replace_all(strTemp,"\r\n","");
        replace_all(strTemp,"\n","");
        replace_all(strTemp,"\r","");
        if(strTemp.size() <= 0){
            continue;
        }
        if(strTemp[0] == ';'){
            continue;
        }
        if(strTemp[0] == '['){
            index = strTemp.find("]");
            if(index == string::npos){
                printf("load %s get an error! can not find ]",FileName);
                return false;
            }
            section = strTemp.substr(1,index-1);
            AddSection((char *)section.c_str());
            continue;
        }
        split(strTemp,delim,strlist);
        if(strlist.size() <= 1){
            continue;
        }
        AddKey(section,strlist[0],strlist[1]);
    }
    return true;
}

bool FIniFile::WriteIniFile (const char* pFileName){
    ofstream fout(pFileName);
    if(!fout){
        return false;
    }
    for(map<string,KeyItem>::iterator iter = lpAllItem.begin(); iter != lpAllItem.end();iter++){
        fout<<"["<<iter->first.c_str()<<"]"<<endl;
        for(KeyItem::iterator kiter = iter->second.begin();kiter != iter->second.end();kiter++){
            fout<<kiter->first.c_str()<<"="<<kiter->second.c_str()<<endl;
        }
        fout<<endl;
    }
    return true;
}

void FIniFile::WriteString (const char* pSection, const char* pKey, const char* pValue){
    AddSection(pSection);
    lpAllItem[pSection][pKey] = pValue;
}

void FIniFile::Writebool (const char* pSection, const char* pKey, bool Value){
    char Val [2] = {"0"};
    sprintf(Val,"%d",Value);
    WriteString(pSection,pKey,Val);
}

void FIniFile::WriteInt (const char* pSection, const char* pKey, int Value){
    char Val [12];
    sprintf (Val, "%d", Value);
    WriteString(pSection, pKey, Val);
}

void FIniFile::WriteDouble (const char* pSection, const char* pKey, double Value){
    char Val [32];
    sprintf (Val, "%1.10lE", Value);
    WriteString (pSection, pKey, Val);
}

string FIniFile::ReadString(const char* pSection, const char* pKey, const char* pDefault){
    if(FindKey(pSection,pKey)){
        string ret = lpAllItem[pSection][pKey];
        return lpAllItem[pSection][pKey];
    }
    return string(pDefault);
}

bool FIniFile::FindKey(const char* pSection, const char* pKey){
    map<string,KeyItem>::iterator itr = lpAllItem.find(pSection);
    if(itr == lpAllItem.end()){
        return false;
    }
    KeyItem::iterator kitr = lpAllItem[pSection].find(pKey);
    if(kitr == lpAllItem[pSection].end()){
        return false;
    }
    return true;
}

bool FIniFile::Readbool (const char* pSection, const char* pKey, bool Default){
    string temp = ReadString(pSection,pKey,"0");
    return temp == "True" || temp == "true" || temp == "TRUE" || temp == "1";
}

int FIniFile::ReadInt (const char* pSection, const char* pKey, int Default){
    char Val [12];
    sprintf (Val,"%d", Default);
    return (atoi(ReadString (pSection, pKey, Val).c_str()));
}

double FIniFile::ReadDouble (const char* pSection, const char* pKey, double Default){
    double Val;
    char m_result[50] = "";
    sprintf (m_result, "%1.10lE", Default);
    sscanf (ReadString (pSection, pKey, m_result).c_str(), "%lE", &Val);
    return Val;
}

bool FIniFile::DelKey (const char* pSection, const char* pKey){
    map<string,KeyItem>::iterator itr = lpAllItem.find(pSection);
    if(itr == lpAllItem.end()){
        return false;
    }
    KeyItem::iterator kitr = lpAllItem[pSection].find(pKey);
    if(kitr == lpAllItem[pSection].end()){
        return false;
    }
    lpAllItem[pSection].erase(kitr);
    return true;
}

void FIniFile::AddKey(string pSection, string pKey, string pValue){
    AddSection(pSection);
    KeyItem::iterator kitr = lpAllItem[pSection].find(pKey);
    if(kitr == lpAllItem[pSection].end()){
        lpAllItem[pSection][pKey] = pValue;
    }
}

void FIniFile::AddSection(string pSection){
    map<string,KeyItem>::iterator itr = lpAllItem.find(pSection);
    if(itr == lpAllItem.end()){
        lpAllItem[pSection] = KeyItem();
    }
}

void FIniFile::Close(){
    lpAllItem.clear();
}

