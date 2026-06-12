class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n-3; i++){
            if(i>0 && nums[i-1] == nums[i]){
                continue;
            }
            for(int j = i+1; j < n-2; j++){
                if(j > i+1 && nums[j-1] == nums[j]){
                    continue;
                }
                int left = j+1;
                int right = n-1;
                while(left < right){
                    bool flag = false;
                    if(left > j+1 && nums[left - 1] == nums[left]){
                        left++;
                        flag = true;
                    }
                    if(right < n-1 && nums[right +1] == nums[right]){
                        right--;
                        flag = true;
                    }
                    if(flag){
                        continue;
                    }
                    long long sum =(long long) nums[i] + (long long)nums[j] + (long long)nums[left] + (long long)nums[right];
                    if(sum == (long long)target){
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                    }
                    else if(sum < target){
                        left++;
                    }
                    else{
                        right--;
                    }
                }     
            }
        }
        return ans;
    }
};