class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int i = 0;
        int n = intervals.size();
        while(i < n){
            vector<int> cur = intervals[i];
            int check = intervals[i][1];
            while(i != n - 1 && check >= intervals[i+1][0]){
                if(check < intervals[i+1][1]){
                    check = intervals[i+1][1];
                }
                i++;
            }
            i++;
            ans.push_back({cur[0], check});
        }
        return ans;
    }
};