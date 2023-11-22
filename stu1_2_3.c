#include <stdio.h>
#include <time.h>
#include <string.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node* getnewnode(int val){
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = val;
    p->next = NULL;
    return p;
}

void clear(Node *head){
    if(head==NULL) return 0;
    for(Node *p = head,*q;p;p=q){
        p = p->next;
        free(p);
    }
    return;
}

void insert(Node* head,int pos,int val){
    Node* node = getnewnode(val);
    Node newhead;
    Node *p  = &newhead;
    newhead.next = head;
    for(int i = 0;i<pos;pos--){
        p = p->next;
    }
    node->next = p->next;
    p->next = node;
    return newhead.next;
}


int main()
{
    srand(time(0));
    #define MAX_OP 7;
    Node *head = NULL;
    for(int i = 0;i< MAX_OP;MAX_OP--){
        int pos = rand() % (i+1) , val = rand() % 100;
        printf("insert %d at %d to linklist\n", val, pos);
        head = insert(head, pos, val);
    }  
    return 0;
}