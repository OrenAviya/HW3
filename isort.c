//
// Created by alon on 12/18/22.
//
# include <stdio.h>
#include "isort.h"

void shift_element(int* arr, int i){
    i--;
    while ( i >= 0){
        *(arr + i + 1) = *(arr + i);
        i--;
    }
}

void insertion_sort(int *arr , int len){
     int i;
     for (i = 0; i < len  ; i++ ){
        int current = *(arr+i);
        int j = 0;
          while (*(arr+j) < current && j < i){
            j++;
          }
            shift_element(arr+j, i-j);
            *(arr+j) = current;
     }

}
void print_array(int *arr, int len) {
	int i;
	for(i = 0; i<len-1; i++) {
		printf("%d,", *arr);
		arr++;
	}
    printf("%d" , *arr);
	printf("\n");
}
int main() {
	int arr[ARR_LENGTH] = {0};
    //scanning and inserting the input to the array
    int	count = 0;
    do {
        // Take input
        // and increment count
        scanf("%d",(arr + count));
        count++;
    } while ( count < ARR_LENGTH);

	//sorting the array
	insertion_sort(arr, ARR_LENGTH);

	print_array(&arr[0], ARR_LENGTH);

    return 0;

}



