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
 * https://github.com/mohamedowi/EmbeddedCoursera.git
 * Header File ProtoTypes
 *
 *
 *
 * Mohamed Amr
 * 10/02/2020
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

void sort_array(unsigned char *arr,int size);
/* sorting the array using swap method by using two for loops till every elements is sorted correctly in descending order */
#ifdef VERBOSE
void print_array(unsigned char *arr,int size);
#endif
/* looping and printing every element of the array */
void print_statistics(unsigned char *arr,int size);
/* calling median, mean, max ,min and then printing them */
char find_median(unsigned char *arr,int size);
/* the array is sorted first using sort array then we check if the array element size is odd or even using modulus, if it's odd we take middle number, if it's even we add two middle numbers then divide by 2 */
int find_mean(unsigned char *arr,int size);
/* Find mean was done by looping on the entire array and adding each value then dividing by their number */
char find_maximum(unsigned char *arr,int size);
/* A find maximum function was implemented by setting the first variable to a maximum variable and then continously searching in the array for a higher value then it becomes the new maximum and so on till looping the entire array  */
char find_minimum(unsigned char *arr,int size);
/* A find minimum function was implemented by setting the first variable to a minimum variable and then continously searching in the array for a smaller value then it becomes the new minimum and so on till looping the entire array  */
#endif /* __STATS_H__ */
