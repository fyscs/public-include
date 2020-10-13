#if defined _fys_Auth_Include_
    #endinput
#endif

#define _fys_Auth_Include_

// 获取认证
native int  Auth_GetClientAuth(int client);
// 获取等级
native int  Auth_GetClientLvls(int client);
// 增加经验
native void Auth_AddClientExps(int client);
// 认证名称
native void Auth_GetClientName(int client, const char[] auth, int maxLen);

forward void Auth_OnClientLoad(int client, int authid);

public SharedPlugin __pl_fys_Auth =
{
    name = "fys-Auth",
    file = "fys.auth.smx",
#if defined REQUIRE_PLUGIN
    required = 1
#else
    required = 0
#endif
};

#if !defined REQUIRE_PLUGIN
public void __pl_fys_Auth_SetNTVOptional()
{
    MarkNativeAsOptional("Auth_GetClientAuth");
    MarkNativeAsOptional("Auth_GetClientName");
}
#endif