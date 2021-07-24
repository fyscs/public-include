#if defined _fys_Exts_GroupManager_Include_
    #endinput
#endif

#define _fys_Exts_GroupManager_Include_

enum
{
    GROUP_FyS,
    GROUP_PEL,
    GROUP_AES,
    GROUP_Hyn,
    GROUP_She,
    MAX_GROUPS
}

// 是否在组内 / 成员 / 官员 / 组内
native bool Exts_GM_IsClientMember (int client, int group);
native bool Exts_GM_IsClientOfficer(int client, int group);
native bool Exts_GM_IsClientInGroup(int client, int group);

// 组标管理
native bool Exts_GM_GetRealClanTag(int client, char[] buffer, int maxLen);
native bool Exts_GM_SetOverrideTag(int client, const char[] buffer = NULL_STRING);

// 取组名, 组缩写
native void Exts_GM_GetGroupFullName (int group, char[] buffer, int maxLen);
native void Exts_GM_GetGroupShortName(int group, char[] buffer, int maxLen);

// 违规组
native bool Exts_GM_InBadGroup(int client);

public SharedPlugin __pl_fys_Exts_GroupManager =
{
    name = "fys-Exts-GroupManager",
    file = "fys.exts.groupmanager.smx",
#if defined REQUIRE_PLUGIN
    required = 1
#else
    required = 0
#endif
};

#if !defined REQUIRE_PLUGIN
public void __pl_fys_Exts_GroupManager_SetNTVOptional()
{
    MarkNativeAsOptional("Exts_GM_IsClientMember");
    MarkNativeAsOptional("Exts_GM_IsClientOfficer");
    MarkNativeAsOptional("Exts_GM_IsClientInGroup");

    MarkNativeAsOptional("Exts_GM_GetGroupFullName");
    MarkNativeAsOptional("Exts_GM_GetGroupShortName");

    MarkNativeAsOptional("Exts_GM_InBadGroup");
}
#endif