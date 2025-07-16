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
        log_error("%dB allocation failed", size);
    }

    // return allocated memory
    return memory;
}

void* memory_reallocate(void* memory, const u32 old_size, const u32 new_size)
{
    // asserts
    assert(tracker.running == true, "memory system not initialized");
    assert(old_size > 0, "old memory size should be greater than 0B");
    assert(new_size > 0, "reallocation size should be greater than 0B");
    assert(old_size != new_size, "can't reallocate same size of memory");
    assert(memory != null, "invalid memory");

    // reallocate memory
    void* new_memory = realloc(memory, new_size);

    // track
    if (new_memory)
    {
        tracker.system_calls++;
        tracker.allocated += new_size - old_size;
    }
    else 
    {
        log_error("%dB reallocation failed", new_memory);
    }

    // return reallocated memory
    return new_memory;
}

void memory_free(void* memory, const u32 size)
{
    // asserts
    assert(tracker.running == true, "memory system not initialized");
    assert(size > 0, "free size should be greater than 0B");
    assert(memory != null, "invalid memory");

    // free memory
    free(memory);

    // track
    tracker.system_calls++;
    tracker.freed += size;
}
