/*
** Lua binding: Network
** Generated automatically by tolua++-1.0.92 on 05/18/14 22:41:57.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_Network_open (lua_State* tolua_S);

#include "LuaNetwork.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_spider__FServer (lua_State* tolua_S)
{
 spider::FServer* self = (spider::FServer*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"spider::FConnect");
 tolua_usertype(tolua_S,"spider::FServer");
 tolua_usertype(tolua_S,"bufferevent");
}

/* method: new of class  spider::FServer */
#ifndef TOLUA_DISABLE_tolua_Network_spider_FServer_new00
static int tolua_Network_spider_FServer_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"spider::FServer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   spider::FServer* tolua_ret = (spider::FServer*)  Mtolua_new((spider::FServer)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"spider::FServer");
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

/* method: new_local of class  spider::FServer */
#ifndef TOLUA_DISABLE_tolua_Network_spider_FServer_new00_local
static int tolua_Network_spider_FServer_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"spider::FServer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   spider::FServer* tolua_ret = (spider::FServer*)  Mtolua_new((spider::FServer)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"spider::FServer");
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

/* method: delete of class  spider::FServer */
#ifndef TOLUA_DISABLE_tolua_Network_spider_FServer_delete00
static int tolua_Network_spider_FServer_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"spider::FServer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  spider::FServer* self = (spider::FServer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Start of class  spider::FServer */
#ifndef TOLUA_DISABLE_tolua_Network_spider_FServer_Start00
static int tolua_Network_spider_FServer_Start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"spider::FServer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  spider::FServer* self = (spider::FServer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Start'", NULL);
#endif
  {
   self->Start();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Start'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Update of class  spider::FServer */
#ifndef TOLUA_DISABLE_tolua_Network_spider_FServer_Update00
static int tolua_Network_spider_FServer_Update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"spider::FServer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  spider::FServer* self = (spider::FServer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Update'", NULL);
#endif
  {
   self->Update();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnConnect of class  spider::FServer */
#ifndef TOLUA_DISABLE_tolua_Network_spider_FServer_OnConnect00
static int tolua_Network_spider_FServer_OnConnect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"spider::FServer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"spider::FConnect",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  spider::FServer* self = (spider::FServer*)  tolua_tousertype(tolua_S,1,0);
  spider::FConnect* fcon = ((spider::FConnect*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnConnect'", NULL);
#endif
  {
   self->OnConnect(fcon);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnConnect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ip of class  spider::FServer */
#ifndef TOLUA_DISABLE_tolua_get_spider__FServer_ip
static int tolua_get_spider__FServer_ip(lua_State* tolua_S)
{
  spider::FServer* self = (spider::FServer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ip'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->ip);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ip of class  spider::FServer */
#ifndef TOLUA_DISABLE_tolua_set_spider__FServer_ip
static int tolua_set_spider__FServer_ip(lua_State* tolua_S)
{
  spider::FServer* self = (spider::FServer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ip'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ip = ((string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: port of class  spider::FServer */
#ifndef TOLUA_DISABLE_tolua_get_spider__FServer_port
static int tolua_get_spider__FServer_port(lua_State* tolua_S)
{
  spider::FServer* self = (spider::FServer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'port'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->port);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: port of class  spider::FServer */
#ifndef TOLUA_DISABLE_tolua_set_spider__FServer_port
static int tolua_set_spider__FServer_port(lua_State* tolua_S)
{
  spider::FServer* self = (spider::FServer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'port'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->port = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: RegistServer of class  spider::FServer */
#ifndef TOLUA_DISABLE_tolua_Network_spider_FServer_RegistServer00
static int tolua_Network_spider_FServer_RegistServer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"spider::FServer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"spider::FServer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  spider::FServer* server = ((spider::FServer*)  tolua_tousertype(tolua_S,2,0));
  {
   spider::FServer::RegistServer(server);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RegistServer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ip of class  spider::FConnect */
#ifndef TOLUA_DISABLE_tolua_get_spider__FConnect_ip
static int tolua_get_spider__FConnect_ip(lua_State* tolua_S)
{
  spider::FConnect* self = (spider::FConnect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ip'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->ip);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ip of class  spider::FConnect */
#ifndef TOLUA_DISABLE_tolua_set_spider__FConnect_ip
static int tolua_set_spider__FConnect_ip(lua_State* tolua_S)
{
  spider::FConnect* self = (spider::FConnect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ip'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ip = ((string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: port of class  spider::FConnect */
#ifndef TOLUA_DISABLE_tolua_get_spider__FConnect_port
static int tolua_get_spider__FConnect_port(lua_State* tolua_S)
{
  spider::FConnect* self = (spider::FConnect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'port'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->port);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: port of class  spider::FConnect */
#ifndef TOLUA_DISABLE_tolua_set_spider__FConnect_port
static int tolua_set_spider__FConnect_port(lua_State* tolua_S)
{
  spider::FConnect* self = (spider::FConnect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'port'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->port = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: _socket_fd of class  spider::FConnect */
#ifndef TOLUA_DISABLE_tolua_get_spider__FConnect__socket_fd
static int tolua_get_spider__FConnect__socket_fd(lua_State* tolua_S)
{
  spider::FConnect* self = (spider::FConnect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '_socket_fd'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->_socket_fd);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: _socket_fd of class  spider::FConnect */
#ifndef TOLUA_DISABLE_tolua_set_spider__FConnect__socket_fd
static int tolua_set_spider__FConnect__socket_fd(lua_State* tolua_S)
{
  spider::FConnect* self = (spider::FConnect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '_socket_fd'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->_socket_fd = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: buf_ev of class  spider::FConnect */
#ifndef TOLUA_DISABLE_tolua_get_spider__FConnect_buf_ev_ptr
static int tolua_get_spider__FConnect_buf_ev_ptr(lua_State* tolua_S)
{
  spider::FConnect* self = (spider::FConnect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'buf_ev'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->buf_ev,"bufferevent");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: buf_ev of class  spider::FConnect */
#ifndef TOLUA_DISABLE_tolua_set_spider__FConnect_buf_ev_ptr
static int tolua_set_spider__FConnect_buf_ev_ptr(lua_State* tolua_S)
{
  spider::FConnect* self = (spider::FConnect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'buf_ev'",NULL);
  if (!tolua_isusertype(tolua_S,2,"bufferevent",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->buf_ev = ((struct bufferevent*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_Network_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_module(tolua_S,"spider",0);
  tolua_beginmodule(tolua_S,"spider");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"FServer","spider::FServer","",tolua_collect_spider__FServer);
   #else
   tolua_cclass(tolua_S,"FServer","spider::FServer","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"FServer");
    tolua_function(tolua_S,"new",tolua_Network_spider_FServer_new00);
    tolua_function(tolua_S,"new_local",tolua_Network_spider_FServer_new00_local);
    tolua_function(tolua_S,".call",tolua_Network_spider_FServer_new00_local);
    tolua_function(tolua_S,"delete",tolua_Network_spider_FServer_delete00);
    tolua_function(tolua_S,"Start",tolua_Network_spider_FServer_Start00);
    tolua_function(tolua_S,"Update",tolua_Network_spider_FServer_Update00);
    tolua_function(tolua_S,"OnConnect",tolua_Network_spider_FServer_OnConnect00);
    tolua_variable(tolua_S,"ip",tolua_get_spider__FServer_ip,tolua_set_spider__FServer_ip);
    tolua_variable(tolua_S,"port",tolua_get_spider__FServer_port,tolua_set_spider__FServer_port);
    tolua_function(tolua_S,"RegistServer",tolua_Network_spider_FServer_RegistServer00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"spider",0);
  tolua_beginmodule(tolua_S,"spider");
   tolua_cclass(tolua_S,"FConnect","spider::FConnect","",NULL);
   tolua_beginmodule(tolua_S,"FConnect");
    tolua_variable(tolua_S,"ip",tolua_get_spider__FConnect_ip,tolua_set_spider__FConnect_ip);
    tolua_variable(tolua_S,"port",tolua_get_spider__FConnect_port,tolua_set_spider__FConnect_port);
    tolua_variable(tolua_S,"_socket_fd",tolua_get_spider__FConnect__socket_fd,tolua_set_spider__FConnect__socket_fd);
    tolua_variable(tolua_S,"buf_ev",tolua_get_spider__FConnect_buf_ev_ptr,tolua_set_spider__FConnect_buf_ev_ptr);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_Network (lua_State* tolua_S) {
 return tolua_Network_open(tolua_S);
};
#endif

