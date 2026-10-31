class Solution {
public:
    int n;
    void subsets(int idx,const vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp){
        if(idx == n){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        subsets(++idx,nums, ans, temp);
        temp.pop_back();
        subsets(idx,nums, ans, temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        subsets(0,nums, ans, temp);
        return ans;
    }
};