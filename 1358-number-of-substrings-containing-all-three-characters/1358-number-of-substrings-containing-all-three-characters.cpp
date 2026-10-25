class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int l, r, cnt,ans;
        l = r = cnt = ans = 0;
        int freq[3] = {1,1,1};
        while(r<n){
            freq[s[r] - 'a']--;
            if(freq[s[r]  - 'a'] ==0){
                cnt++;
            }
            while(cnt == 3 && freq[s[l] - 'a'] < 1){
                freq[s[l] - 'a']++;
                if(freq[s[l] - 'a']==1){
                    cnt--;//Window is no more valid
                }
                ans = ans + (n-r);
                l++;
            }
            r++;
        }
        return ans;
    }
};