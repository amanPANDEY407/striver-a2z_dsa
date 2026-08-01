class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m[256] ={0};
        int n[256] = {0};
        if(s.length() != t.length()){
            return false;
        }
        int l = s.length();
        for(int i = 0; i < l; i++){
            if(m[s[i]] != n[t[i]]){
                return false;
            }
            m[s[i]] = i+1;
            n[t[i]] = i+1;
        }
        return true;
    }
};