#if defined _fys_Core_Include_
    #endinput
#endif

#define _fys_Core_Include_

#define PI_VERSION "1.2.5"

#define foreachAction(%1, %2, %3) for (int %1 = %2; %1 <= %3; %1++)
#define foreachClient(%1) for (int %1 = 1; %1 <= MaxClients; %1++) if (IsClientInGame(%1))
#define foreachPlayer(%1) for (int %1 = 1; %1 <= MaxClients; %1++) if (IsClientInGame(%1) && !IsFakeClient(%1))

#define INVALID_PLAYER -1

methodmap Player __nullable__
{
    property int client {
        public get() { 
            return view_as<int>(this);
        }
    }

    public static Player FromPId(int pid) { return Core_FindByPId(pid); }

    public native Player(int client);

    property int PId { 
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

    property bool IsValid { 
        public get() { 
            return this.client > 0 && this.client <= MaxClients && IsClientInGame(this.client) && !IsFakeClient(this.client);
        }
    }
}

native int  Core_GetServerId();
native int  Core_GetSrvModId();
native void Core_GameModName(char[] buffer, int maxLen);
native void Core_GameTagName(char[] buffer, int maxLen);

native void Core_PushError(bool push, const char[] module, const char[] func, const char[] format, any ...);
native void Core_PushLog(bool push, const char[] module, const char[] func, const char[] format, any ...);
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