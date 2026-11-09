class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {
        int ans = 0;
        int n = target.size();
        int idx = n - 2;
        unordered_map<int,int> mpp;
        for(int i = 0; i < n; i++){
            mpp[nums[i]]++;
            mpp[target[i]]--;
        }
        for(auto it : mpp){
            if (it.second != 0) return 0;
        }
        for(; idx >= 0; idx--){
            if(target[idx] < target[idx+1]){
                break;
            }
        }
        idx++;
        for(int i = 0; i < n; i++){
            if(i >= idx){
                ans++;
            }
            if(nums[i] != target[i]) break;
        }
        return ans;
    }
};