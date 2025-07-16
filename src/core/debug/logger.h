#pragma once

#include "defines.h"

typedef enum log_level {
    LOG_ERROR,
    LOG_WARNING,
    LOG_SUCCESS,
    LOG_INFO
} log_level;

void _log(const log_level level, const char* msg, ...);

#define log_error(msg, ...) _log(LOG_ERROR, msg, ##__VA_ARGS__)

#define log_warning(msg, ...) _log(LOG_WARNING, msg, ##__VA_ARGS__)

#if defined(DEBUG) | defined(DEV)
    #define log_success(msg, ...) _log(LOG_SUCCESS, msg, ##__VA_ARGS__)

    #define log_info(msg, ...) _log(LOG_INFO, msg, ##__VA_ARGS__)
#else
    #define log_success(msg, ...)

    #define log_info(msg, ...)
#endif
