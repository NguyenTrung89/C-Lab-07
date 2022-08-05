//Sap xep 1 mang so nguyen tu vi tri j-k (gia su j-k nam trong khoang 0 - chieu dai mang).
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <time.h>

//Generate a random number
int getRandom(int min, int max)
{
    return min + (int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
}

//Input number in range (min, max)
int getNumber(int min, int max)
{
	int number;
	while(1)
	{
		printf("Enter a number in range (%d, %d): ", min, max);
		scanf("%d", &number);
		if(number >= min && number <= max)
			break;
		else
			printf("Wrong input, please re-enter!\n");
	}
	return number;
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
	int n = 30; //length of array
	int intArr[n];
	int i, j, k;
	
	//Create integer array
	srand((unsigned int)time(NULL));
	for(i = 0; i < n; i++)
	{
		intArr[i] = getRandom(0, 100);
	}
	
	//Enter j, k in range (0-n), 0 <= j < k <= n-1
	j = getNumber(0, n-2);
	k = getNumber(j+1, n-1);
	
	//Display unsorted array
	printf("Unsorted array:\n");
	showArray(intArr, n);
	
	//Sort array ascending from position j - k
	int pos, x;
	for(i = j+1; i <= k; i++)
	{
		x = intArr[i];
		pos = i;
		while(pos > j && x < intArr[pos-1])
		{
			intArr[pos] = intArr[pos-1];
			pos--;
		}
		intArr[pos] = x;
	}
	
	//Display sorted array
	printf("\nSorted array from position (%d, %d):\n", j, k);
	showArray(intArr, n);
	
	return 0;
}
