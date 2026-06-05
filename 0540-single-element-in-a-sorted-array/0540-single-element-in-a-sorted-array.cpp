class Solution {
public:
    void func(vector<int> &nums, int low, int high, int& idx){
        int mid = (low + high)/2;
        if(low >= high){
            idx = mid;
            return;
        }
        if( high - low == 2){
            if(nums[mid] == nums[low]){
                idx = high;
                return;
            }
            else{
                idx = low;
                return;
            }
        }
        if(nums[mid] == nums[mid - 1]){
            if((high - mid)%2 == 0){
                func(nums, low, mid, idx);
            }
            else{
                func(nums, mid - 1, high, idx);
            }
        }
        else if(nums[mid] == nums[mid +1]){
            if((high - mid)%2 == 0){
                func(nums, mid, high, idx);
            }
            else{
                func(nums, low, mid + 1, idx);
            }
        }
        else{
            idx = mid;
            return;
        }
    }
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int idx;
        func(nums, 0, n-1, idx);
        return nums[idx];
    }
};