#if defined _fys_Opts_Include_
    #endinput
#endif

#define _fys_Opts_Include_

forward void Opts_OnClientLoad(int client);

native void  Opts_GetOptString(int client, const char[] key, char[] val, int maxLen, const char[] defVal = "null");
native int   Opts_GetOptInteger(int client, const char[] key, const int defVal = 0);
native bool  Opts_GetOptBool(int client, const char[] key, const bool defVal = false);
native float Opts_GetOptFloat(int client, const char[] key, const float defVal = 0.0);

native void Opts_SetOptString(int client, const char[] key, const char[] val);
native void Opts_SetOptInteger(int client, const char[] key, const int val);
native void Opts_SetOptBool(int client, const char[] key, const bool val);
native void Opts_SetOptFloat(int client, const char[] key, const float val);

methodmap Cookie
{
    property int owner {
        public get() { 
            return view_as<int>(this);
        }
    }

    public Cookie(int client) {
        return view_as<Cookie>(client);
    }

    public void GetString(const char[] key, char[] val, int maxLen, const char[] defVal = "null") {
        Opts_GetOptString(this.owner, key, val, maxLen, defVal);
    }

    public int GetInteger(const char[] key, const int defVal = 0) {
        return Opts_GetOptInteger(this.owner, key, defVal);
    }

    public bool GetBool(const char[] key, const bool defVal = false) {
        return Opts_GetOptBool(this.owner, key, defVal);
    }

    public float GetFloat(const char[] key, const float defVal = 0.0) {
        return Opts_GetOptFloat(this.owner, key, defVal);
    }

    public void SetString(const char[] key, const char[] val) {
        Opts_SetOptString(this.owner, key, val);
    }

    public void SetInteger(const char[] key, const int val) {
        Opts_SetOptInteger(this.owner, key, val);
    }

    public void SetBool(const char[] key, const bool val) {
        Opts_SetOptBool(this.owner, key, val);
    }

    public void SetFloat(const char[] key, const float val) {
        Opts_SetOptFloat(this.owner, key, val);
    }
}

public SharedPlugin __pl_fys_Opts =
{
    name = "fys-Opts",
    file = "fys.opts.smx",
#if defined REQUIRE_PLUGIN
    required = 1
#else
    required = 0
#endif
};