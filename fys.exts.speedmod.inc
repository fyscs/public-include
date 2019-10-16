#if defined _fys_Exts_SpeedMod_Include_
    #endinput
#endif

#define _fys_Exts_SpeedMod_Include_


// speed    -> 1.1为提速10%
// lifetime -> 持续时间, 每次player_spawn重置
// override -> 强制覆盖设置, 如果不为true但是lifetime没到时间, 会设置失败
native bool Exts_SM_SetSpeed(int client, float speed = 1.0, float lifetime = 10.0, bool override = false);

// height   -> 1.1为增加高度10%
// length   -> 1.1为增加距离10%
// lifetime -> 持续时间, 每次player_spawn重置
// override -> 强制覆盖设置, 如果不为true但是lifetime没到时间, 会设置失败
native bool Exts_SM_SetXJump(int client, float height = 1.0, float length = 1.0, float lifetime = 10.0, bool override = false);

public SharedPlugin __pl_fys_Exts_SpeedMod =
{
    name = "fys-Exts-SpeedMod",
    file = "fys.exts.speedmod.smx",
#if defined REQUIRE_PLUGIN
    required = 1
#else
    required = 0
#endif
};

#if !defined REQUIRE_PLUGIN
public __ext_fys_Exts_SpeedMod_SetNTVOptional()
{
	MarkNativeAsOptional("Exts_SM_SetSpeed");
    MarkNativeAsOptional("Exts_SM_SetXJump");
}
#endif