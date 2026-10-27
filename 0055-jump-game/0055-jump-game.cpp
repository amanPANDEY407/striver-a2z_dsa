class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cnt = nums[0];
        int i = 1;
        int n = nums.size();
        while(cnt > 0 && i < n){
            cnt--;
            if(cnt < nums[i]){
                cnt = nums[i];
            }
            i++;
        }
        if(i == n){
            return true;
        }
        return false;
    }
};