#if defined _fys_Exts_PerfectWorld_Include_
    #endinput
#endif

#define _fys_Exts_PerfectWorld_Include_

// 是否是国服登录
native bool Exts_PW_IsPerfectWorld(int client);

public SharedPlugin __pl_fys_Exts_PerfectWorld =
{
    name = "fys-Exts-PerfectWorld",
    file = "fys.exts.perfectworld.smx",
#if defined REQUIRE_PLUGIN
    required = 1
#else
    required = 0
#endif
};

#if !defined REQUIRE_PLUGIN
public void __pl_fys_Exts_PerfectWorld_SetNTVOptional()
{
    MarkNativeAsOptional("Exts_PW_IsPerfectWorld");
}
#endif