class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> mpp;
        int count = 0;
        int ans = 0;
        int prev;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            mpp[nums[i]] = i;
        }
        for(auto it : mpp){
            if( count == 0){
                prev = it.first;
                count++;
                ans = max(ans, count);
            }
            else if(it.first - prev == 1){
                count++;
                prev++;
                ans = max(ans, count);
            }
            else{
                prev = it.first;
                ans = max(ans, count);
                count = 1;
            }
        }
        return ans;
    }
};