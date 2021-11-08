#include "lab13.h"

int main(void)
{
    FILE * fp = fopen("Weather.csv", "r");
    if(fp)
    {
        Weather ** array = readRecord(fp);
        if(array)
        {
            float target;
            printf("Enter a temperature to search for: ");
            scanf("%f", &target);
            int result = binarySearch((void **)array, 0, 9999, &target);
            if(result != -1)
                printf("%f was found in position %d.\n", target, result);
            else
                printf("%f was not found within the array.\n", target);
                
            freeArr(array, 10000);
        }
        else
            printf("Error... (1)\n");
    }
    else
        printf("Error... (2)\n");

    printf("Success.\n");
    return 0;
}