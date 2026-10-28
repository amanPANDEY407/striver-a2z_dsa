class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int rem = n;
        int busy = -50000;
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
            return a[1] < b[1];
        });
        for(int i = 0; i < n; i++){
            if(intervals[i][0] >= busy){
                rem--;
                busy = intervals[i][1];
            }
        }
        return rem;
    }
};