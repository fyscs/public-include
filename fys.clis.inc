#if defined _fys_Client_Include_
    #endinput
#endif

#define _fys_Client_Include_

// 登录器最后心跳时间
native int  Clis_GetLastActive(int client);
// 登录器启动时间
native int  Clis_GetStartTime(int client);

// 登录器侦测判断
native bool Clis_IsUsingClient(int client);
// 是否启用彩蛋
native bool Clis_IsClientEggOn(int client);
// 读取当前使用的版本
native bool Clis_GetVersion(int client, char[] buffer, int maxlen);
// 获取设备Id
native bool Clis_GetDeviceId(int client, char[] buffer, int maxlen);
// 获取外部程序状态
native bool Clis_IsExternal(int client);
// 获取外部程序Id
native int  Clis_GetExternalId(int client);
// 获取外部程序名
native void Clis_GetExternalName(int client, char[] buffer, int maxlen);
// 获取外部程序状态
native bool Clis_GetExternalStatus(int client);
// 获取外部SP
native bool Clis_HasSoundPad(int client);
// 获取Discord状态
native bool Clis_IsDiscordOnline(int client);
// 获取Sponsor状态
native bool Clis_IsDiscordBooster(int client);

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
    MarkNativeAsOptional("Clis_IsExternal");
    MarkNativeAsOptional("Clis_HasSoundPad");
    MarkNativeAsOptional("Clis_GetExternalId");
    MarkNativeAsOptional("Clis_GetExternalName");
    MarkNativeAsOptional("Clis_GetExternalStatus");
    MarkNativeAsOptional("Clis_IsDiscordOnline");
    MarkNativeAsOptional("Clis_IsDiscordBooster");
}
#endif