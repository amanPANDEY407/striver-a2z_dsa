class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int l = nums2.size();
        map<int, int> ans;
        vector<int> anss;
        int l1 = nums1.size();
        for(int i = l-1; i >= 0; i--){
            if(st.empty()){
                st.push(nums2[i]);
                ans[nums2[i]] = -1;
            }else if(st.top() > nums2[i]){
                ans[nums2[i]] = st.top();
                st.push(nums2[i]);
            }else{
                while(!st.empty() && st.top() <= nums2[i]){
                    st.pop();
                }
                if(st.empty()){
                    st.push(nums2[i]);
                    ans[nums2[i]] = -1;
                }else{
                    ans[nums2[i]] = st.top();
                    st.push(nums2[i]);
                }
            }
        }
        for(int i = 0; i < l1 ;i++){
            anss.push_back(ans[nums1[i]]);
        }
        return anss;
    }
};