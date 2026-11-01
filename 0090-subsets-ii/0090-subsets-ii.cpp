class Solution {
public:
    int n;
    void subset(int idx, vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp){
        if(idx == n){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        subset(idx + 1, nums, ans, temp);
        temp.pop_back();
        while(idx < n-1 && nums[idx] == nums[idx + 1]) idx++;
        subset(idx + 1, nums, ans, temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n = nums.size();
        vector<int> temp;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        subset(0, nums, ans, temp);
        return ans;
    }
};