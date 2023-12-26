#include <stdio.h>
#include <stdlib.h>
#include "0.sort_test.h"
#define swap(a, b) { \
    __typeof(a) __c = a; \
    a = b, b = __c; \
}

void quick_sort(int *arr, int l, int r){
    if(r - l <=2){
        if(r - l <=1) return;
        if(arr[l] > arr[l + 1]) swap(arr[l],arr[l+1]);
        return;
    }
    int x = l,y=r -1, z = arr[l];
    while(x < y){
        while(x < y && arr[y] >= z) y--;
        if(x < y) arr[x++] = arr[y];
        while(x < y && arr[x] <= z) x++;
        if(x < y) arr[y--] = arr[x];
    }
    arr[x] = z;
    quick_sort(arr,l,x);
    quick_sort(arr,x+1,r);
    return;
}


void quick_sort_v1(int *arr, int l, int r){
    if(r - l <=2){
        if(r - l <=1) return;
        if(arr[l] > arr[l+1]) swap(arr[l],arr[l+1]);
        return;
    }
    int x = l,y=r-1,z = arr[l];
    do{
        while(arr[y] >=z) y--;
        while(arr[x] <=z) x++;
        if(x < y) swap(arr[x],arr[y]); 
    } while(x < y);
    quick_sort_v1(arr,l,y+1);
    quick_sort_v1(arr,y+1,r);
    return;
}

inline int three_point_select(int a,int b ,int c){
    if(a > b) swap(a,b);
    if(a > c) swap(a,c);
    if(b > c) swap(b,c);
    return b;
}
void quick_sort_v2(int *arr, int l, int r){
    if (r-l <=2){
        if(r-l <=1) return;
        if(arr[l] > arr[l+1]) swap(arr[l],arr[l+1]);
        return;
    }
    int x =l, y = r-1;
    int z = three_point_select(
        arr[l],
        arr[r-1],
        arr[(l+r)/2]
    );
    do {
        while(arr[x] < z) x++;
        while(arr[y] > z) y--;
        if(x <=y) {
            swap(arr[x],arr[y]);
            ++x,--y;
        }
    }while(x <= y);
    quick_sort_v2(arr,l,y+1);
    quick_sort_v2(arr,x,r);
    return;
}

void quick_sort_v3(int *arr,int l, int r){
    if(r-l <= 2){
        if(r-l <=1) return;
        if(arr[l] > arr[l+1]) swap(arr[l],arr[l+1]);
        return;
    }
    while(r >l){
        int x = l, y = r -1;
        int z = three_point_select(
            arr[l],
            arr[r-1],
            arr[(l+r)/2]
        );
        do{
            while(arr[x] < z) ++x;
            while(arr[y] > z) --y;
            if(x <=y){
                swap(arr[x],arr[y]);
                ++x,--y;
            }
        }while(x <=y);
        quick_sort_v3(arr,l,y+1);
        l = x;
    }
    return;
}

#define threshold 16

void __quick_sort_v4(int *arr,int l, int r){
    while(r - l > threshold){
        int x = l , y = r -1;
        int z = three_point_select(
            arr[l],
            arr[r-1],
            arr[(l+r)/2]
        );
        do{
            while(arr[x] < z) ++x;
            while(arr[y] > z) --y;
            if(x <= y){
                swap(arr[x],arr[y]);
                ++x,--y;
            }
        }while(x <=y);
        __quick_sort_v4(arr,l,y+1);
        l = x;
    }
    return;
}

void quick_sort_v4(int *arr,int l, int r){
    __quick_sort_v4(arr,l,r);
    unguarded_insert_sort(arr, l, r);
    return;
}

int main() {
    int *arr_s = getRandData(SMALL_DATA_N);
    int *arr_b = getRandData(BIG_DATA_N);
    TEST(quick_sort, arr_s, SMALL_DATA_N);
    TEST(quick_sort, arr_b, BIG_DATA_N);
    TEST(quick_sort_v1, arr_b, BIG_DATA_N);
    TEST(quick_sort_v2, arr_b, BIG_DATA_N);
    TEST(quick_sort_v3, arr_b, BIG_DATA_N);
    TEST(quick_sort_v4, arr_b, BIG_DATA_N);
    free(arr_s);
    free(arr_b);
    return 0;
}