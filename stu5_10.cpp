class Solution{
public:
    ListNode* sortList(ListNode* head){
        if(head == NULL) return head;
        ListNode* p = head, *h1 = NULL,*h2 = NULL, *q;
        int l = head->val, r = head->val,z;
        while(p) min(p->val,l),max(p->val,r),p = p->next; 
        z = (l + r) >> 1;
        if (l == r) return head;
        p = head;
        while(p){
            q = p->next;
            if(p->val <= z){
                p->next = h1;
                h1 = p;
            } else{
                p->next = h2;
                h2 = p;
            }
            p = q;
        }
        h1 = sortList(h1);
        h2 = sortList(h2);
        p = h1;
        while(p->next) p = p->next;
        p->next = h2;
        return h1;
    }
};