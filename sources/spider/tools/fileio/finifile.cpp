/*
 * date:2011-7-22
 * auther:liangrongze
 * desc:ini文件读取类
*/
#include "stdio.h"
#include <iostream>
#include "string.h"
#include "finifile.h"
#include <vector>
#include <fstream>
#include "fstring.h"

using namespace std;


CFIniFile::CFIniFile (){

}

CFIniFile::~CFIniFile (){
}

int CFIniFile::GetVersion (void){
    return 0x0001;
}

bool CFIniFile::Load (const char* FileName){
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

bool CFIniFile::WriteIniFile (const char* pFileName){
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

void CFIniFile::WriteString (const char* pSection, const char* pKey, const char* pValue){
    AddSection(pSection);
    lpAllItem[pSection][pKey] = pValue;
}

void CFIniFile::Writebool (const char* pSection, const char* pKey, bool Value){
    char Val [2] = {"0"};
    sprintf(Val,"%d",Value);
    WriteString(pSection,pKey,Val);
}

void CFIniFile::WriteInt (const char* pSection, const char* pKey, int Value){
    char Val [12];
    sprintf (Val, "%d", Value);
    WriteString(pSection, pKey, Val);
}

void CFIniFile::WriteDouble (const char* pSection, const char* pKey, double Value){
    char Val [32];
    sprintf (Val, "%1.10lE", Value);
    WriteString (pSection, pKey, Val);
}

string CFIniFile::ReadString(const char* pSection, const char* pKey, const char* pDefault){
    if(FindKey(pSection,pKey)){
        string ret = lpAllItem[pSection][pKey];
        return lpAllItem[pSection][pKey];
    }
    return string(pDefault);
}

bool CFIniFile::FindKey(const char* pSection, const char* pKey){
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

bool CFIniFile::Readbool (const char* pSection, const char* pKey, bool Default){
    char Val [2] = {"0"};
    if(Default != 0)
    {
        Val [0] = '1';
    }
    return (atoi(ReadString(pSection,pKey,Val).c_str()))?true:false;
}

int CFIniFile::ReadInt (const char* pSection, const char* pKey, int Default){
    char Val [12];
    sprintf (Val,"%d", Default);
    return (atoi(ReadString (pSection, pKey, Val).c_str()));
}

double CFIniFile::ReadDouble (const char* pSection, const char* pKey, double Default){
    double Val;
    char m_result[50] = "";
    sprintf (m_result, "%1.10lE", Default);
    sscanf (ReadString (pSection, pKey, m_result).c_str(), "%lE", &Val);
    return Val;
}

bool CFIniFile::DelKey (const char* pSection, const char* pKey){
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

void CFIniFile::AddKey(string pSection, string pKey, string pValue){
    AddSection(pSection);
    KeyItem::iterator kitr = lpAllItem[pSection].find(pKey);
    if(kitr == lpAllItem[pSection].end()){
        lpAllItem[pSection][pKey] = pValue;
    }
}

void CFIniFile::AddSection(string pSection){
    map<string,KeyItem>::iterator itr = lpAllItem.find(pSection);
    if(itr == lpAllItem.end()){
        lpAllItem[pSection] = KeyItem();
    }
}

void CFIniFile::Close(){
    lpAllItem.clear();
}

