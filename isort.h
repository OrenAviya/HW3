//
// Created by alon on 12/18/22.
//

#ifndef HW3_ISORT_H
#define HW3_ISORT_H
#define ARR_LENGTH 50
/*
*this function gets :
* 1.pointer to a place in array 
* 2.number 
* the function will move each of the i next organs
* one place to the right.  
*if i=0 just switch arr[i+1] , arr[i] 
*
*/
void shift_element(int* arr, int i);

/*
*this function gets:
* array size [len]
* the function will sort the array from small to big.
*
*/
void insertion_sort(int* arr , int len);

/*
* function to print the array that the pointer is point on
*/
void print_array(int *data, int n);

#endif //HW3_ISORT_H
