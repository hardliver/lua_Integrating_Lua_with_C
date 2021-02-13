#include <stdio.h>

#include "../lib/lua/src/lua.h"
#include "../lib/lua/src/lualib.h"
#include "../lib/lua/src/lauxlib.h"

void lua_example_dofile(void)
{
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);
    luaL_dofile(L, "./scripts/factorial.lua");
    lua_close(L);
}

void lua_example_getvar(void)
{
    lua_State *L = luaL_newstate();
    luaL_dostring(L, "some_var = 486"); // executing a Lua string
    lua_getglobal(L, "some_var"); // getting back a global varible from Lua
    lua_Number some_var_in_c = lua_tonumber(L, -1);

    printf("The value of some_var inside C is: %d\n", (int)some_var_in_c);

    lua_close(L);
}

int main(int args, char *argv[])
{
    // lua_example_dofile();
    lua_example_getvar();
    return 0;
}
