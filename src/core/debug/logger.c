#include "core/debug/logger.h"

#include <stdio.h>
#include <stdarg.h>

static const char* level_colors[] =
{
    [LOG_ERROR  ] = "\e[0;31m", // red
    [LOG_WARNING] = "\e[0;33m", // yellow
    [LOG_SUCCESS] = "\e[0;32m", // green
    [LOG_INFO   ] = "\e[0;34m"  // blue
};

static const char* level_headers[] =
{
    [LOG_ERROR  ] = "ERROR",
    [LOG_WARNING] = "WARNING",
    [LOG_SUCCESS] = "SUCCESS",
    [LOG_INFO   ] = "INFO"
};

void _log(const log_level level, const char* msg, ...)
{
    // set color and log header
    printf("%s[%s]: ", level_colors[level], level_headers[level]);

    // init args
    va_list list;
    va_start(list, msg);

    // log formated
    vprintf(msg, list);

    // terminate args
    va_end(list);

    // reset start new line
    puts("\e[0;37m");
}
