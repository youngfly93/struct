#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "0.sort_test.h"

void insert_sort(int* arr,int l, int r){
    for(int i = l + 1; i < r;i++){
        int j = i;
        while(j > l && arr[j] < arr[j-1]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
    return;
}


void unguarded_insert_sort(int *arr,int l,int r){
    int ind = l;
    for(int i = l + 1; i < r; i++){
        if(arr[i] < arr[ind]){
            ind = i;
        }
    }
    while(ind > l){
        swap(arr[ind],arr[ind-1]);
        ind--;
    }
    for(int i = l + 1; i < r;i++){
        int j = i;
        while(j > l && arr[j] < arr[j-1]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
    for(int i = l + 1; i < r;i++){
        int j = i;
        while(arr[j] < arr[j-1]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
    return;
}



int main(){
    int* arr = getRandData(SMALL_DATA_N);
    TEST(insert_sort,arr,SMALL_DATA_N);
    TEST(unguarded_insert_sort, arr, SMALL_DATA_N);
    free(arr);
    return 0;
}