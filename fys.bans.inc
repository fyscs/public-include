#if defined _fys_Bans_Include_
    #endinput
#endif

#define _fys_Bans_Include_

enum AdminLevel
{
	AdminLevel_Disabled = 0,
	AdminLevel_Junior,
	AdminLevel_Senior,
	AdminLevel_Superior,
	AdminLevel_Admin,
	AdminLevel_Root,
	AdminLevel_Owner
}

// 检查是不是在权限系统
native bool Admin_IsInAdminSys(int admin);
native bool Admin_IsInAdminSysEx(const char[] auth);
// 检查此steamid在本服是否有权限
native bool Admin_IsAuthAdmin(const char[] auth);
// 检查此人是否是OP
native bool Admin_IsClientAdmin(int admin);
// Admin库对应的Id
native int  Admin_GetAdminId(int admin);
native int  Admin_GetAdminIdEx(const char[] auth);
// Admin库Sp
native int  Admin_GetAdminSpecial(int admin);
// Admin库对应的Level
native AdminLevel Admin_GetAdminLevel(int admin);
native AdminLevel Admin_GetAdminLevelEx(const char[] auth);
// Admin库对应的名字
native void Admin_GetAdminName(int admin, char[] buffer, int maxLen);
// 纪录管理员操作
native void Admin_LogAction(int admin, const char[] action, const char[] message, any ...);
// 系统初始化
native bool Admin_IsSystemLoaded();

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
	MarkNativeAsOptional("Admin_GetAdminLevel");

	MarkNativeAsOptional("Bans_BanClient");
	MarkNativeAsOptional("Bans_BanIdentity");
}
#endif