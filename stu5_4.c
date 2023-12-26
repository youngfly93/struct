#include <stdio.h>
#include <stdlib.h>
#include "0.sort_test.h"

void bubble_sort(int *arr,int l,int r){
    for(int i = r,I = l +1,cnt; i >= I; i --){
        cnt = 0;
        for(int j = l; j < i; j++){
            if(arr[j] < arr[j + 1]) continue;
            swap(arr[j],arr[j+1]);
            cnt ++;
        }
        if(cnt == 0) break;
    }
    return;
}

int main(){
    int *arr = getRandData(SMALL_DATA_N);
    TEST(bubble_sort,arr,SMALL_DATA_N);
    free(arr);
    return 0;
}

