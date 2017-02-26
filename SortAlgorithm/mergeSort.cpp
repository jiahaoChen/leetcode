/* C program for Merge Sort */
#include<stdlib.h>
#include<stdio.h>

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
	int n1 = m-l+1;
	int n2 = r-m;
	int L[n1];
	int R[n2];
	for (int i = 0; i < n1; ++i)
		L[i] = arr[l+i];
	for (int j = 0; j < n2; ++j)
		R[j] = arr[m+j+1];
	
	int i1 = 0;
	int i2 = 0;
	int k = l;
	while(i1 < n1 && i2 < n2)
	{
		if (L[i1] <= R[i2])
			arr[k++] = L[i1++];
		else
			arr[k++] = R[i2++];
	}

	while (i1 < n1)
		arr[k++] = L[i1++];
	while(i2 < n2)
		arr[k++] = R[i2++];
	

}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
	if (r<=l)
		return;
	int m = l + (r-l)/2;
	mergeSort(arr, l, m);
	mergeSort(arr, m+1, r);
	merge(arr, l, m, r);
}

/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

/* Driver program to test above functions */
int main()
{
	int arr[] = {12, 11, 13, 5, 6, 7};
	int arr_size = sizeof(arr)/sizeof(arr[0]);

	printf("Given array is \n");
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	printf("\nSorted array is \n");
	printArray(arr, arr_size);
	return 0;
}
