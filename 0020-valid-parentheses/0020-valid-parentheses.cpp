class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int l = s.length();
        for(int i = 0; i < l; i++){
            char ch = s[i];
            if(st.empty()){
                st.push(ch);
            }else{
                if(st.top() == '(' && ch == ')'){
                    st.pop();
                }else if(st.top() == '{' && ch == '}'){
                    st.pop();
                }else if(st.top() == '[' && ch == ']'){
                    st.pop();
                }else{
                    st.push(ch);
                }
            }
        }
        return st.empty();
    }
};