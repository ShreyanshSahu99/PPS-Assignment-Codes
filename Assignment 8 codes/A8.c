#include <stdio.h>
#include <string.h>

struct Sensor
{
    int id;
    char type[20];
    float value, min, max;
    char status[10];
};

// Function to input sensor details
int input(struct Sensor *s, int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        printf("\nEnter details of Sensor %d\n", i + 1);

        printf("Enter ID: ");
        scanf("%d", &s[i].id);

        printf("Enter Type: ");
        scanf("%19s", s[i].type);

        printf("Enter Reading: ");
        scanf("%f", &s[i].value);

        printf("Enter Minimum Range: ");
        scanf("%f", &s[i].min);

        printf("Enter Maximum Range: ");
        scanf("%f", &s[i].max);
    }

    return 0;
}

// Function to check sensor status
int checkStatus(struct Sensor *s, int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        if(s[i].value >= s[i].min && s[i].value <= s[i].max)
            strcpy(s[i].status, "Normal");
        else
            strcpy(s[i].status, "Abnormal");
    }

    return 0;
}

// Function to display all sensor records
int display(struct Sensor *s, int n)
{
    int i;

    printf("\n--- SENSOR RECORDS ---\n");

    for(i = 0; i < n; i++)
    {
        printf("\nID: %d", s[i].id);
        printf("\nType: %s", s[i].type);
        printf("\nReading: %.2f", s[i].value);
        printf("\nMinimum Range: %.2f", s[i].min);
        printf("\nMaximum Range: %.2f", s[i].max);
        printf("\nStatus: %s\n", s[i].status);
    }

    return 0;
}

// Function to calculate average reading
int average(struct Sensor *s, int n, char type[])
{
    int i, count = 0;
    float sum = 0;

    for(i = 0; i < n; i++)
    {
        if(strcmp(s[i].type, type) == 0)
        {
            sum = sum + s[i].value;
            count++;
        }
    }

    if(count > 0)
        printf("\nAverage reading of %s = %.2f\n", type, sum / count);
    else
        printf("\nNo matching sensor found.\n");

    return 0;
}

// Function to display abnormal sensors using pointer
int abnormal(struct Sensor *s, int n)
{
    int i, found = 0;
    struct Sensor *ptr = s;

    printf("\n--- ABNORMAL SENSORS ---\n");

    for(i = 0; i < n; i++, ptr++)
    {
        if(strcmp(ptr->status, "Abnormal") == 0)
        {
            printf("\nID: %d", ptr->id);
            printf("\nType: %s", ptr->type);
            printf("\nReading: %.2f\n", ptr->value);
            found = 1;
        }
    }

    if(found == 0)
        printf("No abnormal sensors found.\n");

    return 0;
}

int main()
{
    struct Sensor s[100];
    int n;
    char type[20];

    printf("Enter number of sensors: ");
    scanf("%d", &n);

    if(n < 1 || n > 100)
    {
        printf("Invalid number of sensors.\n");
        return 0;
    }

    input(s, n);

    checkStatus(s, n);

    display(s, n);

    printf("\nEnter sensor type to calculate average: ");
    scanf("%19s", type);

    average(s, n, type);

    abnormal(s, n);

    return 0;
}
