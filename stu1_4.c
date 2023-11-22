
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL) return;
        ListNode *p = head->next;
        ListNode *q = head->next;
        while(q&&q->next){
            p = p->next;
            q = q->next->next;
            if(p==q){
                return true;
            }
        }
        return false;
    }
};