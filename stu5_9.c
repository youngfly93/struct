class Solution{
public:
    vector<int>twoSum(vector<int> &nums,int target){
        int n = nums.size();
        vector <int> ind(n);
        for(int i = 0; i < n;i++){
            ind[i] = i;
        }
        sort(ind.begin(),ind.end(),[&](int a, int b){
            return nums[a] < nums[b];
        });
        int p1 = 0, p2 = n  -1;
        while(nums[ind[p1]] + nums[ind[p2]] != target){
            if(nums[ind[p1]] + nums[ind[p2]] > target){
                p2--;
            }
            else{
                p1++;
            }
        }
        vector <int> ret(2);
        ret[0] = ind[p1];
        ret[1] = ind[p2];
        if(ret[0] > ret[1]){
            swap(ret[0],ret[1]);
        }
        return ret;
    }
};