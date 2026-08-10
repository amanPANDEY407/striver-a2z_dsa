class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int ans = 0;
        for(int i = 0; i < n; i++){
            vector<int> v(26,0);
            for(int j = i; j < n; j++){
                v[s[j] - 'a']++;
                int mini = INT_MAX,maxi = 0;
                for(int f : v){
                    if(f> 0){
                        mini = min(mini, f);
                        maxi = max(maxi, f);
                    }
                }
                ans += maxi - mini;
            }
        }
        return ans;
    }
};