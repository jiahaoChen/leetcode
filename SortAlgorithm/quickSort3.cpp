// C++ program for 3-way quick sort
// #include <bits/stdc++.h>
#include <stdio.h>
// using namespace std;
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

// A utility function to print an array
void printarr(int a[], int n)
{
	for (int i = 0; i < n; ++i)
		printf("%d ", a[i]);
	printf("\n");
}

/* This function partitions a[] in three parts
a) a[l..i] contains all elements smaller than pivot
b) a[i+1..j-1] contains all occurrences of pivot
c) a[j..r] contains all elements greater than pivot */

//It uses Dutch National Flag Algorithm
void partition(int a[], int low, int high, int &i, int &j)
{
	int pivot = a[high];
	int mid = low;
	while (mid <= high)
	{
		if (a[mid] > pivot)
			swap(&a[mid], &a[high--]);
		else if (a[mid] == pivot)
			mid++;
		else
			swap(&a[mid++], &a[low++]);
	}
	i = low-1;
	j = mid;
}

// 3-way partition based quick sort
void quicksort(int a[], int low, int high)
{
	if (high <= low)
		return;
	int i, j;
	partition(a, low, high, i, j);
	quicksort(a, low, i);
	quicksort(a, j, high);
}

// Driver program
int main()
{
	// int a[] = {4, 9, 4, 4, 1, 9, 4, 4, 9, 4, 4, 1, 4};
	// int a[] = {4, 39, 54, 14, 31, 89, 44, 34, 59, 64, 64, 11, 41};
	// int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	// int a[] = {91, 82, 73, 64, 55, 46, 37, 28, 19, 10};
	// int a[] = {4, 9, 4, 4, 9, 1, 1, 1};
	int a[] = {2,2,3,4,3,2,3,4,4,2,3,4,5,2,3,4,6,3,2,4};
	// int a[] = {2,1};
	// int a[] = {0};
	int size = sizeof(a) / sizeof(int);

	printarr(a, size);
	quicksort(a, 0, size - 1);
	printarr(a, size);
	return 0;
}
