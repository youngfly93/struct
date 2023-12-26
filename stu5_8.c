/*************************************************************************
	> File Name: 8.sort.cpp
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include "0.sort_test.h"
using namespace std;

void output(int *arr, int n, const char *s = "arr");
template<typename T>
void output(vector<T> &arr);

template<typename T>
void output(vector<T> &arr){
    printf("arr[%lu]= ",arr.size());
    for(int i = 0;i < arr.size();i++){
        cout << arr[i] << " ";
    }
    printf("\n");
    return;
}

void output(int *arr, int n, const char *s){
    printf("%s[%d] = ", s, n);
    for(int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return;
}

void test() {
    printf("\ntest array: \n");
    int arr* = getRandData(10);
    output(arr,10);
    sort(arr,arr+10);
    output(arr,10);
    sort(arr,arr+10, greater<int>());
    output(arr,10);
    free(arr);
    return;
}

void test2(){
    printf("\ntest vector: \n");
    vector <int> arr;
    for(int i = 0; i < 10; i++) arr.push_back(rand() % 100);
    output(arr);
    sort(arr.begin(),arr.end());
    output(arr);
    sort(arr.begin(),arr.end(),greater<int>());
    output(arr);
    return;
}


struct Data{
    int x,y;
}

ostream &operator<<(ostream &out, const Data &d) {
    out << "(" << d.x << ", " << d.y << ")";
    return out;
}

bool cmp(const Data &a, const Data &b){
    if(a.x != b.x) return a.x < b.x;
    return a.y > b.y;
}

void test3(){
    printf("\n test my data structure: \n");
    vector <Data> arr;
    for(int i = 0; i< 10; i++){
        Data d;
        d.x = rand() % 100;
        d.y = rand() % 100;
        arr.push_back(d);
    }
    output(arr);
    sort(arr.begin(),arr.end(),cmp);
    output(arr);
    return;
}

void test4(){
    printf("\ntest sort ind : \n");
    int *arr = getRandData(10);
    int *ind = getRandData(10);
    for(int i =0;i < 10; i++) ind[i] = i;
    output(arr,10);
    sort(ind,ind + 10,[&](int a , int b){
        return arr[a] < arr[b];
    });
    output(arr,10);
    output(ind,10,"ind");
    return;
}

