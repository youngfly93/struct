#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define swap(a, b) {\
    __typeof(a) __c = a; \
    a = b; b = __c; \
}

typedef struct Node{
    char ch;
    int freq;
    struct Node *lchild,*rchild;
} Node;

Node* getNewNode(int freq,char ch){
    Node* p = (Node*)malloc(sizeof(Node));
    p->ch = ch;
    p->freq = freq;
    p->lchild = p->rchild = NULL;
    return p;
}

void clear(Node* root){
    if(root == NULL) return;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
}

typedef struct Heap{
    Node ** data, *__data;
    int size,n;
} Heap;

Heap *getNewheap(int size){
    Heap *h = (Heap*)malloc(sizeof(Heap));
    h->__data = (Node**)malloc(sizeof(Node*) * size);
    h->data = h->__data - 1;
    h->size = size;
    h->n = 0;
    return h;
}

int fullHeap(Heap *h){
    return h->n == h->size;
}

int emptyHeap(Heap *h){
    return h->n == 0;
}

Node* top(Heap* h){
    if (emptyHeap(h)) return NULL;
    return h->data[1];
}

void swap_node(Node **node_arr,int i, int j){
    Node *temp = node_arr[i];
    node_arr[i] = node_arr[j];
    node_arr[j] = temp;
    return;
}

int cmpHeap(Heap *h,int i, int j){
    return h->data[i]->freq < h->data[j] -> freq;
}

void up_maintain(Heap *h,int i){
    while(i > 1 && cmpHeap(h,i,i/2)){
        swap(h->data[i],h->data[i/2]);
        i = i /2;
    }
    return;
}

void down_maintain(Heap *h,int i){
    while(i*2 <= h->n){
        int ind = i,l = i*2,r = i*2+1;
        if(cmpHeap(h,l,ind)) ind = l;
        if(r <= h->n &&cmpHeap(h,r,ind)) ind = r;
        if(ind == i) break;
        swap(h->data[i],h->data[ind]);
        i = ind;
    }
    return;
}


int pushHeap(Heap *h, Node* n){
    if(fullHeap(h)) return 0;
    h->n += 1;
    h->data[h->n] = n;
    up_maintain(h,h->n);
    return 1;
}

int popHeap(Heap *h){
    if(emptyHeap(h)) return 0;
    h->data[1] = h->data[h->n];
    h-> n -= 1;
    down_maintain(h,1);
    return 1;
}



void clearHeap(Heap *h){
    if(h == NULL) return;
    free(h->__data);
    free(h);
    return;
}

Node *buildHaffmanTree(Node **node_arr, int n){
    Heap *h = getNewheap(n);
    for(int i = 0; i < n; i++){
        pushHeap(h,node_arr[i]);
    }
    for(int i = 1;i< n ;i++){
        Node *node1 = top(h);
        popHeap(h);
        Node *node2 = top(h);
        popHeap(h);
        Node *node3 = getNewNode(node1->freq + node2->freq,0);
        node3->lchild = node1;
        node3->rchild = node2;
        pushHeap(h,node3);
    }
    Node *ret = top(h);
    clearHeap(h);
    return ret;
}

#define MAX_CHAR_NUM 128
char *char_code[MAX_CHAR_NUM] = {0};

void extracHaffmanCode(Node * root,char buff[],int k){
    buff[k] = 0;
    if(root->lchild == NULL && root->rchild == NULL){
        char_code[root->ch] = strdup(buff);
        return;
    }
    buff[k] = '0';
    extracHaffmanCode(root->lchild,buff,k+1);
    buff[k] = '1';
    extracHaffmanCode(root->rchild,buff,k+1);
    return;
}


int main(){
    char s[10];
    int n, freq;
    scanf("%d",&n);
    Node **node_arr = (Node**)malloc(sizeof(Node*)*n);
    for(int i = 0; i < n; i++){
        scanf("%s%d",s,&freq);
        node_arr[i] = getNewNode(freq,s[0]);
    }
    Node *root = buildHaffmanTree(node_arr,n);
    char buff[100];
    extracHaffmanCode(root,buff,0);
    for(int i = 0;i < MAX_CHAR_NUM;i++){
        if(char_code[i] == NULL) continue;
        printf("%c : %s\n", i , char_code[i]);
    }
    free(node_arr);
    clear(root);
    return 0;
}