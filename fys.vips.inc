#if defined _VIP_Include_
    #endinput
#endif

#define _VIP_Include_

#define TIME_BEGINOFINIT 1556640000
#define TIME_PERMANENT   2147483647

enum vips_t
{
    vip_NONE,
    vip_Monthly,
    vip_Quarterly,
    vip_Annually,
    vip_Permanently
}

native vips_t VIPS_GetClientVIP(int client);
native vips_t VIPS_GetAuthIdVIP(const char[] AuthId);

forward void VIPS_OnClientChecked(int client, vips_t vip);
forward void VIPS_OnClientPurchased(int client, vips_t vip);

stock bool VIPS_IsClientVIP(int client)
{
    return VIPS_GetClientVIP(client) > vip_NONE;
}

stock bool VIPS_IsAuthIdVIP(const char[] AuthId)
{
    return VIPS_GetAuthIdVIP(AuthId) > vip_NONE;
}

stock int VIPImmunityLevel(vips_t vip)
{
    switch (vip)
    {
        case vip_NONE:        return 0;
        case vip_Monthly:     return 15;
        case vip_Quarterly:   return 20;
        case vip_Annually:    return 25;
        case vip_Permanently: return 30;
        default: return 0;
    }
}

stock char[] VipName(vips_t vip)
{
    char buffer[32];
    switch (vip)
    {
        case vip_Monthly:     buffer =  "VIP";
        case vip_Quarterly:   buffer = "QVIP";
        case vip_Annually:    buffer = "AVIP";
        case vip_Permanently: buffer = "SVIP";
        default:              buffer = "普通会员";
    }
    return buffer;
}

stock char[] VIPTimeToString(int time)
{
    char buffer[64];

    if (time == TIME_PERMANENT)
        buffer = "2099-12-31";
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
    MarkNativeAsOptional("VIPS_GetClientVIP");
    MarkNativeAsOptional("VIPS_GetAuthIdVIP");
}
#endif