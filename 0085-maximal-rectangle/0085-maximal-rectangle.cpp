class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        int area = 0;
        vector<int> h(c,0);
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(matrix[i][j] == '0'){
                    h[j] = 0;
                }else{
                    h[j] += 1;
                }
            }
            stack<int> st;
            for(int k = 0; k < c; k++){
                int ch = h[k];
                int l = -1;
                int ri = c;
                while(!st.empty() && h[st.top()] >= ch){
                    l = -1;
                    int x = h[st.top()];
                    st.pop();
                    if(!st.empty()){
                        l = st.top();
                    }
                    ri = k;
                    area = max(area, (ri-l-1)*x);
                }
                st.push(k);
            }
            int li = -1;
            while(!st.empty()){
                int x = h[st.top()];
                st.pop();
                li = -1;
                if(!st.empty()){
                    li = st.top();
                }
                area = max(area, (c - li - 1)*x);
            }
        }
        return area;
    }
};