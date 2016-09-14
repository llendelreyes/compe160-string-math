//
//  main.c
//  Pointer Lab
//
//  Created by Llendel Reyes on 3/15/16.
//  Copyright © 2016 Llendel Reyes. All rights reserved.
//

#include <stdio.h>
#define arraysize 9

int sum(int array[],int asize){
    int sumarray = 0;
    for (int i = 0; i < asize; i++)
        sumarray += array[i];
    return sumarray;
}

int swap(int *pA,int *pB){
    if (*pA > *pB){
        int tempV = *pA;
        *pA = *pB;
        *pB = tempV;
        
        return 1;
    }
    return 0;
}

int sort_1pass(int array[],int asize){
    int t = 0;
    for (int i = 0; i < asize-1; i++){
        if (array[i] > array[i+1]){
            swap(&array[i],&array[i+1]);
            t = 1;
        }
    }
    return t;
}

void sort(int array[],int asize){
    while (1){
        int res = sort_1pass(array,asize);
        if (res == 0){
            return;
        }
    }
}

void printarray(int array[],int asize){
    for (int i = 0; i < asize; i++)
        printf("%d ", array[i]);
    printf("\n");
}

void main(void) {
    int array[arraysize] = {8,1,8,2,2,9,5,6,2};
    printf("%s ", "Original Array : ");
    printarray(array,arraysize);
    printf("Sum of entire Array : %d\n", sum(array,arraysize));
    sort(array,arraysize);
    printf("%s ", "Sorted Array : ");
    printarray(array,arraysize);
    printf("%s %d \n", "Median of sorted array : ",array[arraysize / 2]);
    printf("%s %.2f \n", "Average of array : ",sum(array,arraysize) / (arraysize + 0.0));
    
}
