class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> anss;
        stack<int> st;
        int n = asteroids.size();
        vector<int> ans(n,0);
        for(int i = n-1; i >= 0; i--){
            int elem = asteroids[i];
            if(elem < 0){
                st.push(elem);
            }
            else if(st.empty() && elem > 0){
                ans[i] = elem;
            }else{
                while(!st.empty()){
                    if(elem > abs(st.top())){
                        st.pop();
                    }else if(elem == abs(st.top())){
                        elem = 0;
                        st.pop();
                        break;
                    }else{
                        elem  =0;
                        break;
                    }
                }
                if(elem != 0){
                    ans[i] = elem;
                }
            }
        }
        while(!st.empty()){
            anss.push_back(st.top());
            st.pop();
        }
        for(int i  = 0; i < n; i++){
            if(ans[i] != 0){
                anss.push_back(ans[i]);
            }
        }
        return anss;
    }
};