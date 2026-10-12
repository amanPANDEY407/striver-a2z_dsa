class Solution {
public:
    vector<int> nse(vector<int>& arr){
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st; 
        for(int i = n - 1 ; i>= 0; i--){
            while(!st.empty() && arr[i] <= arr[st.top()]){
                st.pop();
            }
            if(st.empty()){
                nse[i] = n;
            }else{
                nse[i] = st.top();
            }
            st.push(i);
        }
        return nse;
    }
    vector<int> pse(vector<int>& arr){
        int n = arr.size();
        vector<int> pse(n);
        stack<int> st; 
        for(int i = 0 ; i<n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            if(st.empty()){
                pse[i] = -1;
            }else{
                pse[i] = st.top();
            }
            st.push(i);
        }
        return pse;
    }
    int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    long long sum = 0;
    const int MOD = 1e9 + 7;

    vector<int> next_s = nse(arr);
    vector<int> prev_s = pse(arr);

    for (int i = 0; i < n; i++) {
        long long choices = (1LL * (next_s[i] - i) * (i - prev_s[i])) % MOD;
        sum = (sum + choices * arr[i]) % MOD;
    }

    return sum;
}
};