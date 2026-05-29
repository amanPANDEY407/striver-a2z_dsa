class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
      map <int, int> mpp;
      vector<int> v;
      for(int i = 0; i < nums.size(); i++){
        mpp[nums[i]]+=1;
      }
      for(int i = 0; i < nums.size(); i++){
        auto it1 = mpp.find(nums[i] - 1);
        auto it2 = mpp.find(nums[i] + 1);
        if(it1 != mpp.end()){
            it1->second += 2;
            mpp[nums[i]] += 2;
        }
        if(it2 != mpp.end()){
            it2->second += 2;
            mpp[nums[i]] += 2;
        }
      }
      for(int i = 0; i< nums.size(); i++){
        if(mpp[nums[i]]==1){
            v.push_back(nums[i]);
        }
      }
      return v;
    }
};