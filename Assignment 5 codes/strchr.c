#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "apple";

    char *ptr = strrchr(str, 'a');

    if(ptr != NULL)
        printf("%s", ptr);
    else
        printf("Not found");

    return 0;
}
