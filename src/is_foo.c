#include <stdbool.h>
#include <string.h>
#include <stdio.h>
bool is_foo(const char *param)
{
    if (!param)
        return false;
    else
    {
        if (strcmp(param, "foo") == 0)
            return true;
        else
            return false;
    }
}

void main()
{
    printf("%d", is_foo(NULL));
}