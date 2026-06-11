class Solution {
public:
    int pointerUpdate(vector<int>& nums, int i){
        while(i < nums.size()-1 && nums[i] == nums[i+1]){
            i++;
        }
        return i;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i = 0; i < n-2; i++){
            int left = i+1;
            int right = n-1;
            while(left < right){
                int req = -1 * nums[i];
                if(nums[left] + nums[right] == req){
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[left]);
                    v.push_back(nums[right]);
                    ans.push_back(v);
                    left = pointerUpdate(nums, left) + 1;
                    while(right>0 && nums[right] == nums[right - 1]){
                        right--;
                    }
                    right--;
                }
                else if(nums[left] + nums[right] < req){
                    left = pointerUpdate(nums, left) + 1;
                }
                else{
                    while(right>0 && nums[right] == nums[right - 1]){
                        right--;
                    }
                    right--;
                }
            }
            i = pointerUpdate(nums, i);
        }
        return ans;
    }
};