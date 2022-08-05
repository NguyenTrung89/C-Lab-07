//Tim cac phan tu chung cua 2 mang so nguyen
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <time.h>

//Generate a random number
int getRandom(int min, int max)
{
    return min + (int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
}

//Sort array ascending
void insertionSort(int arr[], int n)
{
	int i, pos, x;
	for(i = 1; i < n; i++)
	{
		x = arr[i];
		pos = i;
		while(pos > 0 && x < arr[pos-1])
		{
			arr[pos] = arr[pos-1];
			pos--;
		}
		arr[pos] = x;
	}
}

//Binary search
int binarySearch(int arr[], int n, int x)
{
	int right = n - 1; //last element index
	int left = 0; //first element index
	while(right >= left)
	{
		int mid = left + (right - left) / 2; //mid = (right+left)/2
		
		if(arr[mid] == x)
			return mid;
		//if arr[mid] < x then search in the second half of array
		if(arr[mid] < x)
			left = mid + 1;
		//if arr[mid] > x then search in the first half of array
		if(arr[mid] > x)
			right = mid - 1;
	}
	return -1; //Not found
}

//Display array
void showArray(int arr[], int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
}


int main()
{
	int n1 = 10; //length of array 1
	int n2 = 20; //length of array 2
	int commonIndex, countCommon = 0; //count total common elements of 2 arrays
	int arr1[n1], arr2[n2];
	int commonArr[countCommon]; //array contains common elements of 2 arrays
	int i;
	
	srand((unsigned int)time(NULL));
	//Create integer array1
	for(i = 0; i < n1; i++)
	{
		arr1[i] = getRandom(0, 100);
	}
	//Create integer array2
	for(i = 0; i < n2; i++)
	{
		arr2[i] = getRandom(0, 100);
	}
	//Display unsorted array
	printf("Array 1:\n");
	showArray(arr1, n1);
	printf("\nArray 2:\n");
	showArray(arr2, n2);
	printf("\n");
	
	//Sort array ascending
	insertionSort(arr1, n1);
	insertionSort(arr2, n2);
	
	//Display sorted array
	printf("\nArray 1 sorted:\n");
	showArray(arr1, n1);
	printf("\nArray 2 sorted:\n");
	showArray(arr2, n2);
	printf("\n");
	
	
	//find common elements of 2 arrays
	if(arr1[0] > arr2[n2-1] || arr1[n1-1] < arr2[0])
		countCommon = 0;
	else
	{
		for(i = 0; i < n1; i++)
		{
			commonIndex = binarySearch(arr2, n2, arr1[i]);
			if(commonIndex != -1)
			{
				//printf("%d ", arr1[i]);
				commonArr[countCommon] = arr1[i];
				++countCommon;
			}
		}
	}
	
	//Display
	if(countCommon == 0)
		printf("\nNot found common element of 2 arrays!");
	else
	{
		printf("\nCommon elements of 2 arrays:\n");
		showArray(commonArr, countCommon);
	}
	
	return 0;
}
