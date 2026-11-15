#include <stdio.h>
#include <string.h>

int main()
{
    char src[] = "Hellooo !!";
    char dest[20];

    memcpy(dest, src, strlen(src) + 1);

    printf("%s", dest);

    return 0;
}
