#include "core/debug/assert.h"
#include "core/debug/logger.h"

int main(const int argc, const char** argv)
{
    assert(1 == 1, "shit, app failed");
    assert(1 == 2, "shit, app failed");

    log_error("logging error %f", 3.14f);
    log_warning("logging warning %f", 3.14f);
    log_success("logging success %f", 3.14f);
    log_info("logging info %f", 3.14f);

    return 0;
}

