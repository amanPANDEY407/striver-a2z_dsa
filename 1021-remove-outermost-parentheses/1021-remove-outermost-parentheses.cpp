class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int cnt = 0;
        int j = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                cnt++;
            }
            else{
                cnt--;
                if(cnt == 0){
                    ans =ans + s.substr(j+1, i - j -1);
                    j = i+1;
                }
            }
        }
        return ans;
    }
};