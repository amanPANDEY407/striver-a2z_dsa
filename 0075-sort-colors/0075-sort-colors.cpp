class Solution {
public:
    void sortColors(vector<int>& nums) {
        int j,k,l;
        j = k = l = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 0){
                j++;
            }
            else if(nums[i] == 1){
                k++;
            }
            else{
                l++;
            }
        }
        int i = 0;
        while(j > 0){
            nums[i++] = 0;
            j--;
        }
        while(k > 0){
            nums[i++] = 1;
            k--;
        }
        while(l > 0){
            nums[i++] = 2;
            l--;
        }
    }
};