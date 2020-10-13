#if defined _fys_Core_Include_
    #endinput
#endif

#define _fys_Core_Include_

#define PI_VERSION "1.5" ... "." ... "<build>"

#define foreachAction(%1, %2, %3) for (int %1 = %2; %1 <= %3; %1++)
#define foreachClient(%1) for (int %1 = 1; %1 <= MaxClients; %1++) if (IsClientInGame(%1))
#define foreachPlayer(%1) for (int %1 = 1; %1 <= MaxClients; %1++) if (IsClientInGame(%1) && !IsFakeClient(%1))

enum Player
{
    INVALID_PLAYER = -1
}

methodmap Player __nullable__
{
    property int client {
        public get() { 
            return view_as<int>(this);
        }
    }

    public native Player(int client);

    property int PId { 
        public native get(); 
    }

    property int UId { 
        public native get(); 
    }

    property int Coin {
        public native get();
    }

    property int FirstJoin { 
        public native get();
    }

    property int LastSeen { 
        public native get();
    }

    property int Connections {
        public native get();
    }

    property int Onlines {
        public native get();
    }

    property int OnlineToday {
        public native get();
    }

    property int PlayedToday {
        public native get();
    }

    property int SignTimes {
        public native get();
    }

    property int SignDate {
        public native get();
    }

    property int SignKeep {
        public native get();
    }

    property int PlayTotal {
        public native get();
    }

    property int SpecTotal {
        public native get();
    }

    property int AliveTime {
        public native get();
    }

    property int PlaySession {
        public native get();
    }

    property int SpecSession {
        public native get();
    }

    property bool IsValid { 
        public get() { 
            return this.client > 0 && this.client <= MaxClients && IsClientInGame(this.client) && !IsFakeClient(this.client);
        }
    }

    property bool IsLoaded { 
        public native get();
    }

    property bool ForumBan {
        public native get();
    }

    property bool ForumGag {
        public native get();
    }

    public native bool GetDiscordName(char[] buffer, int maxLen);

    public native bool GetDiscordId(char[] buffer, int maxLen);

    public native bool GetDiscordNumber(char[] buffer, int maxLen);

    public native bool GetUsername(char[] buffer, int maxLen);
}

// 读取服务器ServerId
native int  Core_GetServerId();
// 读取服务器ModId
native int  Core_GetSrvModId();
// 读取服务器模式名称
native void Core_GameModName(char[] buffer, int maxLen);
// 读取服务器缩写
native void Core_GameTagName(char[] buffer, int maxLen);

// 推送错误消息
native void Core_PushError(bool push, const char[] module, const char[] func, const char[] format, any ...);
// 推送日志
native void Core_PushLog(bool push, const char[] module, const char[] func, const char[] format, any ...);

// 通过PlayerId查玩家实例
native Player Core_FindByPId(int pid);

forward void Core_OnServerLoad(int sid, int mod);
forward void Core_OnClientSign(Player player);
forward void Core_OnClientLoad(Player player);
forward void Core_OnAnotherDay(int today);

public SharedPlugin __pl_fys_Core =
{
	name = "fys-Core",
	file = "fys.core.smx",
#if defined REQUIRE_PLUGIN
    required = 1
#else
    required = 0
#endif
};

#if !defined REQUIRE_PLUGIN
public void __pl_fys_Core_SetNTVOptional()
{
    MarkNativeAsOptional("Core_GetServerId");
    MarkNativeAsOptional("Core_GetSrvModId");
    MarkNativeAsOptional("Core_GameModName");
    MarkNativeAsOptional("Core_GameTagName");
    MarkNativeAsOptional("Core_PushError");
    MarkNativeAsOptional("Core_PushLog");
    MarkNativeAsOptional("Core_FindByPId");

    MarkNativeAsOptional("Player.Player");
    MarkNativeAsOptional("Player.IsLoaded.get");
    MarkNativeAsOptional("Player.PId.get");
    MarkNativeAsOptional("Player.UId.get");
    MarkNativeAsOptional("Player.Coin.get");
    MarkNativeAsOptional("Player.FirstJoin.get");
    MarkNativeAsOptional("Player.LastSeen.get");
    MarkNativeAsOptional("Player.Connections.get");
    MarkNativeAsOptional("Player.Onlines.get");
    MarkNativeAsOptional("Player.SignTimes.get");
    MarkNativeAsOptional("Player.SignDate.get");
    MarkNativeAsOptional("Player.SignKeep.get");
    MarkNativeAsOptional("Player.PlayTotal.get");
    MarkNativeAsOptional("Player.SpecTotal.get");
    MarkNativeAsOptional("Player.AliveTime.get");
    MarkNativeAsOptional("Player.PlaySession.get");
    MarkNativeAsOptional("Player.SepcSession.get");
    MarkNativeAsOptional("Player.OnlineToday.get");
    MarkNativeAsOptional("Player.PlayedToday.get");
    MarkNativeAsOptional("Player.ForumBan.get");
    MarkNativeAsOptional("Player.ForumGag.get");
    MarkNativeAsOptional("Player.GetUsername");
    MarkNativeAsOptional("Player.GetDiscordName");
    MarkNativeAsOptional("Player.GetDiscordId");
    MarkNativeAsOptional("Player.GetDiscordNumber");
}
#endif