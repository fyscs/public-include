#if defined _fys_Exts_Filter_Include_
    #endinput
#endif

#define _fys_Exts_Filter_Include_

// 是否是违规玩家
native bool Exts_FT_IsClientBadGuy(int client);

public SharedPlugin __pl_fys_Exts_Filter =
{
    name = "fys-Exts-Filter",
    file = "fys.exts.filter.smx",
#if defined REQUIRE_PLUGIN
    required = 1
#else
    required = 0
#endif
};

#if !defined REQUIRE_PLUGIN
public void __pl_fys_Exts_Filter_SetNTVOptional()
{
    MarkNativeAsOptional("Exts_FT_IsClientBadGuy");
}
#endif