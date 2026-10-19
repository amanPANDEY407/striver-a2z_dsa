class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int obs = 0;
        int water = 0;
        int  n = height.size();
        for(int i = 0; i < n; i++){
            int ch = height[i];
            while(!st.empty() && height[st.top()] <= ch){
                obs = height[st.top()];
                st.pop();
                if(!st.empty()){
                    water += (min(height[st.top()],ch) - obs)*(i - st.top() - 1);
                }
            }
            st.push(i);
        }
        /*while(st.size > 1){
            obs += height[st.top()];
            water = height[st.top()]*(n - st.top());
            st.pop();
        }*/
        return water;
    }
};