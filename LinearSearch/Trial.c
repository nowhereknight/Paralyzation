#include <omp.h>
#include <stdio.h>
#include "linearSearchParallel.h"
#include "linearSearch.h"
#include "randomizeArray.h"
#define NUM 100000000

int main(){
	int *ptrA=(int*) calloc(NUM,sizeof(int));
	int *ptrB=(int*) calloc(NUM,sizeof(int));
	randomizeArray(ptrA,NUM);
	randomizeArray(ptrB,NUM);
	double startTime, totalTime;

	startTime=omp_get_wtime();
	linearSearchParallel(ptrA,NUM,-1);
	totalTime=omp_get_wtime()-startTime;


	printf("\nParallel final Time: %f\n",totalTime);


	startTime=omp_get_wtime();
	linearSearch(ptrB,NUM,-1);
	totalTime=omp_get_wtime()-startTime;
	printf("\nNormal final Time: %f\n",totalTime);
	free(ptrA);
	free(ptrB);

}


/*


void mergeSortParallel(int *arr, int size);
void mergeSort(int *arr, int size);
void merge(int *arr, int size1, int size2);

void merge(int *arr, int p, int q) {
    int temp[p+q];
    int ptr1=0, ptr2=0;

    while (ptr1+ptr2 < p+q) {
        if (ptr1 < p && arr[ptr1] <= arr[p+ptr2] || ptr1 < p && ptr2 >= q)
            temp[ptr1+ptr2] = arr[ptr1++];

        if (ptr2 < q && arr[p+ptr2] < arr[ptr1] || ptr2 < q && ptr1 >= p)
            temp[ptr1+ptr2] = arr[p+ptr2++];
        
    }

    for (int i=0; i < p+q; i++)
        arr[i] = temp[i];
}

void mergeSortParallel(int *arr, int size) {
    if (size == 1)
        return;  
    #pragma omp parallel
    {
	    int p = size/2, q = size-p;
	    //left half
	  	#pragma omp task shared(p,q)
	    mergeSort(arr , p);
	    //rigth half
	    #pragma omp task shared (p,q)
	    mergeSort(arr + p , q);
    	#pragma omp taskwait

    merge(arr , p , q);
	}
}

void mergeSort(int *arr, int size) {
    if (size == 1)
        return;  

	int p = size/2, q = size-p;
	//left half
	mergeSort(arr , p);
	//rigth half
	mergeSort(arr + p , q);

    merge(arr , p , q);
	
}
*/