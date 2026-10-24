class Solution {
public:
    string minWindow(string s, string t) {
        int l1 = s.length();
        int l2 = t.length();
        int cnt = 0;
        int startIdx = -1;
        if(l2>l1){
            return "";
        }
        int l,r,len;
        r=0;
        len = l1+1;
        l = -1;
        unordered_map<char,pair<int,int>> freq;
        for(; r < l2; r++){
            if(freq.find(t[r]) == freq.end()){
                freq[t[r]].first = 1;
                freq[t[r]].second = 0;
            }else{
                freq[t[r]].first++;
            }
        }
        for(r = 0; r < l1 ; r++){
            if(freq.find(s[r]) != freq.end()){
                l = r;
                break;
            }
        }
        for(; r < l1; r++){
            if(freq.find(s[r]) != freq.end()){
                freq[s[r]].second++;
                if(freq[s[r]].second <= freq[s[r]].first){
                    cnt++;
                }
            }
            while(freq.find(s[l]) == freq.end() || freq[s[l]].first < freq[s[l]].second){
                if(freq.find(s[l]) != freq.end()){
                    freq[s[l]].second--;
                }
                l++;
            }
            if(cnt == l2 && r-l+1 < len){
                len = r-l+1;
                startIdx = l;
            }
        }
        return startIdx == -1 ? "" : s.substr(startIdx, len);
    }
};