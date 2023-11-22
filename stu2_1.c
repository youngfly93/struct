#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct vector{
    int* data;
    int size;
} vector;

vector *initVector(int n){
    vector* v  = (vector*)malloc(sizeof(vector));
    v->size = n;
    v->data = (int *)malloc(sizeof(int) * n);
    return v;
}

int insertVector(vector* v,int pos,int val){
    if(pos < 0||pos >  v->size) return 0;
    v->data[pos] = val;
    return 1;
}

int  VectorSeek(vector* v,int pos){
    if(pos < 0||pos >  v->size) return -1;
    return v->data[pos];
}

void clearVector(vector* v){
    if(v==NULL) return;
    free(v->data);
    free(v);
    return;
}

typedef struct Queue{
    vector* data;
    int size,count,head,tail;
} Queue;

Queue *initQueue(int n){
    Queue* q  = (Queue *)malloc(sizeof(Queue));
    q->data = initVector(n);
    q->size = n;
    q->count=q->head=q->tail=0;
    return q;
}

int empty(Queue* q){
    return q->count == 0;
}

int front(Queue* q){
    return VectorSeek(q->data,q->head);
}

int push(Queue* q,int val){
    if(q->count == q->size) return 0;
    insertVector(q->data,q->tail,val);
    q->tail+=1;
    if(q->tail == q->size) q->tail = 0;
    q->count+=1;
    return 1;
}

int pop(Queue* q){
    if(empty(q)) return 0;
    q->tail+=1;
    if(q->head==q->size) q->head = 0;
    q->count-=1;
    return 1;
}

void outputQueue(Queue* q){
    printf("Queue : ");
    for(int i = 0;i<q->count;i++){
        printf("%4d",VectorSeek(q->data, (q->head + i) % q->size));
    }
    printf("\n\n");
    return;
}

void clearQueue(Queue* q){
    if (q == NULL) return ;
    clearVector(q->data);
    free(q);
}

int main(){
    srand(time(0));
    #define MAX_OP 10
    Queue* q = initQueue(5);
    for(int i = 0;i<MAX_OP;i++){
        int op = rand() % 5, val = rand() % 100;
        switch(op){
            case 0:
            case 1:
                printf("front of queue : %d\n", front(q));
                pop(q);
                break;    
            case 2:
            case 3:
            case 4:
                printf("push of queue : %d\n", val);
                push(q,val);
                break;
        }
        outputQueue(q);
    }
    clearQueue(q);
    return 0;
}
