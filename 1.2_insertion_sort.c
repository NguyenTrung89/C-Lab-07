//Dung insertion sort de sap xep 1 mang ký tu theo chieu tang dan.
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <time.h>

//Generate random a character
char getRandom(char min, char max)
{
    return min + (char)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
}

//Insertion Sort
void insertionSort(char arr[], int n)
{
	int i, pos, x;
	for(i = 1; i < n; i++)
	{
		x = arr[i];
		pos = i;
		while(pos > 0 && x < arr[pos-1])
		{
			arr[pos] = arr[pos-1]; //translocate
			pos--;
		}
		arr[pos] = x;
	}
	
}

//Display array
void showArray(char a[], int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		printf("%c ", a[i]);
	}
}

int main()
{
	int n = 20; //number elements of the array
	char charArr[n];
	int i;
	
	//Create array characters
	srand((char)time(NULL));
	for(i = 0; i < n; i++)
	{
		charArr[i] = getRandom('a', 'z');
	}
	
	//Display unsorted array
	printf("Unsorted array:\n");
	showArray(charArr, n);
	
	//Sort array
	insertionSort(charArr, n);
	
	//Display sorted array
	printf("\nSorted array:\n");
	showArray(charArr, n);
	
	return 0;
}

