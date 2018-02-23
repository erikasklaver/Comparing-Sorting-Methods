/*
File: Sklaver-quicksort.c

Author: Erika Sklaver 
Date: 02/24/2017
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Sklaver-quicksort.h" 

//Erika$ gcc Sklaver-quicksort.c -o Quicksort -Wall
//Erika$ ./Quicksort

const int N = 10;

/*
partition function used within sort to split up the array
*/
int partition(int* a, int p, int r){

	int pivot = a[r];
	int i = p-1;

	for(int j=p; j<r; j++){
		if(a[j]<=pivot){
			i++;
			int index = a[i];
			a[i]=a[j];
			a[j]=index; 
		}
	}

	int holder=a[i+1];
	a[i+1]=a[r];
	a[r]=holder;

	return i+1; 

}

/*
quicksort in place array a of length n;
assume array is allocated and populated with data prior to this call
*/
void quicksort(int* a, int p, int r){

	if(p<r){
		int q = partition(a, p, r);
		//printf("%d \n", q);
		quicksort(a,p,q-1);
		quicksort(a, q+1, r);
	}


}

/*
return 1 if a is sorted (in non-decreasing order); and 0 otherwise
assume array is allocated and populated with data prior to this call
*/
int issorted(int* a, int n){

	for(int i=0; i<n; i++){
		if(i+1<n){
			if(a[i]>a[i+1]){
				//not sorted
				return 0;
			}

		}
		
	}

	return 1;

}

int main (void){
	//declare and allocate the array 
	int *a;
	a = (int *)malloc(sizeof(int)*N); 

	//populate the array with random data
	srand(time(NULL)); 

	for (int i=0; i<N; i++){
		a[i] = (float)rand();
	}


	clock_t begin = clock();

	//call quicksort
	quicksort(a, 0, N-1);

	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;


	//test that the array is sorted 

	// if (issorted(a,N)){
	// 	printf("Array is sorted!\n");
	// }else{
	// 	printf("Oops! Array is NOT sorted!\n");
	// }
	

	printf("Time: %f seconds \n", time_spent);

	return 1;
}