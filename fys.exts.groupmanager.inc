#if defined _fys_Exts_GroupManager_Include_
    #endinput
#endif

#define _fys_Exts_GroupManager_Include_

#define MAX_GROUPS 3

#define GROUP_FyS 0
#define GRPUP_PEL 1
#define GROUP_AES 2

native bool Exts_GM_IsClientMember (int client, int group);
native bool Exts_GM_IsClientOfficer(int client, int group);
native bool Exts_GM_IsClientInGroup(int client, int group);

native void Exts_GM_GetGroupFullName (int group, char[] buffer, int maxLen);
native void Exts_GM_GetGroupShortName(int group, char[] buffer, int maxLen);

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
}
#endif