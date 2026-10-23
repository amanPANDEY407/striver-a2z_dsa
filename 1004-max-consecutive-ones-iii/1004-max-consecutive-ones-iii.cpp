class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l, r, cnt, len;
        l = r = cnt = len = 0;
        while(r < n){
            while(cnt >= k && nums[r] == 0 && nums[l] != 0){
                l++;
            }
            if(nums[r] == 0 && cnt < k){
                cnt++;
            }else if(nums[r] == 0 && cnt >= k){
                l++;
            }
            r++;
            len = max(len, (r-l));
        }
        return len;
    }
};