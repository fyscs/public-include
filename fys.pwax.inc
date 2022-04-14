#if defined _fys_Pwax_Include_
    #endinput
#endif

#define _fys_Pwax_Include_

native bool Pwax_GetClientGreen(int client);
native int  Pwax_GetClientScore(int client);
native bool Pwax_GetClientLevel(int clinet, char buffer[16]);

public SharedPlugin __pl_fys_Pwax =
{
    name = "fys-Pwax",
    file = "fys.pwax.smx",
#if defined REQUIRE_PLUGIN
    required = 1
#else
    required = 0
#endif
};

#if !defined REQUIRE_PLUGIN
public void __pl_fys_Pwax_SetNTVOptional()
{
    MarkNativeAsOptional("Pwax_GetClientGreen");
    MarkNativeAsOptional("Pwax_GetClientScore");
    MarkNativeAsOptional("Pwax_GetClientLevel");
}
#endif