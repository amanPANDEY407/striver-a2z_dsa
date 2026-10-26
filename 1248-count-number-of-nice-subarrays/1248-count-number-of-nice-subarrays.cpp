class Solution {
public:
    int atMax(vector<int>& nums, int k){
        int n = nums.size();
        int l, r, cnt,ans;
        l = r = cnt = ans = 0;
        while(r < n){
            if(nums[r] % 2 != 0) cnt++;
            while(l < r && cnt > k){
                if(nums[l] % 2 != 0) cnt--;
                l++;
            }
            if(cnt <= k){
                ans += r - l + 1;
            }
            r++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMax(nums, k) - atMax(nums, k-1);
    }
};