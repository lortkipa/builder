#pragma once

#include "defines.h"

#define MAX_STRING_LENGTH 2000

typedef struct string {
    char* data;
    u32 length;
} string;

string string_create(void);

void string_destroy(string* str);

void string_set(string* str, const char* data);

void string_setf(string* str, const char* data, ...);
