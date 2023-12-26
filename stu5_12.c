class Solution{
public:
    ListNode* mergeTwoLists(ListNode* list1,ListNode* list2){
        ListNode ret, *p = &ret;
        while(list1 || list2){
            if(list2 ==NULL || (list1 && list1->val <= list2->val)){
                p->next = list1;
                list1 = list1->next;
                p = p->next;
            }else{
                p->next = list2;
                list2 = list2->next;
                p = p->next;
            }
        }
        return ret.next;
    }
};