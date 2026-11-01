class Solution {
public:
    int n;
    void combs(int idx, vector<int>& candidates, vector<int>& temp, vector<vector<int>>& ans, int target){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(target < 0 || idx == n) return;
        temp.push_back(candidates[idx]);
        combs(idx + 1, candidates, temp, ans, target - candidates[idx]);
        temp.pop_back();
        while(idx < n-1 && candidates[idx+1] == candidates[idx]) idx++;
        combs(idx + 1, candidates, temp, ans, target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        vector<vector<int>> ans;
        int idx = 0;
        combs(idx, candidates, temp, ans, target);
        return ans;
    }
};