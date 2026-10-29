class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> start;
        vector<int> end;
        int curr_count, maxx, i, j;
        curr_count = maxx = i = j = 0;
        int n = intervals.size();
        for( ; i < n; i++){
            start.push_back(intervals[i][0]);
            end.push_back(intervals[i][1]);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        i = 0;
        while(i < n && j < n){
            if(start[i] <= end[j]){
                curr_count++;
                maxx = max(maxx, curr_count);
                i++;
            }else{
                curr_count--;
                j++;
            }
        }
        return maxx;
    }
};