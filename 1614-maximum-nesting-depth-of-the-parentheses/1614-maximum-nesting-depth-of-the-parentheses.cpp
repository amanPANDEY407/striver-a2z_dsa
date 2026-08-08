class Solution {
public:
    int maxDepth(string s) {
        stack<int> sck;
        int cnt = 0;
        int ans = 0;
        for(int  i = 0; i < s.length(); i++){
            if(s[i] == '('){
                sck.push('(');
                cnt++;
                ans = max(ans, cnt);
            }
            else if(s[i] == ')'){
                cnt--;
                sck.pop();
            }
            else{}
        }
        return ans;
    }
};