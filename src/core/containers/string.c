#include "core/debug/assert.h"
#include "core/debug/logger.h"
#include "core/containers/string.h"
#include "core/memory/memory.h"

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

string string_create(void)
{
    // init structure
    string str = 
    {
        .data = null,
        .length = 0
    };

    // return structure
    return str;
}

void string_destroy(string* str)
{
    // asserts
    assert(str != null, "invalid string");

    // free data
    if (str->data)
        memory_free(str->data, str->length);

    // zero out string
    str->data = null;
    str->length = 0;
}

void string_set(string* str, const char* data)
{
    // asserts
    assert(str != null, "invalid string");
    assert(data != null, "invalid data");

    // store old length
    const u32 old_length = str->length;

    // update string length
    str->length = strlen(data);
    
    // allocate data
    if (!str->data)
        str->data = memory_allocate(strlen(data));
    else if (str->length != old_length)
        str->data = memory_reallocate(str->data, old_length, str->length);

    // check for allocation errors
    if (!str->data)
    {
        log_error("%d length string creation failed", str->length);
        string_destroy(str);
    }

    // store the data
    memcpy(str->data, data, str->length);
    str->data[str->length] = '\0';
}

void string_setf(string* str, const char* data, ...)
{
    // asserts
    assert(str != null, "invalid string");
    assert(data != null, "invalid data");

    // init args
    va_list list;
    va_start(list, data);

    // create format
    char buffer[MAX_STRING_LENGTH];
    va_list args;
    va_start(args, data);
    vsnprintf(buffer, sizeof(buffer), data, args);
    va_end(args);

    // set new string
    string_set(str, buffer);

    // terminate args
    va_end(list);
}
