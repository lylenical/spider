#ifndef __LUAUTILS_H_
#define __LUAUTILS_H_

#ifdef __cplusplus
extern "C" {
#endif
#include "tolua++.h"
#ifdef __cplusplus
}
#endif

#include "stdafx.h"
#include "Utils/FUtils.h"

TOLUA_API int  tolua_Utils_open (lua_State* tolua_S);

#endif // __LUACOCOS2D_H_
