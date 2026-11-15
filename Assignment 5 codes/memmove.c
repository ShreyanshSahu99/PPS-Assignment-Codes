#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "GoodBoy1234";

    memmove(str + 1, str, 4);

    printf("%s", str);

    return 0;
}
