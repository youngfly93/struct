/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return nullptr;
        ListNode newhead;
        newhead.next = head;
        ListNode* p = &newhead;
        ListNode* q = &newhead;
        for(int i =0;i<=n;i++){
            if(!p) return nullptr;
            p = p->next;
        }
        while(p){
            q=q->next;
            p=p->next;
        }
        q->next = q->next->next;
        return newhead.next; 
    }
};