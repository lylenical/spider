/*
 * date:2011-7-22
 * auther:liangrongze
 * desc:
*/
#ifndef __FSTRING_H__
#define __FSTRING_H__

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void split(string& s, string& delim,vector<string >& ret);

string& replace_all(string& str,const string& old_value,const string& new_value);

string& trim(string &s);
string int2str(int num);

#endif

