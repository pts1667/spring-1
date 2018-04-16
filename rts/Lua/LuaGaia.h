/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#ifndef LUA_GAIA_H
#define LUA_GAIA_H

#include <string>
using std::string;

#include "LuaHandleSynced.h"


class CLuaGaia : public CSplitLuaHandle
{
public:
	static bool CanLoadHandler();
	static bool ReloadHandler() { return (FreeHandler(), LoadFreeHandler()); } // NOTE the ','
	static bool LoadFreeHandler() { return (LoadHandler() || FreeHandler()); }

	static bool LoadHandler();
	static bool FreeHandler();

protected:
	bool AddSyncedCode(lua_State* L) { return true; }
	bool AddUnsyncedCode(lua_State* L) { return true; }

private:
	CLuaGaia();
	virtual ~CLuaGaia();
};


extern CLuaGaia* luaGaia;


#endif /* LUA_GAIA_H */
