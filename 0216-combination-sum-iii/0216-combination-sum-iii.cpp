class Solution {
public:
    void combSum(int idx, int k, int n, vector<int>& temp, vector<vector<int>>& ans){
        if(k == 0 && n == 0){
            ans.push_back(temp);
            return;
        }
        if(n <= 0 || k <= 0 || idx > 9) return;
        temp.push_back(idx);
        combSum(idx + 1, k - 1, n - idx , temp, ans);
        temp.pop_back();
        combSum(idx + 1, k, n, temp, ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<vector<int>> ans;
        combSum(1, k, n, temp, ans);
        return ans;
    }
};