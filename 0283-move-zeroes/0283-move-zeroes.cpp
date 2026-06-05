class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int k =0;
        for(int j = 0; j < n; j++){
            if(nums[j] != 0){
                nums[low++] = nums[j];
            }
            if(nums[j] == 0){
                k++;
            }
        }
        for(int i = n-1; i>= n-k; i--){
            nums[i] = 0;
        }
    }
};