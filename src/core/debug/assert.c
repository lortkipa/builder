#include "core/debug/assert.h"
#include "core/debug/logger.h"

void assert_log_failure(const char* res, const char* msg, const char* path, const char* func, const u32 line)
{
    // log error
    log_error("assertion failure \"%s\": %s in %s %d at %s\n", res, msg, path, line, func);
}
