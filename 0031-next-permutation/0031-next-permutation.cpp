class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int i = n - 2;
        while(i >= 0 && nums[i] >= nums[i + 1]){
            i--;
        }
        if(i == -1){
            for(int j = n - 1; j >= 0; j--){
                ans.push_back(nums[j]);
            }
        }
        else{
            for(int j = 0; j < i; j++){
                ans.push_back(nums[j]);
            }
            int max = nums[i];
            for(int j = n - 1; j >= i; j--){
                if(nums[j] > max){
                    ans.push_back(nums[j]);
                    swap(nums[i],nums[j]);
                    break;
                }
            }
            for(int j = n - 1; j >= i; j-- ){
                ans.push_back(nums[j]);
            }
        }
        for(int i = 0; i < n; i++){
            nums[i] = ans[i];
        }
    }
};