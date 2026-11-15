#include <stdio.h>

int main()
{
    char str[100];

    printf("Enter your string: ");
    fgets(str, sizeof(str), stdin);

    printf("The string you entered is : %s", str);

    return 0;
}
