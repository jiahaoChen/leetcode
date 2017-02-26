/* C implementation QuickSort */
#include<stdio.h>
#include <iostream>
using namespace std;
// A utility function to swap two elements
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
	array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition (int arr[], int low, int high)
{
	int pivot = arr[high];
	int mid = low;
	int index = high;
	while (mid < high)
	{
		if (arr[mid] > pivot)
		{
			swap(&arr[mid], &arr[--high]);
		}
		else if (arr[mid] <= pivot)
		{
			swap(&arr[mid++], &arr[low++]);
		}
	}
	swap(&arr[mid], &arr[index]);
	return mid;
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
	if (high <= low)
		return;
	int mid = partition(arr, low, high);
	quickSort(arr, low, mid-1);
	quickSort(arr, mid+1, high);
}

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// Driver program to test above functions
int main()
{
	// int arr[] = {10, 7, 8, 9, 1, 5};
	int arr[] = {2,2,3,4,3,2,3,4,4,2,3,4,5,2,3,4,6,3,2,4};
	int n = sizeof(arr)/sizeof(arr[0]);
	printf("Input array: \n");
	printArray(arr, n);
	quickSort(arr, 0, n-1);
	printf("Sorted array: \n");
	printArray(arr, n);
	return 0;
}
