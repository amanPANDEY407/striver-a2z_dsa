class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,bool>mpp;
        int l,r;
        l = r = 0;
        int len = 0;
        int n = s.length();
        while(r < n ){
            char ch = s[r];
            while(mpp.find(ch) != mpp.end()&& mpp[ch] != false){
                mpp[s[l]] = false;
                l++;
            }
            mpp[ch] = true;
            len = max(len, r-l+1);
            r++;
        }
        return len;
    }
};