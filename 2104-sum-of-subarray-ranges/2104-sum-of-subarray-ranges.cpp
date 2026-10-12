class Solution {
public:
    void pgee(vector<int>& nums, vector<int>& pge, vector<int>& pse) {
        int n = nums.size();
        stack<int> st;
        stack<int> ts;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[i] > nums[st.top()]) {
                st.pop();
            }
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);

            while (!ts.empty() && nums[i] < nums[ts.top()]) {
                ts.pop();
            }
            pse[i] = ts.empty() ? -1 : ts.top();
            ts.push(i);
        }
    }

    void ngee(vector<int>& nums, vector<int>& nge, vector<int>& nse) {
        int n = nums.size();
        stack<int> st;
        stack<int> ts;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[i] >= nums[st.top()]) {
                st.pop();
            }
            nge[i] = st.empty() ? n : st.top();
            st.push(i);

            while (!ts.empty() && nums[i] <= nums[ts.top()]) {
                ts.pop();
            }
            nse[i] = ts.empty() ? n : ts.top();
            ts.push(i);
        }
    }

    long long subArrayRanges(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();
        vector<int> pge(n), pse(n), nge(n), nse(n);

        ngee(nums, nge, nse);
        pgee(nums, pge, pse);

        for (int i = 0; i < n; i++) {
            long long max_count = 1LL * (nge[i] - i) * (i - pge[i]);
            long long min_count = 1LL * (nse[i] - i) * (i - pse[i]);
            sum += (max_count - min_count) * nums[i];
        }

        return sum;
    }
};