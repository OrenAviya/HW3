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
        int scan = 0;
        scanf("%d",(arr + count));
        count++;
    } while ( count < ARR_LENGTH);



    //int arr[50] = {0,2,41,52,74,64,984,19,21,14,409,50,91,7444,67,7232,5322,6,24,7,6,5,2,90,49,9,8,5232313,89,9,8,4,5,6,7,60,2,1,20,1234,5,6,9,8,6,477,12,2,13,124};
	//sorting the array
	insertion_sort(arr, ARR_LENGTH);

	print_array(&arr[0], ARR_LENGTH);
   
    return 1;

}



