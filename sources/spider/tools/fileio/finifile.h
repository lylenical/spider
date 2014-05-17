/*
 * date:2011-7-22
 * auther:liangrongze
 * desc:ini文件读取类
*/
#ifndef __FINIFILE_H__
#define __FINIFILE_H__

#include <iostream>
#include <map>
#include "string.h"

using namespace std;
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


#endif
