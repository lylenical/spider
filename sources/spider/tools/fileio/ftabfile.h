/*
 * date:2011-7-22
 * auther:liangrongze
 * desc:工具库，表格文件
*/

#ifndef __FTABFILE_H__
#define __FTABFILE_H__

#include <map>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

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

#endif
