struct Node {
    int data;
    Node *next;
};

class MyCircularQueue {
public:
    int size,count;
    Node* head, *tail;
    MyCircularQueue(int k){
        head = new Node();
        tail = head;
        for(int i = 0;i < k;i++){
            tail->next = new Node();
            tail = tail->next;
        }
        tail->next = head;
        size = k;
        count = 0;
        return;
    }
    bool enQueue(int val){
        if(isFull()) return false;
        tail = tail->next;
        tail->data = val;
        count+= 1 ;
        return true; 
    }
    
    bool deQueue(){
        if(isEmpty()) return false;
        head = head->next;
        count -= 1;
        return true; 
    }

    int Front(){
        if(isEmpty()) return -1;
        return head->data;
    }
    int Rear(){
        if(isEmpty()) return -1;
        return tail->data;
    }
    bool isFull(){
        return count == size;
    }
    bool isEmpty(){
        return count == 0;
    }
};