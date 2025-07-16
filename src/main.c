#include "core/debug/logger.h"
#include "core/memory/memory.h"
#include "core/containers/string.h"

int main(const int argc, const char** argv)
{
    // statrup
    memory_system_startup();

    string str = string_create();
    string_set(&str, "Nikoloz");
    log_info("| %s | %d | ", str.data, str.length);
    string_setf(&str, "Dima %d", 14);
    log_info("| %s | %d | ", str.data, str.length);
    string_destroy(&str);
    
    // shutdown
    memory_system_shutdown();
}

