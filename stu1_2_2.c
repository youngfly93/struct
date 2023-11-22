#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef stuct Node {
    int data;
    struct Node *next;
} Node;

Node* getnewnode(int val){
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = val;
    p->next = NULL;
    return p;
}

void clear(Node* head){
    if(head == NULL) return;
    for(Node * p = head , *q; p ;p = q){
        q = p->next;
        free(p);
    }
    return;
}

Node *insert(Node *head, int pos, int val){
    Node new_head, *p = &new_head, *node = getNewNode(val);
    new_head.next = head;
    for (int i = 0; i < pos; i++) p = p->next;
    node->next = p->next;
    p->next = node;
    return new_head.next;
}

int main() {
    srand(time(0));
    #define MAX_OP 7
    Node *head = NULL;
    for (int i = 0; i < MAX_OP; i++) {
        int pos = rand() % (i + 1), val = rand() % 100;
        printf("insert %d at %d to linklist\n", val, pos);
        head = insert(head, pos, val);
        output_linklist(head);
    }
    int val;
    while (~scanf("%d", &val)) {
        if (!find(head, val)) {
            printf("not found\n");
        }
    }
    clear(head);
    return 0;
}