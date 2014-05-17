/*
 * date:2011-7-22
 * auther:liangrongze
 * desc:
*/
#include "fstring.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void split(string& s, string& delim,vector<string >& ret)
{
    size_t last = 0;
    size_t index=s.find_first_of(delim,last);
    while (index!=std::string::npos)
    {
        ret.push_back(s.substr(last,index-last));
        last=index+1;
        index=s.find_first_of(delim,last);
    }
    if (index-last>0)
    {
        ret.push_back(s.substr(last,index-last));
    }
}

string& replace_all(string& str,const string& old_value,const string& new_value)
{
    while(true){
        string::size_type   pos(0);
        if((pos=str.find(old_value))!=string::npos)
            str.replace(pos,old_value.length(),new_value);
        else   break;
    }
    return str;
}

string& trim(string &s){
    if (s.empty())
    {
        return s;
    }
    s.erase(0,s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
    return s;
}

string int2str(int num){
    if(num == 0){
        return "0";
    }
    string str = "";
    int num_ = num>0?num:-1*num;
    while(num_){
        str = (char)(num % 10 + 48) + str;
        num /= 10;
    }
    if(num < 0){
        str = "-" + str;
    }
    return str;
}
