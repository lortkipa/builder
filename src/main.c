#include <stdio.h>

int main(const int argc, const char** argv)
{
    printf("arg count: %d\n", argc);

    for (int i = 0; i < argc; i++)
    {
        printf("%d. %s\n", i+1, argv[i]);
    }

    return 0;
}

