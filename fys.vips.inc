#if defined _VIP_Include_
    #endinput
#endif

#define _VIP_Include_

#define TIME_BEGINOFINIT 1556640000
#define TIME_PERMANENT   2147483647

enum vips_t
{
    vip_None,
    vip_Normal,
    vip_Supreme,
    vip_Diamond
}

// 系统初始化
native bool VIPS_IsSystemLoaded();

// 取VIP类型?
native vips_t VIPS_GetClientVIP(int client);
native vips_t VIPS_GetAuthIdVIP(const char[] AuthId);

forward void VIPS_OnClientChecked(int client, vips_t vip);
forward void VIPS_OnClientPurchased(int client, vips_t vip);

stock bool VIPS_IsClientVIP(int client)
{
    return VIPS_GetClientVIP(client) > vip_None;
}

stock bool VIPS_IsAuthIdVIP(const char[] AuthId)
{
    return VIPS_GetAuthIdVIP(AuthId) > vip_None;
}

stock int VIPImmunityLevel(vips_t vip)
{
    switch (vip)
    {
        case vip_None:      return 0;
        case vip_Normal:    return 15;
        case vip_Supreme:   return 20;
        case vip_Diamond:   return 25;
        default:            return 0;
    }
}

stock char[] VipName(vips_t vip)
{
    char buffer[32];
    switch (vip)
    {
        case vip_None:      buffer =  "VIP";
        case vip_Supreme:   buffer = "SVIP";
        case vip_Diamond:   buffer = "DVIP";
        default:            buffer = "普通会员";
    }
    return buffer;
}

stock char[] VIPTimeToString(int time)
{
    char buffer[64];

    if (time == TIME_PERMANENT)
        buffer = "有生之年";
    else
        FormatTime(buffer, 64, "%Y-%m-%d", time);

    return buffer;
}

stock char[] VIPRemaningToString(int time)
{
    char buffer[64];

    if (time > 24 * 3600)
        FormatEx(buffer, 64, "%d天", time / (3600 * 24));
    else
        FormatEx(buffer, 64, "%d小时", time / 3600);

    return buffer;
}

public SharedPlugin __pl_fys_VIPS =
{
    name = "fys-VIPS",
    file = "fys.vips.smx",
#if defined REQUIRE_PLUGIN
    required = 1
#else
    required = 0
#endif
};

#if !defined REQUIRE_PLUGIN
public void __pl_fys_VIPS_SetNTVOptional()
{
    MarkNativeAsOptional("VIPS_IsSystemLoaded");
    MarkNativeAsOptional("VIPS_GetClientVIP");
    MarkNativeAsOptional("VIPS_GetAuthIdVIP");
}
#endif