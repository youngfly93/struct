class KthLargest {
public:
    typedef pair<int,int> pII;
    int tot,k;
    set<pII> s;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int i = 0; i < nums.size();i++){
            add(nums[i]);
        }
    }
    int add(int val){
        if (s.size()< k){
            s.insert(pII(val,tot++));
        }else{
            if (s.begin()->first < val){
                s.insert(pII(val,tot++));
            }
        }
        if (s.size() > k){
            s.erase(s.begin());
        }
        return s.begin()->first;
    }
};