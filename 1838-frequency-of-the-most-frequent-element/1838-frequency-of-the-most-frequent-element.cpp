class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        /*int maxx = 0;
        sort(nums.begin(), nums.end());
        int i = nums.size() - 1;
        for(auto it = nums.rbegin(); it != nums.rend(); it++ ){
            int temp = k;
            int j = i;
            int cnt=0;
            while(temp > 0){
                if(nums[i] - nums[j] <= temp){
                    cnt++;
                    temp = temp - (nums[i] - nums[j]);
                    if(j != 0)
                      j--;
                    else
                      break;
                }
                else{
                    break;
                }
            }
            if(cnt>maxx){
                maxx = cnt;
            }
            i--;
        }
        return maxx; */ //BRUTE FORCE (TLE)

        //Optimal Approach
        // We sort because it's easier to patch smaller numbers up to a larger number.
        sort(nums.begin(), nums.end());
        
        // Use long long to prevent integer overflow during multiplications
        long long actual_sum = 0; 
        int max_freq = 0;
        int left = 0; // The left boundary of our window
        
        // 'right' expands the window forward on every single turn
        for (int right = 0; right < nums.size(); ++right) {
            
            // Add the new element entering the window to our running total
            actual_sum += nums[right];
            
            // Calculate how many elements are currently in our window
            long long window_len = right - left + 1;
            
            // This is our condition check: 
            // Total operations needed = (window_len * nums[right]) - actual_sum
            // If this value is GREATER than k, our window is too wide for our budget.
            while (window_len * nums[right] - actual_sum > k) {
                
                // Shrink the window: remove the leftmost element's value from our sum
                actual_sum -= nums[left]; 
                
                // Move the left pointer up to narrow the window
                left++;                   
                
                // Recalculate the window length for the next loop check
                window_len = right - left + 1; 
            }
            
            // If we break out of the while loop, it means the window is now valid.
            // Check if this valid window is the largest we've seen so far.
            max_freq = max(max_freq, (int)window_len);
        }
        
        return max_freq;
    }
};