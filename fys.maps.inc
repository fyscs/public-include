#if defined _fys_Maps_Include_
    #endinput
#endif

#define _fys_Maps_Include_

#define FYS_MAX_TIER 6
#define FYS_DEF_TIER 0

#pragma unused g_sTierString

char g_sTierString[FYS_MAX_TIER+1][16] = {
    "待定","入门","简单","普通","困难","火星","入土"
};

// 取地图翻译名
native bool Maps_GetName(const char[] map, char[] buffer, int maxLen);
// 取地图哈希码
native bool Maps_GetHash(const char[] map, char[] buffer, int maxLen);
// 取地图UUID
native bool Maps_GetUUID(const char[] map, char[] buffer, int maxLen);
// 取地图大小
native int  Maps_GetSize(const char[] map);
// 取地图难度
native int  Maps_GetTier(const char[] map);

// 当前关卡
native int Maps_GetStage();
// 总关卡数
native int Maps_GetTotal();
// Ex开始关
native int Maps_GetExStart();
// 是否有Ex
native int Maps_GetExtreme();


public SharedPlugin __pl_fys_Maps =
{
    name = "fys-Maps",
    file = "fys.maps.smx",
#if defined REQUIRE_PLUGIN
    required = 1
#else
    required = 0
#endif
};

#if !defined REQUIRE_PLUGIN
public void __pl_fys_Maps_SetNTVOptional()
{
    MarkNativeAsOptional("Maps_GetName");
    MarkNativeAsOptional("Maps_GetHash");
    MarkNativeAsOptional("Maps_GetUUID");
    MarkNativeAsOptional("Maps_GetSize");
    MarkNativeAsOptional("Maps_GetTier");

    MarkNativeAsOptional("Maps_GetStage");
    MarkNativeAsOptional("Maps_GetTotal");
    MarkNativeAsOptional("Maps_GetExStart");
    MarkNativeAsOptional("Maps_GetExtreme");
}
#endif