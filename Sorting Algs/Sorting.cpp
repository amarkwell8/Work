#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;
// Function Prototypes

int *createArray(int n);
int selectionSort(int *&list, int n);
int bubbleSort(int *&list, int n);
int linearSearch(int *list, int n);
int binarySearch(int *list, int n);

int *createArray(int n) 
{
	// IN:
	// OUT:
	int *unsortedArray;
	unsortedArray = new int[n];
	for(int i = 0; i < n; i++)
	{
		unsortedArray[i] = rand();
	}
	return(unsortedArray);
}

int selectionSort (int *&list, int n)
{
	int numOperations = 0, temp = 0;
	for(int x = 0; x < n; x++)
	{
		numOperations++;
		for(int y = x+1; y < n; y++)
		{
			numOperations++;
			if(list[y]<list[x])
			{
				temp = list[x];
				list[x] = list[y];
				list [y] = temp;
				numOperations++;
				
			}//End if
		}//End nested for
	}//End for
	return (numOperations);
}//End selectionSort

int bubbleSort (int *&list, int n)
{
	int numOperations = 0, temp = 0;
	for (int x = 0; x < n; x++)
	{
		numOperations++;
		
		for(int y = 0; y < n-1; y++)
		{
			numOperations++;
			
			if(list[y] > list[y+1])
			{
				temp = list[y];
				list[y] = list[y+1];
				list[y+1] = temp;
				numOperations++;
				
			}//End if
		}//End nested for
	}//End for
	return (numOperations);
}//End bubbleSort

int linearSearch(int *list, int n)
{
	//start with first array position and go all the way through
	int numOperations = 0;
	int aveOperations = 0, j;
	for(int i = 0; i < n; i++)
	{
		
		
		for(j = 0; j < n; j++) 
		{
			numOperations++;
			if(i== list[j])
			{
				break;
			}//End if
			
		}//End nested for
	}//End for
	aveOperations = numOperations/n;
	return (aveOperations);
}

int binarySearch(int *list, int n)
{
	int numOperations = 0, aveOperations = 0, i;

	for(i = 0; i < n; i++)
	{
		int left = 0, right = n;
		while(left <= right)
		{
			int middle = (left + right)/2;
			
			if(i == list[middle])
			{
				numOperations++;
				break;
			}
			else if(i > list[middle])
			{
				left= middle + 1;
				numOperations++;
			}
			else
			{
				right = middle - 1;
				numOperations++;
			}
			
		}//End while
	}//End for
	aveOperations = numOperations/n;
	return (aveOperations);
}//End binarySearch

int main(void) 
{
	// Determine the maximum random number on the system
	cout << "MAXIMUM RANDOM NUMBER: " << RAND_MAX << endl << endl;
	
	srand(time(NULL));
	 
	int n;
	// Print the header for the output
	cout << "\tSELECT\tBUBBLE\t\t\tLINEAR\tBINARY\n";
	cout << "n\tSORT\tSORT\t\t\tSEARCH\tSEARCH\n";
	cout << "==============================================\n";
	for(n = 10; n <= 10000; n*= 10) 
	{
		// Arrays for unsorted and sorted values
		int *unsortedArray;
		int *selectionSortArray;
		int *bubbleSortArray;
		
		//Variables to store number of opeartions
		int selectionSort_n;
		int bubbleSort_n;
		int linearSearch_n;
		int binarySearch_n;
		
		// create a random array of n elements
		unsortedArray = createArray(n);
		
		// create space for each of the sorted arrays
		selectionSortArray = new int[n];
		bubbleSortArray = new int[n];
		// Initialize sorted arrays to unsorted list
		for(int i = 0; i < n; i++) 
		{
			selectionSortArray[i] = unsortedArray[i];
			bubbleSortArray[i] = unsortedArray[i];
		};
		
		// Sort arrays ]] returns the number of operations as the
		// function return value, the sorte array as pass by reference array
		selectionSort_n = selectionSort(selectionSortArray, n);
		bubbleSort_n = bubbleSort(bubbleSortArray, n);
		
		linearSearch_n = linearSearch(selectionSortArray, n);
		binarySearch_n = binarySearch(selectionSortArray, n);
		
		cout << n << "\t" << selectionSort_n << "\t" << bubbleSort_n <<  "\t\t\t" << linearSearch_n << "\t" << binarySearch_n << endl;
		
		// NOW PRINT OUT FIRST FEW SORTED VALUES WHEN N = 10000
		if(n == 10000) 
		{
			cout << endl << endl;
			cout << "UNSORTED\tSELECT\tBUBBLE\n";
			cout << "------------------------------------------------\n";
			for(int j = 0; j < 100; j++) {
			cout << unsortedArray[j] << "\t\t" << selectionSortArray[j] << "\t\t" << bubbleSortArray[j] << "\t" << endl;
			}
		}
	}
}//End Main
