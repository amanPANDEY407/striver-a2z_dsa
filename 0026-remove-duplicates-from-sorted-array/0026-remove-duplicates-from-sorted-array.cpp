class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> v={};
        int k=0;
        for(int i = 0; i<n-1; i++){
            if(nums[i] == nums[i+1]){
                nums[i] = 101;
            }
        }
        for(int i = 0; i < n; i++){
            if(nums[i] != 101){
                v.push_back(nums[i]);
                k++;
            }
        }
        for(int i = 0; i<k;i++){
            nums[i] = v[i];
        }
        return k;
    }
};