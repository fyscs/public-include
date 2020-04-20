#if defined _fys_Bans_Include_
    #endinput
#endif

#define _fys_Bans_Include_

// 检查是不是在权限系统
native bool Admin_IsInAdminSys(int client);
// 检查此steamid在本服是否有权限
native bool Admin_IsAuthAdmin(const char[] auth);
// 检查此人是否是OP
native bool Admin_IsClientAdmin(int client);
// Admin库对应的Id
native int  Admin_GetAdminId(int client);
// Admin库对应的名字
native void Admin_GetAdminName(int client, char[] buffer, int maxLen);
// 纪录管理员操作
native void Admin_LogAction(int admin, const char[] action, const char[] message, any ...);

/*
 *  Ban_Type
 */
// 0 = 全服封禁
// 1 = 游戏封禁
// 2 = 模式封禁
// 3 = 单服封禁
native bool Bans_BanClient(int admin, int target, int ban_type, int ban_length, const char[] ban_reason);
native bool Bans_BanIdentity(int admin, const char[] identity, int ban_type, int ban_length, const char[] ban_reason);

public SharedPlugin __pl_fys_Bans =
{
    name = "fys-Bans",
    file = "fys.bans.smx",
#if defined REQUIRE_PLUGIN
    required = 1
#else
    required = 0
#endif
};

#if !defined REQUIRE_PLUGIN
public void __pl_fys_Bans_SetNTVOptional()
{
	MarkNativeAsOptional("Admin_IsInAdminSys");
	MarkNativeAsOptional("Admin_IsAuthAdmin");
	MarkNativeAsOptional("Admin_IsClientAdmin");
	MarkNativeAsOptional("Admin_GetAdminId");
	MarkNativeAsOptional("Admin_GetAdminName");
	MarkNativeAsOptional("Admin_LogAction");

	MarkNativeAsOptional("Bans_BanClient");
	MarkNativeAsOptional("Bans_BanIdentity");
}
#endif