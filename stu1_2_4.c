#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DL 3
#define STR(n) #n
#define DIGIT_LEN_STR(n) "%" STR(n) "d"


typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* getnewnode(int val){
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->next = NULL;
    return p;
}

void clear(Node* head){
    if(head == NULL) return;
    for(Node* p = head,*q;p;p=q){
        q = p->next;
        free(p);
    }
    return;
}

Node* insert(Node* head,int pos,int val){
    Node newhead;
    Node *p = &newhead;
    newhead.next = head;
    for(int i = 0;i<pos;i++){
        p = p->next;
    }
    Node* newnode = getnewnode(val);
    newnode->next = p->next;
    p->next = newnode;
    return newhead.next;
}

void output_linklist(Node *head) {
    int flag = 0;
    int n = 0;
    for (Node *p = head; p; p = p->next) n += 1;
    for (int i = 0; i < n; i++) {
        printf(DIGIT_LEN_STR(DL), i);
        printf("  ");
    }
    printf("\n");
    for (Node *p = head; p; p = p->next) {
        printf(DIGIT_LEN_STR(DL), p->data);
        printf("->");
    }
    printf("\n");
    if (flag == 0) printf("\n\n");
    return ;
}

int main(){
    srand(time(0));
    #define MAX_OP  7;
    Node* head = NULL;
    for(int i = 0;i < 7; i++){
        int pos = rand() % (i+1);
        int val = rand() % 100;
        head = insert(head,pos,val);
    }
    output_linklist(head);
    clear(head);
    return 0;
}