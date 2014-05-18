/*
** Lua binding: Utils
** Generated automatically by tolua++-1.0.92 on 05/18/14 22:41:57.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_Utils_open (lua_State* tolua_S);

#include "LuaNetwork.h"
using namespace spider::utils;

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_FTabFile (lua_State* tolua_S)
{
 FTabFile* self = (FTabFile*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_FIniFile (lua_State* tolua_S)
{
 FIniFile* self = (FIniFile*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"FTabFile");
 tolua_usertype(tolua_S,"std::map<int,ROWLINE>");
 tolua_usertype(tolua_S,"std::vector<std::string>");
 tolua_usertype(tolua_S,"FIniFile");
}

/* method: new of class  FIniFile */
#ifndef TOLUA_DISABLE_tolua_Utils_FIniFile_new00
static int tolua_Utils_FIniFile_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FIniFile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   FIniFile* tolua_ret = (FIniFile*)  Mtolua_new((FIniFile)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FIniFile");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  FIniFile */
#ifndef TOLUA_DISABLE_tolua_Utils_FIniFile_new00_local
static int tolua_Utils_FIniFile_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FIniFile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   FIniFile* tolua_ret = (FIniFile*)  Mtolua_new((FIniFile)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FIniFile");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  FIniFile */
#ifndef TOLUA_DISABLE_tolua_Utils_FIniFile_delete00
static int tolua_Utils_FIniFile_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FIniFile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FIniFile* self = (FIniFile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetVersion of class  FIniFile */
#ifndef TOLUA_DISABLE_tolua_Utils_FIniFile_GetVersion00
static int tolua_Utils_FIniFile_GetVersion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FIniFile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FIniFile* self = (FIniFile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetVersion'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetVersion();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetVersion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Load of class  FIniFile */
#ifndef TOLUA_DISABLE_tolua_Utils_FIniFile_Load00
static int tolua_Utils_FIniFile_Load00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FIniFile",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FIniFile* self = (FIniFile*)  tolua_tousertype(tolua_S,1,0);
  const char* pFileName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Load'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Load(pFileName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Load'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Readbool of class  FIniFile */
#ifndef TOLUA_DISABLE_tolua_Utils_FIniFile_Readbool00
static int tolua_Utils_FIniFile_Readbool00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FIniFile",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FIniFile* self = (FIniFile*)  tolua_tousertype(tolua_S,1,0);
  const char* pSection = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* pKey = ((const char*)  tolua_tostring(tolua_S,3,0));
  bool Default = ((bool)  tolua_toboolean(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Readbool'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Readbool(pSection,pKey,Default);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Readbool'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadInt of class  FIniFile */
#ifndef TOLUA_DISABLE_tolua_Utils_FIniFile_ReadInt00
static int tolua_Utils_FIniFile_ReadInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FIniFile",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FIniFile* self = (FIniFile*)  tolua_tousertype(tolua_S,1,0);
  const char* pSection = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* pKey = ((const char*)  tolua_tostring(tolua_S,3,0));
  int Default = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReadInt'", NULL);
#endif
  {
   int tolua_ret = (int)  self->ReadInt(pSection,pKey,Default);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ReadInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadDouble of class  FIniFile */
#ifndef TOLUA_DISABLE_tolua_Utils_FIniFile_ReadDouble00
static int tolua_Utils_FIniFile_ReadDouble00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FIniFile",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FIniFile* self = (FIniFile*)  tolua_tousertype(tolua_S,1,0);
  const char* pSection = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* pKey = ((const char*)  tolua_tostring(tolua_S,3,0));
  double Default = ((double)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReadDouble'", NULL);
#endif
  {
   double tolua_ret = (double)  self->ReadDouble(pSection,pKey,Default);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ReadDouble'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadString of class  FIniFile */
#ifndef TOLUA_DISABLE_tolua_Utils_FIniFile_ReadString00
static int tolua_Utils_FIniFile_ReadString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FIniFile",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FIniFile* self = (FIniFile*)  tolua_tousertype(tolua_S,1,0);
  const char* pSection = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* pKey = ((const char*)  tolua_tostring(tolua_S,3,0));
  const char* pDefault = ((const char*)  tolua_tostring(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReadString'", NULL);
#endif
  {
   string tolua_ret = (string)  self->ReadString(pSection,pKey,pDefault);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ReadString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Writebool of class  FIniFile */
#ifndef TOLUA_DISABLE_tolua_Utils_FIniFile_Writebool00
static int tolua_Utils_FIniFile_Writebool00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FIniFile",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FIniFile* self = (FIniFile*)  tolua_tousertype(tolua_S,1,0);
  const char* pSection = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* pKey = ((const char*)  tolua_tostring(tolua_S,3,0));
  bool Value = ((bool)  tolua_toboolean(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Writebool'", NULL);
#endif
  {
   self->Writebool(pSection,pKey,Value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Writebool'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteInt of class  FIniFile */
#ifndef TOLUA_DISABLE_tolua_Utils_FIniFile_WriteInt00
static int tolua_Utils_FIniFile_WriteInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FIniFile",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FIniFile* self = (FIniFile*)  tolua_tousertype(tolua_S,1,0);
  const char* pSection = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* pKey = ((const char*)  tolua_tostring(tolua_S,3,0));
  int Value = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteInt'", NULL);
#endif
  {
   self->WriteInt(pSection,pKey,Value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteDouble of class  FIniFile */
#ifndef TOLUA_DISABLE_tolua_Utils_FIniFile_WriteDouble00
static int tolua_Utils_FIniFile_WriteDouble00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FIniFile",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FIniFile* self = (FIniFile*)  tolua_tousertype(tolua_S,1,0);
  const char* pSection = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* pKey = ((const char*)  tolua_tostring(tolua_S,3,0));
  double Value = ((double)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteDouble'", NULL);
#endif
  {
   self->WriteDouble(pSection,pKey,Value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteDouble'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteString of class  FIniFile */
#ifndef TOLUA_DISABLE_tolua_Utils_FIniFile_WriteString00
static int tolua_Utils_FIniFile_WriteString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FIniFile",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FIniFile* self = (FIniFile*)  tolua_tousertype(tolua_S,1,0);
  const char* pSection = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* pKey = ((const char*)  tolua_tostring(tolua_S,3,0));
  const char* pValue = ((const char*)  tolua_tostring(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteString'", NULL);
#endif
  {
   self->WriteString(pSection,pKey,pValue);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteIniFile of class  FIniFile */
#ifndef TOLUA_DISABLE_tolua_Utils_FIniFile_WriteIniFile00
static int tolua_Utils_FIniFile_WriteIniFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FIniFile",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FIniFile* self = (FIniFile*)  tolua_tousertype(tolua_S,1,0);
  const char* pFileName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteIniFile'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->WriteIniFile(pFileName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteIniFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DelKey of class  FIniFile */
#ifndef TOLUA_DISABLE_tolua_Utils_FIniFile_DelKey00
static int tolua_Utils_FIniFile_DelKey00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FIniFile",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FIniFile* self = (FIniFile*)  tolua_tousertype(tolua_S,1,0);
  const char* pSection = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* pKey = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DelKey'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->DelKey(pSection,pKey);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DelKey'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Close of class  FIniFile */
#ifndef TOLUA_DISABLE_tolua_Utils_FIniFile_Close00
static int tolua_Utils_FIniFile_Close00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FIniFile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FIniFile* self = (FIniFile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Close'", NULL);
#endif
  {
   self->Close();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Close'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_Width of class  FTabFile */
#ifndef TOLUA_DISABLE_tolua_get_FTabFile_m_Width
static int tolua_get_FTabFile_m_Width(lua_State* tolua_S)
{
  FTabFile* self = (FTabFile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_Width'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_Width);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_Width of class  FTabFile */
#ifndef TOLUA_DISABLE_tolua_set_FTabFile_m_Width
static int tolua_set_FTabFile_m_Width(lua_State* tolua_S)
{
  FTabFile* self = (FTabFile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_Width'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_Width = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_Height of class  FTabFile */
#ifndef TOLUA_DISABLE_tolua_get_FTabFile_m_Height
static int tolua_get_FTabFile_m_Height(lua_State* tolua_S)
{
  FTabFile* self = (FTabFile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_Height'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_Height);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_Height of class  FTabFile */
#ifndef TOLUA_DISABLE_tolua_set_FTabFile_m_Height
static int tolua_set_FTabFile_m_Height(lua_State* tolua_S)
{
  FTabFile* self = (FTabFile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_Height'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_Height = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: colList of class  FTabFile */
#ifndef TOLUA_DISABLE_tolua_get_FTabFile_colList
static int tolua_get_FTabFile_colList(lua_State* tolua_S)
{
  FTabFile* self = (FTabFile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'colList'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->colList,"std::vector<std::string>");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: colList of class  FTabFile */
#ifndef TOLUA_DISABLE_tolua_set_FTabFile_colList
static int tolua_set_FTabFile_colList(lua_State* tolua_S)
{
  FTabFile* self = (FTabFile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'colList'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"std::vector<std::string>",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->colList = *((std::vector<std::string>*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: rowList of class  FTabFile */
#ifndef TOLUA_DISABLE_tolua_get_FTabFile_rowList
static int tolua_get_FTabFile_rowList(lua_State* tolua_S)
{
  FTabFile* self = (FTabFile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rowList'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->rowList,"std::vector<std::string>");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: rowList of class  FTabFile */
#ifndef TOLUA_DISABLE_tolua_set_FTabFile_rowList
static int tolua_set_FTabFile_rowList(lua_State* tolua_S)
{
  FTabFile* self = (FTabFile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rowList'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"std::vector<std::string>",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->rowList = *((std::vector<std::string>*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: allMap of class  FTabFile */
#ifndef TOLUA_DISABLE_tolua_get_FTabFile_allMap
static int tolua_get_FTabFile_allMap(lua_State* tolua_S)
{
  FTabFile* self = (FTabFile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'allMap'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->allMap,"std::map<int,ROWLINE>");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: allMap of class  FTabFile */
#ifndef TOLUA_DISABLE_tolua_set_FTabFile_allMap
static int tolua_set_FTabFile_allMap(lua_State* tolua_S)
{
  FTabFile* self = (FTabFile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'allMap'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"std::map<int,ROWLINE>",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->allMap = *((std::map<int,ROWLINE>*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  FTabFile */
#ifndef TOLUA_DISABLE_tolua_Utils_FTabFile_new00
static int tolua_Utils_FTabFile_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FTabFile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   FTabFile* tolua_ret = (FTabFile*)  Mtolua_new((FTabFile)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FTabFile");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  FTabFile */
#ifndef TOLUA_DISABLE_tolua_Utils_FTabFile_new00_local
static int tolua_Utils_FTabFile_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FTabFile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   FTabFile* tolua_ret = (FTabFile*)  Mtolua_new((FTabFile)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FTabFile");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  FTabFile */
#ifndef TOLUA_DISABLE_tolua_Utils_FTabFile_delete00
static int tolua_Utils_FTabFile_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FTabFile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FTabFile* self = (FTabFile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Load of class  FTabFile */
#ifndef TOLUA_DISABLE_tolua_Utils_FTabFile_Load00
static int tolua_Utils_FTabFile_Load00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FTabFile",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FTabFile* self = (FTabFile*)  tolua_tousertype(tolua_S,1,0);
  const char* FileName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Load'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Load(FileName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Load'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Save of class  FTabFile */
#ifndef TOLUA_DISABLE_tolua_Utils_FTabFile_Save00
static int tolua_Utils_FTabFile_Save00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FTabFile",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FTabFile* self = (FTabFile*)  tolua_tousertype(tolua_S,1,0);
  const char* FileName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Save'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Save(FileName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Save'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LoadPack of class  FTabFile */
#ifndef TOLUA_DISABLE_tolua_Utils_FTabFile_LoadPack00
static int tolua_Utils_FTabFile_LoadPack00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FTabFile",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FTabFile* self = (FTabFile*)  tolua_tousertype(tolua_S,1,0);
  const char* FileName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LoadPack'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->LoadPack(FileName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LoadPack'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: FindRow of class  FTabFile */
#ifndef TOLUA_DISABLE_tolua_Utils_FTabFile_FindRow00
static int tolua_Utils_FTabFile_FindRow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FTabFile",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FTabFile* self = (FTabFile*)  tolua_tousertype(tolua_S,1,0);
  const char* szRow = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FindRow'", NULL);
#endif
  {
   int tolua_ret = (int)  self->FindRow(szRow);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FindRow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: FindColumn of class  FTabFile */
#ifndef TOLUA_DISABLE_tolua_Utils_FTabFile_FindColumn00
static int tolua_Utils_FTabFile_FindColumn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FTabFile",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FTabFile* self = (FTabFile*)  tolua_tousertype(tolua_S,1,0);
  const char* szColumn = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FindColumn'", NULL);
#endif
  {
   int tolua_ret = (int)  self->FindColumn(szColumn);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FindColumn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Col2Str of class  FTabFile */
#ifndef TOLUA_DISABLE_tolua_Utils_FTabFile_Col2Str00
static int tolua_Utils_FTabFile_Col2Str00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FTabFile",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FTabFile* self = (FTabFile*)  tolua_tousertype(tolua_S,1,0);
  int nCol = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Col2Str'", NULL);
#endif
  {
   string tolua_ret = (string)  self->Col2Str(nCol);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Col2Str'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWidth of class  FTabFile */
#ifndef TOLUA_DISABLE_tolua_Utils_FTabFile_GetWidth00
static int tolua_Utils_FTabFile_GetWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FTabFile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FTabFile* self = (FTabFile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWidth'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetHeight of class  FTabFile */
#ifndef TOLUA_DISABLE_tolua_Utils_FTabFile_GetHeight00
static int tolua_Utils_FTabFile_GetHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FTabFile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FTabFile* self = (FTabFile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetHeight'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetString of class  FTabFile */
#ifndef TOLUA_DISABLE_tolua_Utils_FTabFile_GetString00
static int tolua_Utils_FTabFile_GetString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FTabFile",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FTabFile* self = (FTabFile*)  tolua_tousertype(tolua_S,1,0);
  int nRow = ((int)  tolua_tonumber(tolua_S,2,0));
  const char* szColumn = ((const char*)  tolua_tostring(tolua_S,3,0));
  const char* lpDefault = ((const char*)  tolua_tostring(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetString'", NULL);
#endif
  {
   string tolua_ret = (string)  self->GetString(nRow,szColumn,lpDefault);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetString of class  FTabFile */
#ifndef TOLUA_DISABLE_tolua_Utils_FTabFile_GetString01
static int tolua_Utils_FTabFile_GetString01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FTabFile",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  FTabFile* self = (FTabFile*)  tolua_tousertype(tolua_S,1,0);
  int nRow = ((int)  tolua_tonumber(tolua_S,2,0));
  int nColumn = ((int)  tolua_tonumber(tolua_S,3,0));
  const char* lpDefault = ((const char*)  tolua_tostring(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetString'", NULL);
#endif
  {
   string tolua_ret = (string)  self->GetString(nRow,nColumn,lpDefault);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_Utils_FTabFile_GetString00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetString of class  FTabFile */
#ifndef TOLUA_DISABLE_tolua_Utils_FTabFile_GetString02
static int tolua_Utils_FTabFile_GetString02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FTabFile",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  FTabFile* self = (FTabFile*)  tolua_tousertype(tolua_S,1,0);
  const char* szRow = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* szColumn = ((const char*)  tolua_tostring(tolua_S,3,0));
  const char* lpDefault = ((const char*)  tolua_tostring(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetString'", NULL);
#endif
  {
   string tolua_ret = (string)  self->GetString(szRow,szColumn,lpDefault);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_Utils_FTabFile_GetString01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetInteger of class  FTabFile */
#ifndef TOLUA_DISABLE_tolua_Utils_FTabFile_GetInteger00
static int tolua_Utils_FTabFile_GetInteger00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FTabFile",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FTabFile* self = (FTabFile*)  tolua_tousertype(tolua_S,1,0);
  int nRow = ((int)  tolua_tonumber(tolua_S,2,0));
  const char* szColumn = ((const char*)  tolua_tostring(tolua_S,3,0));
  int nDefault = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetInteger'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetInteger(nRow,szColumn,nDefault);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetInteger'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetInteger of class  FTabFile */
#ifndef TOLUA_DISABLE_tolua_Utils_FTabFile_GetInteger01
static int tolua_Utils_FTabFile_GetInteger01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FTabFile",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  FTabFile* self = (FTabFile*)  tolua_tousertype(tolua_S,1,0);
  int nRow = ((int)  tolua_tonumber(tolua_S,2,0));
  int nColumn = ((int)  tolua_tonumber(tolua_S,3,0));
  int nDefault = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetInteger'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetInteger(nRow,nColumn,nDefault);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_Utils_FTabFile_GetInteger00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetInteger of class  FTabFile */
#ifndef TOLUA_DISABLE_tolua_Utils_FTabFile_GetInteger02
static int tolua_Utils_FTabFile_GetInteger02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FTabFile",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  FTabFile* self = (FTabFile*)  tolua_tousertype(tolua_S,1,0);
  const char* szRow = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* szColumn = ((const char*)  tolua_tostring(tolua_S,3,0));
  int nDefault = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetInteger'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetInteger(szRow,szColumn,nDefault);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_Utils_FTabFile_GetInteger01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFloat of class  FTabFile */
#ifndef TOLUA_DISABLE_tolua_Utils_FTabFile_GetFloat00
static int tolua_Utils_FTabFile_GetFloat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FTabFile",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FTabFile* self = (FTabFile*)  tolua_tousertype(tolua_S,1,0);
  int nRow = ((int)  tolua_tonumber(tolua_S,2,0));
  const char* szColumn = ((const char*)  tolua_tostring(tolua_S,3,0));
  float fDefault = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFloat'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetFloat(nRow,szColumn,fDefault);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFloat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFloat of class  FTabFile */
#ifndef TOLUA_DISABLE_tolua_Utils_FTabFile_GetFloat01
static int tolua_Utils_FTabFile_GetFloat01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FTabFile",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  FTabFile* self = (FTabFile*)  tolua_tousertype(tolua_S,1,0);
  int nRow = ((int)  tolua_tonumber(tolua_S,2,0));
  int nColumn = ((int)  tolua_tonumber(tolua_S,3,0));
  float fDefault = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFloat'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetFloat(nRow,nColumn,fDefault);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_Utils_FTabFile_GetFloat00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFloat of class  FTabFile */
#ifndef TOLUA_DISABLE_tolua_Utils_FTabFile_GetFloat02
static int tolua_Utils_FTabFile_GetFloat02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FTabFile",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  FTabFile* self = (FTabFile*)  tolua_tousertype(tolua_S,1,0);
  const char* szRow = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* szColumn = ((const char*)  tolua_tostring(tolua_S,3,0));
  float fDefault = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFloat'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetFloat(szRow,szColumn,fDefault);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_Utils_FTabFile_GetFloat01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Clear of class  FTabFile */
#ifndef TOLUA_DISABLE_tolua_Utils_FTabFile_Clear00
static int tolua_Utils_FTabFile_Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FTabFile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FTabFile* self = (FTabFile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clear'", NULL);
#endif
  {
   self->Clear();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Clear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_Utils_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"FIniFile","FIniFile","",tolua_collect_FIniFile);
  #else
  tolua_cclass(tolua_S,"FIniFile","FIniFile","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"FIniFile");
   tolua_function(tolua_S,"new",tolua_Utils_FIniFile_new00);
   tolua_function(tolua_S,"new_local",tolua_Utils_FIniFile_new00_local);
   tolua_function(tolua_S,".call",tolua_Utils_FIniFile_new00_local);
   tolua_function(tolua_S,"delete",tolua_Utils_FIniFile_delete00);
   tolua_function(tolua_S,"GetVersion",tolua_Utils_FIniFile_GetVersion00);
   tolua_function(tolua_S,"Load",tolua_Utils_FIniFile_Load00);
   tolua_function(tolua_S,"Readbool",tolua_Utils_FIniFile_Readbool00);
   tolua_function(tolua_S,"ReadInt",tolua_Utils_FIniFile_ReadInt00);
   tolua_function(tolua_S,"ReadDouble",tolua_Utils_FIniFile_ReadDouble00);
   tolua_function(tolua_S,"ReadString",tolua_Utils_FIniFile_ReadString00);
   tolua_function(tolua_S,"Writebool",tolua_Utils_FIniFile_Writebool00);
   tolua_function(tolua_S,"WriteInt",tolua_Utils_FIniFile_WriteInt00);
   tolua_function(tolua_S,"WriteDouble",tolua_Utils_FIniFile_WriteDouble00);
   tolua_function(tolua_S,"WriteString",tolua_Utils_FIniFile_WriteString00);
   tolua_function(tolua_S,"WriteIniFile",tolua_Utils_FIniFile_WriteIniFile00);
   tolua_function(tolua_S,"DelKey",tolua_Utils_FIniFile_DelKey00);
   tolua_function(tolua_S,"Close",tolua_Utils_FIniFile_Close00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"FTabFile","FTabFile","",tolua_collect_FTabFile);
  #else
  tolua_cclass(tolua_S,"FTabFile","FTabFile","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"FTabFile");
   tolua_variable(tolua_S,"m_Width",tolua_get_FTabFile_m_Width,tolua_set_FTabFile_m_Width);
   tolua_variable(tolua_S,"m_Height",tolua_get_FTabFile_m_Height,tolua_set_FTabFile_m_Height);
   tolua_variable(tolua_S,"colList",tolua_get_FTabFile_colList,tolua_set_FTabFile_colList);
   tolua_variable(tolua_S,"rowList",tolua_get_FTabFile_rowList,tolua_set_FTabFile_rowList);
   tolua_variable(tolua_S,"allMap",tolua_get_FTabFile_allMap,tolua_set_FTabFile_allMap);
   tolua_function(tolua_S,"new",tolua_Utils_FTabFile_new00);
   tolua_function(tolua_S,"new_local",tolua_Utils_FTabFile_new00_local);
   tolua_function(tolua_S,".call",tolua_Utils_FTabFile_new00_local);
   tolua_function(tolua_S,"delete",tolua_Utils_FTabFile_delete00);
   tolua_function(tolua_S,"Load",tolua_Utils_FTabFile_Load00);
   tolua_function(tolua_S,"Save",tolua_Utils_FTabFile_Save00);
   tolua_function(tolua_S,"LoadPack",tolua_Utils_FTabFile_LoadPack00);
   tolua_function(tolua_S,"FindRow",tolua_Utils_FTabFile_FindRow00);
   tolua_function(tolua_S,"FindColumn",tolua_Utils_FTabFile_FindColumn00);
   tolua_function(tolua_S,"Col2Str",tolua_Utils_FTabFile_Col2Str00);
   tolua_function(tolua_S,"GetWidth",tolua_Utils_FTabFile_GetWidth00);
   tolua_function(tolua_S,"GetHeight",tolua_Utils_FTabFile_GetHeight00);
   tolua_function(tolua_S,"GetString",tolua_Utils_FTabFile_GetString00);
   tolua_function(tolua_S,"GetString",tolua_Utils_FTabFile_GetString01);
   tolua_function(tolua_S,"GetString",tolua_Utils_FTabFile_GetString02);
   tolua_function(tolua_S,"GetInteger",tolua_Utils_FTabFile_GetInteger00);
   tolua_function(tolua_S,"GetInteger",tolua_Utils_FTabFile_GetInteger01);
   tolua_function(tolua_S,"GetInteger",tolua_Utils_FTabFile_GetInteger02);
   tolua_function(tolua_S,"GetFloat",tolua_Utils_FTabFile_GetFloat00);
   tolua_function(tolua_S,"GetFloat",tolua_Utils_FTabFile_GetFloat01);
   tolua_function(tolua_S,"GetFloat",tolua_Utils_FTabFile_GetFloat02);
   tolua_function(tolua_S,"Clear",tolua_Utils_FTabFile_Clear00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_Utils (lua_State* tolua_S) {
 return tolua_Utils_open(tolua_S);
};
#endif

