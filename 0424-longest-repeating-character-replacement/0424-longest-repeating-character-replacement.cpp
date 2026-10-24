class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int freq[26] = {0};
        int l, r, len, maxF;
        l = r = len = maxF = 0;
        for(;r < n; r++){
            freq[s[r] - 'A']++;
            maxF = max(maxF, freq[s[r] - 'A']);
            while(r - l + 1 - maxF > k){
                freq[s[l] - 'A']--;
                l++;
            }
            len = max(len, r - l + 1);
        }
        return len;
    }
};