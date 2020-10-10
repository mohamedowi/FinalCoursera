/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material.
 *
 *****************************************************************************/
/**
 * stats.c
 * This C file contains 7 functions to be implemnted. The max,min,sort,find median,find_mean, print_array and print_statistics.
 * In Addition a helper swap method is implemented to be used for sorting the array. The implementation description is written in the header file.
 *
 *
 *
 * Mohamed Amr
 * 02/10/2020
 * https://github.com/mohamedowi/EmbeddedCoursera.git
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)
void sort_array(unsigned char *arr,int size){
for(int j=0;j<size;j++){
    int counter = 0;
    for(int i=0;i<size;i++){
    if(arr[i+1] != NULL && arr[i]<arr[i+1]){
    sp(&arr[i],&arr[i+1]);
    counter++;
    }
    }
    if (counter == 0){
    printf("Finished Sorting\n");
    break;
    }
    }
}
#ifdef VERBOSE
void print_array(unsigned char *arr,int size){
for(int i = 0; i<size; i++){
printf("The array elements are: %d \n", arr[i]);
}
}
#endif
char find_median(unsigned char *arr,int size){
char median = 0;
int x = size;
sort_array(arr,size);
if ( (x%2) == 0){
median = (arr[(size/2)] + arr[(size/2)+1])/2;
}
else{
median = arr[(size/2)-1];
}
return median;
}
int find_mean(unsigned char *arr,int size){
int sum = 0;
int mean = 0;
for( int i =0; i<size ; i++){
 sum += arr[i];
}
mean = sum/size ;
return mean;
}
char find_maximum(unsigned char *arr,int size){
unsigned char max = arr[0];
for( int i =0; i <size;i++){
if( arr[i] > max){
max = arr[i];
}
}
return max;
}
char find_minimum(unsigned char *arr,int size){
unsigned char min = arr[0];
for( int i =0; i <size;i++){
if( arr[i] != NULL && arr[i] < min){
min = arr[i];
}
}
return min;
}
void sp(unsigned char *ptr1,unsigned char *ptr2){
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;

}
void print_statistics(unsigned char *arr,int size){
unsigned char median = find_median(arr,size);
printf("Median is : %d \n", median);
unsigned char mean = find_mean(arr,size);
printf("Mean is : %d \n", mean);
unsigned char max = find_maximum(arr,size);
printf("Maximum is : %d \n", max);
unsigned char min = find_minimum(arr,size);
printf("Miminum is : %d \n", min);
}
int main()
{   unsigned char test[40] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};
  int size = 40;
    #ifdef VERBOSE
      printf("Array Before Sorting\")
      print_array(test,size);

    #endif
      print_statistics(test,size);

      sort_array(test,size);

    #ifdef VERBOSE
      printf("Array After Sorting\")

      print_array(test,size);

    #endif

}
/* Add other Implementation File Code Here */
