class Solution{
public:
    ListNode* mergeKLists(vector <ListNode*> &lists){
        typedef pair<int, int> PII;
        set <PII> s;
        int n = lists.size();
        for(int i = 0;i < n;i++){
            if(lists[i] == nullptr) continue;
            s.insert(PII(lists[i]->val,i));
        }
        ListNode new_head, *p = &new_head, *q;
        while(s.size()){
            PII a = *s.begin();
            s.erase(s.begin());
            q = lists[a.second];
            lists[a.second] = lists[a.second]->next;
            p->next = q;
            q->next = nullptr;
            p = q;
            if(lists[a.second] != nullptr){
                s.insert(PII(lists[a.second]->val,a.second));
            }
        }
        return new_head->next; 
    }
};