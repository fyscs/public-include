#if defined _fys_Data_Include_
    #endinput
#endif

#define _fys_Data_Include_

native bool Data_TraceBet(int client, int chip, int earn, int time = -1);
native bool Data_TraceEntWatch(int client, const char[] action, int itemId, const char[] item);
native bool Data_TraceVoice(int client, float duration, bool soundpad);
native void Data_GetAuthorization(char[] header, int maxLen);

public SharedPlugin __pl_fys_Data =
{
    name = "fys-Data",
    file = "fys.data.smx",
#if defined REQUIRE_PLUGIN
    required = 1
#else
    required = 0
#endif
};

#if !defined REQUIRE_PLUGIN
public void __pl_fys_Data_SetNTVOptional()
{
    MarkNativeAsOptional("Data_TraceBet");
    MarkNativeAsOptional("Data_TraceEntWatch");
    MarkNativeAsOptional("Data_TraceVoice");
    MarkNativeAsOptional("Data_GetAuthorization");
}
#endif