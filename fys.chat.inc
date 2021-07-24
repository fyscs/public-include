#if defined _fys_Chat_Include_
    #endinput
#endif

#define _fys_Chat_Include_

forward Action Chat_OnGetAuthName(int client, char[] buffer, int len);

public SharedPlugin __pl_fys_Chat =
{
    name = "fys-Chat",
    file = "fys.chat.smx",
#if defined REQUIRE_PLUGIN
    required = 1
#else
    required = 0
#endif
};

#if !defined REQUIRE_PLUGIN
public void __pl_fys_Chat_SetNTVOptional()
{
    
}
#endif