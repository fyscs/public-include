#if defined _fys_Exts_Movement_Include_
    #endinput
#endif

#define _fys_Exts_Movement_Include_


// 设置玩家跳跃Buff
// height   -> 1.1为增加高度10%
// length   -> 1.1为增加距离10%
// lifetime -> 持续时间, 每次player_spawn重置
// override -> 强制覆盖设置, 如果不为true但是lifetime没到时间, 会设置失败
native bool Exts_MM_SetXJump(int client, float height = 1.0, float length = 1.0, float lifetime = 10.0, bool override = false);

// 获取玩家的实时速度
native float Exts_MM_GetSpeed(int client);

// 获取玩家之间的距离(缓存?)
// forceUpdate -> 强制刷新位置关系, 否则使用缓存数据
native float Exts_MM_GetDistance(int client, int target, bool forceUpdate = false);

// 获取玩家准星瞄准的实体
// forceFilterClient -> 强制过滤非玩家实体, 否者为Edict
// 本方法不执行穿墙, 若需要执行穿墙请使用SM native
// [int GetClientAimTarget(int client, bool only_clients)]
native int Exts_MM_GetAimTarget(int client, bool forceFilterClient = false);

// 获取玩家是否处于蹲下状态
native bool Exts_MM_IsDucking(int client);

// 检测玩家是否卡住
native bool Exts_MM_IsStuck(int client);

// 获取玩家离地面或脚底实体的距离
// 如果失败则返回值 < -1.0
native float Exts_MM_GetGroundDistance(int client);

// 获取玩家脚底地面/实体的坐标
native bool Exts_MM_GetVerticalGroudPos(int client, float fPos[3]);

public SharedPlugin __pl_fys_Exts_Movement =
{
    name = "fys-Exts-Movement",
    file = "fys.exts.movement.smx",
#if defined REQUIRE_PLUGIN
    required = 1
#else
    required = 0
#endif
};

#if !defined REQUIRE_PLUGIN
public void __pl_fys_Exts_Movement_SetNTVOptional()
{
    MarkNativeAsOptional("Exts_MM_SetXJump");
    MarkNativeAsOptional("Exts_MM_GetSpeed");
    MarkNativeAsOptional("Exts_MM_GetDistance");
    MarkNativeAsOptional("Exts_MM_GetAimTarget");
    MarkNativeAsOptional("Exts_MM_IsDucking");
    MarkNativeAsOptional("Exts_MM_IsStuck");
    MarkNativeAsOptional("Exts_MM_GetGroundDistance");
    MarkNativeAsOptional("Exts_MM_GetVerticalGroudPos");
}
#endif