#include <stdio.h>
#include <time.h>

int main()
{
    int year, month, days, i;
    int monthDays[] = {31, 28, 31, 30, 31, 30,
                       31, 31, 30, 31, 30, 31};

    char *months[] = {"January", "February", "March",
                      "April", "May", "June", "July",
                      "August", "September", "October",
                      "November", "December"};

    printf("Enter year: ");
    scanf("%d", &year);

    // Check leap year
    if ((year % 400 == 0) ||
        (year % 4 == 0 && year % 100 != 0))
    {
        monthDays[1] = 29;
    }

    for (month = 0; month < 12; month++)
    {
        struct tm date = {0};

        date.tm_year = year - 1900;
        date.tm_mon = month;
        date.tm_mday = 1;

        mktime(&date);

        printf("\n\n       %s %d\n", months[month], year);
        printf("Sun Mon Tue Wed Thu Fri Sat\n");

        // Print spaces before the first day
        for (i = 0; i < date.tm_wday; i++)
            printf("    ");

        days = monthDays[month];

        for (i = 1; i <= days; i++)
        {
            printf("%3d ", i);

            if ((i + date.tm_wday) % 7 == 0)
                printf("\n");
        }

        printf("\n");
    }

    return 0;
}