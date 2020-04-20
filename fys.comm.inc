#if defined _fys_Comm_Include_
    #endinput
#endif

#define _fys_Comm_Include_

// 是否被禁言
native bool Comm_IsClientGagged(int client);
native bool BaseComm_IsClientGagged(int client);

// 是否被禁麦
native bool Comm_IsClientMuted(int client);
native bool BaseComm_IsClientMuted(int client);

// 兼容老Api
native void BaseComm_SetClientGag(int client, bool state);
native void BaseComm_SetClientMute(int client, bool state);

// 设置禁麦/禁言
native void Comm_SetClientGag(int admin, int target, bool state, int length = 1);
native void Comm_SetClientMute(int admin, int target, bool state, int length = 1);

public SharedPlugin __pl_fys_Comm =
{
    name = "fys-Comm",
    file = "fys.comm.smx",
#if defined REQUIRE_PLUGIN
    required = 1
#else
    required = 0
#endif
};

#if !defined REQUIRE_PLUGIN
public void __pl_fys_Comm_SetNTVOptional()
{
	MarkNativeAsOptional("Comm_IsClientGagged");
    MarkNativeAsOptional("BaseComm_IsClientGagged");

    MarkNativeAsOptional("Comm_IsClientMuted");
    MarkNativeAsOptional("BaseComm_IsClientMuted");

    MarkNativeAsOptional("BaseComm_SetClientGag");
    MarkNativeAsOptional("BaseComm_SetClientMute");

    MarkNativeAsOptional("Comm_SetClientGag");
    MarkNativeAsOptional("Comm_SetClientMute");
}
#endif