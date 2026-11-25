#include <stdio.h>
#include <string.h>

struct device
{
    int id;
    char type[10];
    float vf, ir, vr;
    char status[6];
};

struct Limits
{
    float maxVf, maxIr, minVr;
};

union DeviceLimits
{
    struct Limits diode;
    struct Limits bjt;
    struct Limits mosfet;
    struct Limits led;
};

int main()
{
    struct device d[100];
    union DeviceLimits u;
    struct Limits *lim;
    int n, i;

    printf("Enter number of devices: ");
    scanf("%d", &n);

    if(n < 1 || n > 100)
    {
        printf("Invalid number of devices.");
        return 0;
    }

    for(i = 0; i < n; i++)
    {
        printf("\nEnter details of Device %d\n", i + 1);

        printf("Enter Device ID: ");
        scanf("%d", &d[i].id);

        printf("Enter Device Type: ");
        scanf("%9s", d[i].type);

        printf("Enter Forward Voltage (Vf): ");
        scanf("%f", &d[i].vf);

        printf("Enter Reverse Leakage Current (Ir): ");
        scanf("%f", &d[i].ir);

        printf("Enter Rated Voltage (Vr): ");
        scanf("%f", &d[i].vr);

        if(strcmp(d[i].type, "Diode") == 0)
        {
            u.diode.maxVf = 0.7;
            u.diode.maxIr = 5;
            u.diode.minVr = 50;
            lim = &u.diode;
        }
        else if(strcmp(d[i].type, "BJT") == 0)
        {
            u.bjt.maxVf = 0.9;
            u.bjt.maxIr = 10;
            u.bjt.minVr = 40;
            lim = &u.bjt;
        }
        else if(strcmp(d[i].type, "MOSFET") == 0)
        {
            u.mosfet.maxVf = 4.0;
            u.mosfet.maxIr = 1;
            u.mosfet.minVr = 60;
            lim = &u.mosfet;
        }
        else if(strcmp(d[i].type, "LED") == 0)
        {
            u.led.maxVf = 3.6;
            u.led.maxIr = 10;
            u.led.minVr = 5;
            lim = &u.led;
        }
        else
        {
            printf("Invalid device type.\n");
            return 0;
        }

        if(d[i].vf > lim->maxVf ||
           d[i].ir > lim->maxIr ||
           d[i].vr < lim->minVr)
        {
            strcpy(d[i].status, "FAIL");
        }
        else
        {
            strcpy(d[i].status, "PASS");
        }
    }

    printf("\n----- DEVICE REPORT -----\n");

    for(i = 0; i < n; i++)
    {
        printf("\nDevice ID: %d", d[i].id);
        printf("\nDevice Type: %s", d[i].type);
        printf("\nForward Voltage: %.2f", d[i].vf);
        printf("\nReverse Leakage Current: %.2f", d[i].ir);
        printf("\nRated Voltage: %.2f", d[i].vr);
        printf("\nStatus: %s\n", d[i].status);
    }

    printf("\n--- OUT OF SPECIFICATION DEVICES ---\n");

    for(i = 0; i < n; i++)
    {
        if(strcmp(d[i].status, "FAIL") == 0)
        {
            printf("\nID: %d | Type: %s",
                   d[i].id, d[i].type);
        }
    }

    return 0;
}
