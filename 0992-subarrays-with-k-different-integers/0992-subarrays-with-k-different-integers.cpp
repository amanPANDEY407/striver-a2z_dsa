class Solution {
public:
    int atMax(vector<int>& nums, int k){
        if(k == 0){
            return 0;
        }
        int n = nums.size();
        unordered_map<int,int> mpp;
        int l,r,cnt,ans;
        l = r = ans = cnt = 0;
        while(r < n){
            if(mpp.find(nums[r]) == mpp.end() || mpp[nums[r]] == 0){
                cnt++;
                mpp[nums[r]] = 1;
            }else{
                mpp[nums[r]]++;
            }
            while(cnt > k){
                if(mpp[nums[l]] == 1){
                   cnt--;
                }
                mpp[nums[l]]--;
                l++;
            }
            ans += r - l + 1;
            r++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMax(nums, k) - atMax(nums, k-1);
    }
};