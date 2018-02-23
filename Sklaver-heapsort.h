#ifndef __heapsort_h
#define __heapsort_h



void heapSorts(int* a);

int deletemax(int* a);

void buildheap(int* a);

void heapify(int* a, int i);

int issorted(int* a, int n);

#endif