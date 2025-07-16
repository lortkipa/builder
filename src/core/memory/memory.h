#pragma once

#include "defines.h"

typedef struct memory_tracker {
    b8 running;
    u32 allocated;
    u32 freed;
    u32 system_calls;
} memory_tracker;

memory_tracker memory_tracker_get(void);

void memory_system_startup(void);

void memory_system_shutdown(void);

void* memory_allocate(const u32 size);

void* memory_reallocate(void* memory, const u32 old_size, const u32 new_size);

void memory_free(void* memory, const u32 size);
