#pragma once

#include "defines.h"

#ifdef _WIN32
    #define debug_break() __debugbreak()
#else
    #include <signal.h>
    #define debug_break() raise(SIGTRAP)
#endif

void assert_log_failure(const char* res, const char* msg, const char* path, const char* func, const u32 line);

#if defined(DEBUG) || defined(DEV)

#define assert(res, msg)                                                  \
    if (res){}                                                            \
    else                                                                  \
    {                                                                     \
        assert_log_failure(#res, msg, __FILE__,  __FUNCTION__, __LINE__); \
        debug_break();                                                    \
    }

#else

#define assert(res, msg)

#endif
