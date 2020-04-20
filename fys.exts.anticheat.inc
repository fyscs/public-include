#if defined _fys_Exts_AntiCheat_Include_
    #endinput
#endif

#define _fys_Exts_AntiCheat_Include_

// 当前回合关闭此人反作弊检测
// 适用于越狱的道具商店够买自动连跳之后
native void Exts_AC_SetIgnoreClient(int client, bool stats); // if true = ignore client check

public SharedPlugin __pl_fys_Exts_AntiCheat =
{
    name = "fys-Exts-AntiCheat",
    file = "fys.exts.anticheat.smx",
#if defined REQUIRE_PLUGIN
    required = 1
#else
    required = 0
#endif
};

#if !defined REQUIRE_PLUGIN
public void __pl_fys_Exts_AntiCheat_SetNTVOptional()
{
    MarkNativeAsOptional("Exts_AC_SetIgnoreClient");
}
#endif