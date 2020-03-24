#if defined _fys_Client_Include_
    #endinput
#endif

#define _fys_Client_Include_

native int  Clis_GetLastActive(int client);
native int  Clis_GetStartTime(int client);

native bool Clis_IsUsingClient(int client);
native bool Clis_IsClientEggOn(int client);
native bool Clis_GetVersion(int client, char[] buffer, int maxlen);
native bool Clis_GetDeviceId(int client, char[] buffer, int maxlen);

public SharedPlugin __pl_fys_Client =
{
    name = "fys-Client",
    file = "fys.clis.smx",
#if defined REQUIRE_PLUGIN
    required = 1
#else
    required = 0
#endif
};

#if !defined REQUIRE_PLUGIN
public void __pl_fys_Client_SetNTVOptional()
{
    MarkNativeAsOptional("Clis_GetLastActive");
    MarkNativeAsOptional("Clis_GetStartTime");
    MarkNativeAsOptional("Clis_IsUsingClient");
    MarkNativeAsOptional("Clis_IsClientEggOn");
    MarkNativeAsOptional("Clis_GetVersion");
    MarkNativeAsOptional("Clis_GetDeviceId");
}
#endif