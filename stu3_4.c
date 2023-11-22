/*************************************************************************
	> File Name: 3.serialize_deserialize.cpp
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char ch;
    int freq;
    struct Node* lchild, *rchild;
} Node;

Node* getNewNode(char ch, int freq){
    Node* p = malloc(sizeof(Node));
    p->ch = ch;
    p->freq = freq;
    p->lchild = p->rchild = NULL;
    return p;
}

void swap_node(Node **anno_arr,int i,int j){
    Node* tmp = anno_arr[i];
    anno_arr[i] = anno_arr[j];
    anno_arr[j] = tmp;
    return;
}

int find_min_node(Node **anno_arr,int n){
    int ind = 0;
    for(int j =0;j < n ;j++){
        if(anno_arr[j]->freq < anno_arr[ind]->freq) ind = j;
    }
    return ind;
}

Node *buildHaffmanTree(Node **node_arr,int n){
    for(int i = 0;i < n;i++){
        int ind1 = find_min_node(node_arr,n-i);
        swap_node(node_arr, ind1 ,n-i);
        int ind2 = find_min_node(node_arr,n-i -1);
        swap_node(node_arr, ind2 ,n-i-1);
        int freq = node_arr[n-i-1]->freq + node_arr[n-i]->freq;
        Node* node = getNewNode(0,freq);
        node->lchild = node_arr[n-i-1];
        node->rchild = node_arr[n-i];
        node_arr[n-i-1] = node;
    }
    return node_arr[0];

}

 void clear(Node* root){
    if(root == NULL) return;
    if(root->lchild) clear(root->lchild);
    if(root->rchild) clear(root->rchild);
    free(root);
    return;
}

#define MAX_CHAR_NUM 128
char *char_code[MAX_CHAR_NUM] = {0};

void extractHaffmanCode(Node *root,char buff[],int k){
    buff[k] = 0;
    if(root->lchild == NULL && root->rchild == NULL){
        char_code[root->ch] = strdup(buff);
        return;
    }
    buff[k] = '0';
    extractHaffmanCode(root->lchild,buff,k+1);
    buff[k] = '1';
    extractHaffmanCode(root->rchild,buff,k+1);
    return;
}

int main(){
    char s[10];
    int n ,freq;
    scanf("%d",&n);
    Node **node_arr = (Node **)malloc(sizeof(Node*) * n);
    for (int i = 0;i < n; i++){
        scanf("%s%d" , s, &freq);
        node_arr[i] = getNewNode(s[0],freq);
    }
    Node *root = buildHaffmanTree(node_arr,n);
    char buff[1000];
    extractHaffmanCode(root,buff,0);
    for (int i = 0; i < MAX_CHAR_NUM; i++) {
        if (char_code[i] == NULL) continue;
        printf("%c : %s\n", i, char_code[i]);
    }
    clear(root);
    return 0;
}