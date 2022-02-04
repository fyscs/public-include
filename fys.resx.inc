#if defined _fys_Resx_Include_
    #endinput
#endif

#define _fys_Resx_Include_

native void Resx_AddContent(const char[] path);
native void Resx_ForceUpdate();

native bool Resx_SB_SetConnected(int client, bool value);
native  int Resx_SB_GetLevel(int client);
native void Resx_SB_SetLevel(int client, int level);
native  int Resx_SB_GetBadge(int client);
native void Resx_SB_SetBadge(int client, int badge);
native  int Resx_SB_GetRank(int client);
native void Resx_SB_SetRank(int client, int rank);

public SharedPlugin __pl_fys_Resx =
{
    name = "fys-Resx",
    file = "fys.resx.smx",
#if defined REQUIRE_PLUGIN
    required = 1
#else
    required = 0
#endif
};

#if !defined REQUIRE_PLUGIN
public void __pl_fys_Resx_SetNTVOptional()
{
    MarkNativeAsOptional("Resx_AddContent");
    MarkNativeAsOptional("Resx_ForceUpdate");

    MarkNativeAsOptional("Resx_SB_SetConnected");
    MarkNativeAsOptional("Resx_SB_SetLevel");
    MarkNativeAsOptional("Resx_SB_SetRank");

    MarkNativeAsOptional("Resx_SB_GetLevel");
    MarkNativeAsOptional("Resx_SB_GetRank");

    MarkNativeAsOptional("Resx_SB_GetBadge");
    MarkNativeAsOptional("Resx_SB_SetBadge");
}
#endif