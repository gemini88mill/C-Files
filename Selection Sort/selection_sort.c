/*	Selection Sort
	By raphael Miller
		
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char argv[]){
	/*	function collects an unsorted array, then proceeds to sort the array in-line*/
	int unsorted_array[] = {2, 5, 7, 23, 4, 11};
	
	int i, j = 0, k;
	int n = sizeof(unsorted_array) / sizeof(int);
	
	printf("unsorted: \t");
	for(i = 0; i < n; i++){
		printf(" %i", unsorted_array[i]);
	}
	
	printf("\n");
	
	for(i = 0; i < n - 1; i++){
		//current min a[0]
		
		for(j = i + 1; j < n; j++)
		
			if(unsorted_array[j] < unsorted_array[i]){
				int temp;
				temp = unsorted_array[i];
				unsorted_array[i] = unsorted_array[j];
				unsorted_array[j] = temp;
			}
	
	}
	
	
	printf("sorted: \t");
	for(i = 0; i < n; i++){
		printf(" %i", unsorted_array[i]);
	}
	printf("\n");
	
	return 0;
}


