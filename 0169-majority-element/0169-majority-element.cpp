class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(count == 0){
                element = nums[i];
                count++;
            }
            else{
                if(nums[i] == element){
                    count++;
                }
                else{
                    count--;
                }
            }
        }
        count = 0;
        for(int i = 0;  i < nums.size(); i++){
            if(nums[i] == element){
                count++;
            }
        }
        if(count > nums.size()/2){
            return element;
        }
        return -1;
    }
};