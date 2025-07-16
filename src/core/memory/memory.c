#include "core/memory/memory.h"
#include "core/debug/assert.h"
#include "core/debug/logger.h"

#include <stdlib.h>

static memory_tracker tracker = {};

memory_tracker memory_tracker_get(void)
{
    // asserts
    assert(tracker.running == true, "memory system not initialized");

    // return tracker
    return tracker;
}

void memory_system_startup(void)
{
    // asserts
    assert(tracker.running == false, "memory system is already initialized");

    // start tracking
    tracker.running = true;
    log_info("memory tracking started");

    // zero out stats
    tracker.allocated = 0;
    tracker.freed = 0;
    tracker.system_calls = 0;
}

void memory_system_shutdown(void)
{
    // asserts
    assert(tracker.running == true, "memory system not initialized");
    log_info("memory tracking stoped | allocated %dB | freed %dB | system calls %d | ",
            tracker.allocated, tracker.freed, tracker.system_calls);
    
    // stop tracking
    tracker.running = true;
}

void* memory_allocate(const u32 size)
{
    // asserts
    assert(tracker.running == true, "memory system not initialized");
    assert(size > 0, "allocation size should be greater than 0B");

    // allocate memory
    void* memory = malloc(size);

    // track
    if (memory)
    {
        tracker.system_calls++;
        tracker.allocated += size;
    }
    else 
    {
        log_error("%dB allocation failed");
    }

    // return allocated memory
    return memory;
}

void memory_free(void* memory, const u32 size)
{
    // asserts
    assert(tracker.running == true, "memory system not initialized");
    assert(size > 0, "free size should be greater than 0B");
    assert(memory != null, "memory is null");

    // free memory
    free(memory);

    // track
    tracker.system_calls++;
    tracker.freed += size;
}
