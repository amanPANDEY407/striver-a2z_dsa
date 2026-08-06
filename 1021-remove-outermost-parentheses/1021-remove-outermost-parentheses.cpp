class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st;
        int n=s.size();
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(st.size()>0){
                    ans.push_back('(');
                }
                st.push('(');
            }
            else{
                st.pop();
                if(st.size()>0){
                    ans.push_back(')');
                }
            }
        }
        return ans;
    }//TC:O(n) and SC:O(n)
};