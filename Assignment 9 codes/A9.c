#include <stdio.h>

#define MAX 100
#define MOISTURE_LIMIT 30.0

// Structure to store field data
typedef struct {
    int id;
    float moisture;
    float temperature;
    float humidity;
    int cropHealth;
    float latitude;
    float longitude;
} Field;

// Function to input field data
void inputData(Field f[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("\nEnter details for Field %d\n", i + 1);

        printf("Field ID: ");
        scanf("%d", &f[i].id);

        printf("Soil Moisture (%%): ");
        scanf("%f", &f[i].moisture);

        printf("Temperature: ");
        scanf("%f", &f[i].temperature);

        printf("Humidity (%%): ");
        scanf("%f", &f[i].humidity);

        printf("Crop Health (0-100): ");
        scanf("%d", &f[i].cropHealth);

        printf("Latitude: ");
        scanf("%f", &f[i].latitude);

        printf("Longitude: ");
        scanf("%f", &f[i].longitude);
    }
}

// Function to save data into file
void saveData(Field f[], int n)
{
    FILE *fp;
    int i;

    fp = fopen("fielddata.txt", "w");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    for (i = 0; i < n; i++)
    {
        fprintf(fp, "%d %.2f %.2f %.2f %d %.6f %.6f\n",
                f[i].id,
                f[i].moisture,
                f[i].temperature,
                f[i].humidity,
                f[i].cropHealth,
                f[i].latitude,
                f[i].longitude);
    }

    fclose(fp);

    printf("\nData saved successfully!\n");
}

// Function to generate field report
void generateReport()
{
    FILE *fp;
    Field f;
    int count = 0;

    fp = fopen("fielddata.txt", "r");

    if (fp == NULL)
    {
        printf("Error reading file!\n");
        return;
    }

    printf("\n========== FIELD MONITORING REPORT ==========\n");

    while (fscanf(fp, "%d %f %f %f %d %f %f",
                  &f.id,
                  &f.moisture,
                  &f.temperature,
                  &f.humidity,
                  &f.cropHealth,
                  &f.latitude,
                  &f.longitude) == 7)
    {
        count++;

        printf("\nField ID       : %d", f.id);
        printf("\nSoil Moisture  : %.2f%%", f.moisture);
        printf("\nTemperature    : %.2f C", f.temperature);
        printf("\nHumidity       : %.2f%%", f.humidity);
        printf("\nCrop Health    : %d%%", f.cropHealth);
        printf("\nLatitude       : %.6f", f.latitude);
        printf("\nLongitude      : %.6f", f.longitude);

        // Irrigation condition
        if (f.moisture < MOISTURE_LIMIT)
        {
            printf("\nStatus         : NEEDS IRRIGATION");
        }
        else
        {
            printf("\nStatus         : NO IRRIGATION REQUIRED");
        }

        // Crop health condition
        if (f.cropHealth < 50)
        {
            printf("\nCrop Condition : POOR");
        }
        else if (f.cropHealth < 75)
        {
            printf("\nCrop Condition : MODERATE");
        }
        else
        {
            printf("\nCrop Condition : HEALTHY");
        }

        printf("\n---------------------------------------------\n");
    }

    if (count == 0)
    {
        printf("No field records found.\n");
    }

    fclose(fp);
}

// Main function
int main()
{
    Field f[MAX];
    int n;

    printf("========================================\n");
    printf(" AGRICULTURAL ROBOT FIELD MONITORING\n");
    printf("========================================\n");

    printf("\nEnter number of fields: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
    {
        printf("Invalid number of fields!\n");
        return 1;
    }

    // Input sensor readings
    inputData(f, n);

    // Store data in file
    saveData(f, n);

    // Read stored data and generate report
    generateReport();

    printf("\nReport generated successfully!\n");

    return 0;
}

