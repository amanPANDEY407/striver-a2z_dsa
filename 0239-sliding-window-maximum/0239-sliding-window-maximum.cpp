class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int max = nums[0];
        vector<int> ans;
        deque<int> q;
        int i;
        for(i = 0; i < k; i++){
            int ch = nums[i];
            while(!q.empty() && ch > nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
        }
        ans.push_back(nums[q.front()]);
        if(q.front() <= i - k){
            q.pop_front();
        }
        for(i = k; i < n; i++){
            int ch = nums[i];
            while(!q.empty() && ch > nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
            if(q.front() <= i - k){
                q.pop_front();
            }
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};