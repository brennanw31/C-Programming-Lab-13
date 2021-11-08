#include "lab13.h"

/*This function populates an array with Weather structs whose temperature and humidity
values are read from a file. The size of the array is expected to be the first integer listed
in the file. All memory is dynamically allocated*/
Weather** readRecord(FILE *fp)
{
	if(!fp){
		printf("***Error: File not available***\n");
		return(NULL);
	}
	Weather **p; int numElems;
	fscanf(fp, "%d", &numElems);
	p = malloc(numElems*sizeof(Weather*));
	int j = 0;`
	while(!feof(fp)){
		p[j] = malloc(sizeof(Weather));
		fscanf(fp, "%f,%f\n", &p[j]->temperature, &p[j]->humidity);
		j++;
	}
	fclose(fp);
	return(p);
}

/*This function compares two Weather structs based on their temperature member.
It returns 1 if the first parameter is greater than the second, and -1 if the
opposite. It returns 0 if the two are equivalent.*/
int comparison(void *n, void *m)
{
	if(((Weather*)(n))->temperature > ((Weather*)(m))->temperature) return(1);
	else if(((Weather*)(n))->temperature < ((Weather*)(m))->temperature) return (-1);
	else return(0);
}

/*This function recursively searches for a member of an array whose
temperature value is equivalent to the query parameter passed to the function.
It returns the position of the array in which it is found, or -1 if it is not found*/
int binarySearch(void **p, int first, int last, void *query)
{
	if(!p){ printf("***Error: Array is NULL***\n"); return(-1); }
	if(first >= last){ return(-1); }
	int mid = (first+last)/2;
	if(comparison(p[mid], query) == 1){
		return(binarySearch(p, first, mid-1, query));
	}
	else if(comparison(p[mid], query) == -1){
		return(binarySearch(p, mid+1, last, query));
	}
	else return(mid);
}

/*This function frees all previosuly allocated memories*/
void freeArr(Weather **p, int numElems)
{
	for(int i = 0; i<numElems; i++){
		free(p[i]);
	}
	free(p);
}









