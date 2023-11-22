class Solution{
public:
    int getLength(ListNode* head){
        ListNode* p = head;
        int i = 0;
        while(p){
            p = p->next;
            i++;
        }
        return i;
    }
    ListNode* rotateRight(ListNode* head,int k){
        if(!head) return head;
        int n = getLength(head);
        k %= n;
        if(k==0||n==1) return head;
        ListNode* p = head;
        ListNode* q = head;
        for(int i = 0;i<k;i++) p=p->next;
        while(p->next){
            p = p->next;
            q = q->next;
        }
        ListNode* newHead = q->next;
        q->next = NULL;
        p->next = head;
        return newHead;
    }
};