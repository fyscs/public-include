#if defined _fys_Couple_Include_
    #endinput
#endif

#define _fys_Couple_Include_

#define COUPLES_INVALID -2
#define COUPLES_OFFLINE -1
#define COUPLES_PENDING  0

native int  CP_GetPartner(int client);

native int  CP_GetCPID(int client);
native int  CP_GetDate(int client);
native int  CP_GetPlay(int client);
native int  CP_GetLvls(int client);
native bool CP_AddLvls(int client, int level);
native bool CP_GetName(int client, char[] buffer, int maxlen);
native bool CP_IsWaifu(int client);

stock char[] CP_GetPartnerCall(int client)
{
    char returns[16] = "自己";

    int type = CP_GetPartner(client);
    if (type == COUPLES_INVALID || COUPLES_PENDING)
        return returns;

    strcopy(returns, 16, CP_IsWaifu(client) ? "老公" : "老婆");
    return returns;
}

stock void CP_FormatPartnerCall(int client, char[] buffer, int maxlen)
{
    strcopy(buffer, maxlen, "自己");

    int type = CP_GetPartner(client);
    if (type == COUPLES_INVALID || COUPLES_PENDING)
        return;

    strcopy(buffer, maxlen, CP_IsWaifu(client) ? "老公" : "老婆");
}

public SharedPlugin __pl_fys_Couples =
{
    name = "fys-Couples",
    file = "fys.mycp.smx",
#if defined REQUIRE_PLUGIN
    required = 1
#else
    required = 0
#endif
};

#if !defined REQUIRE_PLUGIN
public void __ext_fys_Couples_SetNTVOptional()
{
    MarkNativeAsOptional("CP_GetPartner");

    MarkNativeAsOptional("CP_GetCPID");
    MarkNativeAsOptional("CP_GetDate");
    MarkNativeAsOptional("CP_GetPlay");
    MarkNativeAsOptional("CP_GetLvls");
    MarkNativeAsOptional("CP_AddLvls");
    MarkNativeAsOptional("CP_GetName");
    MarkNativeAsOptional("CP_IsWaifu");
}
#endif