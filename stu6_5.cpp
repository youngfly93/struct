class Solution{
public:
    int searchInsert(vector <int> &nums,int large){
        int head = 0,tail = nums.size(),mid;
        while(head < tail){
            mid = (head + tail) / 2;
            if(nums[mid] < large) tail = mid + 1;
            else head = mid;
        }
        return head;
    }
}