class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       map<int,int> mpp;
       int n = nums.size();
       for(int i = 0; i < nums.size(); i++){
        mpp[nums[i]] += 1;
       } 
       nums.erase(nums.begin(), nums.end());
       for(pair<int, int> it : mpp){
        if(it.second > n/3){
            nums.push_back(it.first);
        }
       }
       return nums;
    }
};