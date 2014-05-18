#ifndef __LUANETWORK_H_
#define __LUANETWORK_H_

#ifdef __cplusplus
extern "C" {
#endif
#include "tolua++.h"
#ifdef __cplusplus
}
#endif

#include "stdafx.h"
#include "Network/FNetwork.h"

TOLUA_API int  tolua_Network_open (lua_State* tolua_S);

#endif // __LUACOCOS2D_H_
