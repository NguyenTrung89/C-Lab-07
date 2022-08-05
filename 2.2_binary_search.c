//Dung binary search de tim kiem vi tri xuat hien cua ky tu trong chuoi
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <time.h>

//Generate a random character
char getRandom(char min, char max)
{
    return min + (char)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
}

//Sort array ascending
void insertionSort(char arr[], int n)
{
	int i, pos;
	char x;
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

//Binary search a character
int binarySearch(char arr[], int n, char x)
{
	int right = n - 1; //last element index
	int left = 0; //first element index
	while(right >= left)
	{
		int mid = left + (right - left) / 2; //mid = (right+left)/2
		if(arr[mid] == x)
			return mid;
		//if arr[mid] < x then search in the second half array
		if(arr[mid] < x)
			left = mid + 1; //first element index of second half array
		//if arr[mid] > x then search in the first half array	
		if(arr[mid] > x)
			right = mid - 1; //last element index of first half array
	}
	//if Not found
	return -1; 
}

//Display array
void showArray(char arr[], int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		printf("%c ", arr[i]);
	}
}


int main()
{
	int i, indexFound, n = 20;
	char charArr[n], ch;
	
	//Create array characters
	srand((char)time(NULL));
	for(i = 0; i < n; i++)
	{
		charArr[i] = getRandom('a', 'z');
	}
	
	//Display unsorted array
	printf("Unsorted array:\n");
	showArray(charArr , n);
	
	//Sort array ascending
	insertionSort(charArr, n);
	
	//Display sorted array
	printf("\nSorted array:\n");
	showArray(charArr , n);
	
	//Entered character for searching
	printf("\n\nEntered character for searching: ");
	scanf("%c", &ch);
	
	//Binary search
	indexFound = binarySearch(charArr, n, ch);
	
	//Display result
	if(indexFound == -1)
		printf("Character %c not found!", ch);
	else
		printf("Character %c found at position %d", ch, indexFound);
	
	return 0;
}
