#include "core/debug/logger.h"
#include "core/memory/memory.h"

int main(const int argc, const char** argv)
{
    // statrup
    memory_system_startup();

    u8 age_count = 5;
    u8* ages = memory_allocate(age_count * sizeof(u8));
    ages[0] = 14;
    ages[1] = 16;
    ages[2] = 44;
    ages[3] = 42;
    ages[4] = 5;
    for (u8 i = 0; i < age_count; i++)
        log_info("%d. %d", (i+1), ages[i]);
    memory_free(ages, age_count * sizeof(u8));
    
    // shutdown
    memory_system_shutdown();
    return 0;
}

