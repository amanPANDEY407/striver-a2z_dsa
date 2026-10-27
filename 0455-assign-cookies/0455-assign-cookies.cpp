class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m = g.size();
        int n = s.size();
        int i, j;
        i = j = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while(i < n && j < m){
            if(s[i] >= g[j]){
                j++;
            }
            i++;
        }
        return j;
    }
};