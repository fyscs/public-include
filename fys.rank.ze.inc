#if defined _fys_Rank_ZE_Include_
    #endinput
#endif

#define _fys_Rank_ZE_Include_

native bool Rank_ZE_GetStatus();
native void Rank_ZE_SetStatus(bool status);

native int  Rank_ZE_GetRank(int client);

native int  Rank_ZE_Get_Points(int client);
native void Rank_ZE_EernPoints(int client, int point);
native void Rank_ZE_LostPoints(int client, int point);

native int  Rank_ZE_Get_KillZ(int client);
native int  Rank_ZE_Get_KillH(int client);
native int  Rank_ZE_Get_DmgTP(int client);
native int  Rank_ZE_Get_DmgRW(int client);
native int  Rank_ZE_Get_RPlay(int client);
native int  Rank_ZE_Get_RWins(int client);
native int  Rank_ZE_Get_NNade(int client);
native int  Rank_ZE_Get_NIces(int client);
native int  Rank_ZE_Get_NFire(int client);
native int  Rank_ZE_Get_NPush(int client);
native int  Rank_ZE_Get_NHole(int client);

forward void Rank_ZE_OnClientLoad(int client);

stock char[] StringPadLeft(int value, int len = 0, const char[] padleft = "  ")
{
    char buffer[16];
    FormatEx(buffer, 16, "%d", value);

    if (len > 0)
    {
        int csl = len - strlen(buffer);

        for(int i = 0; i < csl; i++)
        {
            Format(buffer, 16, "%s%s", padleft, buffer);
        }
    }

    return buffer;
}

stock char[] DamageText(int value, int len = 0, const char[] padleft = "  ")
{
    char buffer[16];
    if (value >= 1024000000)
        //FormatEx(buffer, 16, "%4.1fG", float(value) / 1024000000);
        FormatEx(buffer, 16, "%dG", value / 1024000000);
    else if (value >= 1024000)
        //FormatEx(buffer, 16, "%4.1fM", float(value) / 1024000);
        FormatEx(buffer, 16, "%dM", value / 1024000);
    else if (value >= 1024)
        //FormatEx(buffer, 16, "%4.1fK", float(value) / 1024);
        FormatEx(buffer, 16, "%dK", value / 1024);
    else
        FormatEx(buffer, 16, "%d", value);

    if (len > 0)
    {
        int csl = strlen(buffer);

        for(int i = 0; i < len - csl; i++)
        {
            Format(buffer, 16, "%s%s", padleft, buffer);
        }
    }

    //if (FindCharInString(buffer, '.', false) > -1)
    //{
    //    StrCat(buffer, 16, ".");
    //}

    return buffer;
}

stock char[] FormatDamage(int value, int len, const char[] padleft = "  ")
{
    char buffer[16];

    if (len <= 0)
        return buffer;

    if (value >= 100000000)
        FormatEx(buffer, 16, "%dM", value / 1024000);
    else if (value >= 100000)
        FormatEx(buffer, 16, "%dK", value / 1024);
    else
        FormatEx(buffer, 16, "%d", value);

    int csl = len - strlen(buffer);

    for(int i = 0; i < csl; i++)
    {
        Format(buffer, 16, "%s%s", padleft, buffer);
    }

    return buffer;
}

public SharedPlugin __pl_fys_Rank_ZE =
{
    name = "fys-Rank-ZE",
    file = "fys.rank.ze.smx",
#if defined REQUIRE_PLUGIN
    required = 1
#else
    required = 0
#endif
};

#if !defined REQUIRE_PLUGIN
public void __pl_fys_Rank_ZE_SetNTVOptional()
{
    MarkNativeAsOptional("Rank_ZE_GetStatus");
    MarkNativeAsOptional("Rank_ZE_SetStatus");

    MarkNativeAsOptional("Rank_ZE_Get_Points");
    MarkNativeAsOptional("Rank_ZE_EernPoints");
    MarkNativeAsOptional("Rank_ZE_LostPoints");

    MarkNativeAsOptional("Rank_ZE_Get_KillZ");
    MarkNativeAsOptional("Rank_ZE_Get_KillH");
    MarkNativeAsOptional("Rank_ZE_Get_DmgTP");
    MarkNativeAsOptional("Rank_ZE_Get_DmgRW");
    MarkNativeAsOptional("Rank_ZE_Get_RPlay");
    MarkNativeAsOptional("Rank_ZE_Get_RWins");
    MarkNativeAsOptional("Rank_ZE_Get_NNade");
    MarkNativeAsOptional("Rank_ZE_Get_NIces");
    MarkNativeAsOptional("Rank_ZE_Get_NFire");
    MarkNativeAsOptional("Rank_ZE_Get_NPush");
    MarkNativeAsOptional("Rank_ZE_Get_NHole");
}
#endif