class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int ans =0;
        for(int i = 0; i < n; i++){
            int ch = heights[i];
            int r = n;
            while(!st.empty() && heights[st.top()] > ch){
                int  l = -1;
                r = i;
                int h = heights[st.top()];
                st.pop();
                if(!st.empty()){
                    l = st.top();
                }
                int area = (r-l-1)*h;
                ans = max(ans, area);
            }
            st.push(i);
        }
        while(!st.empty()){
            int c = st.top();
            st.pop();
            int l;
            if(!st.empty()){
                l = st.top();
            }else{
                l = -1;
            }
            int area = (n - l -1)*heights[c];
            ans = max(ans, area);
        }
        return ans;
    }
};