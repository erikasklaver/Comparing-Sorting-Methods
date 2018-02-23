/*
File: Sklaver-heapsort.c

Author: Erika Sklaver 
Date: 02/24/2017
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Sklaver-heapsort.h"

//Erika$ gcc Sklaver-heapsort.c -o Heapsort -Wall
//Erika$ ./Heapsort 

const int N = 10;

//keeps track of the number of max "nodes" deleted
int numdeleted = 0;


void heapSorts(int* a){

	//build a max heap so that it satisfies heap properties
	buildheap(a);

	//call deletemax N times until the array is sorted 
	for(int i=N; i>0; i--){
		deletemax(a);
	}

}

int deletemax(int* a){
	
	//since the heap is built, the max value is at the root
	int root = a[0];

	//put the next largest value in its correct spot on the array
	a[N-numdeleted-1]=root;
	a[0]=a[N-numdeleted-1];

	//increment the number of elements sorted from the back 
	numdeleted++;

	//heapify the rest of the array 
	heapify(a, 0);

	//return the value of the number just "deleted"
	return a[N-numdeleted-1];
}

//construct the initial heap with N elements that has heap properties 
void buildheap(int* a){

	//go through every node that has children and heapify the mini heaps
	for(int i= N/2; i>0; i--){
		heapify(a, i);
	}

}

//make heap have heap properties
void heapify(int* a, int i){

	int leftchild = 2i+1;
	int rightchild = 2i+2;
	int max_index = 0;

	//if there are no left children then there are no children at all 
	//so nothing to heapify 
	if(leftchild > N-numdeleted-1){ 
		return;
	}
	
	//if the left child is greater than its parent then it is the max of the two
	//otherwise the parent is the max	
	if(a[leftchild]>a[i]){
		max_index = leftchild;
	}else{
		max_index = i;
	}
	
	//if there is a right child, then see if it is the maximum of the three
	if(rightchild <= N-numdeleted-1){
		if(a[rightchild]>a[max_index]){
			max_index = rightchild;
		}
	}
	
	//make the maximum the parent of the other two 
	int holder = a[max_index];
	a[max_index] = a[i]; 
	a[i]=holder;

	//call heapify again to make sure the bottom branches also satisfy
	//heap properties
	heapify(a, max_index);

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
	a = (int *)malloc(sizeof(int)*100); 

	//populate the array with random data
	srand(time(NULL)); 


	for (int i=0; i<N; i++){
		a[i] = rand()%10;
	}


	heapSorts(a);

	//issorted(a,N);

	return 1; 
}