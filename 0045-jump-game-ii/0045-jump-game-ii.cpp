class Solution {
public:
    int jump(vector<int>& nums) {
        int jump, curend, far;
        jump = curend = far = 0;
        int n = nums.size();
        for(int  i = 0; i < n-1 && curend < n - 1; i++){
            far = max(far, i + nums[i]);
            if(curend == i){
                jump++;
                curend = far;
            }
        }
        return jump;
    }
};