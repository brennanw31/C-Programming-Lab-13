#include <stdio.h>
#include <stdlib.h>

typedef struct tempstruct{
    float temperature;
    float humidity;
}Weather;

Weather** readRecord(FILE*);
int comparison(void*,void*);
int binarySearch(void**,int,int,void*);
void freeArr(Weather**,int);