#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct vector {
    int size,count;
    int *data;
} vector;


//初始化
vector *getNewVector(int n){
    vector *p = (vector *)malloc(sizeof(vector));
    p->size = n;
    p->count = 0;
    p->data = (int *)malloc(sizeof(int) *n);
    return p;
}

int insert(vector *v,int pos,int val){
    if (pos <0||pos >=v->count) return 0;
    if(v->size == v->count) return 0;
    for(int i = v->count;i>=pos;i--){
        v->data[i+1] = v->data[i];
    }
    v->data[pos] = val;
    v->count += 1;
    return 1;
}

int arase(vector *v,int pos){
    if(pos <0||pos >= v->count) return 0;
    for(int i = pos+1;i<v->count;i++){
        v->data[i-1] = v->data[i];
    }
    v->count-=1;
    return 1;
}

void output_vector(vector *v){
    int len = 0;
    for (int i = 0;i< v->size;i++){
        len += printf("%3d",i);
    }
    printf("\n");
    for(int i = 0;i<v->count;i++){
        printf("%3d",v->data[i]);
    }
    printf("\n\n");
}

void clear(vector *v){
    if(v == NULL) return;
    free(v->data);
    free(v);
    return;
}

int main(){
    srand(time(0));
    #define MAX_OP 20
    vector *v = getNewVector(MAX_OP);
    for(int i = 0;i<MAX_OP;i++){
        int op = rand() % 4,pos,val;
        switch (op){
            case 0:
            case 1:
            case 2:
                pos = rand() % (v->count +2);
                val = rand() % 100;
                printf("insert %d to  %d vector = %d\n",val,pos,insert(v,pos,val));
                break;
            case 3:
                pos = rand() % (v->count +2);
                printf("erase item at %d in vector = %d\n",pos,arase(v,pos));
                break;
        }
        output_vector(v);
    }
    return 0;
}