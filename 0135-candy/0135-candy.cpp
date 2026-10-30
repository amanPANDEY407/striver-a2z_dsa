class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n,0);
        candies[0] = 1;
        int ans = 0;
        for(int i = 1; i < n; i++){
            candies[i]++;
            if(ratings[i-1] < ratings[i]){
                candies[i] = max(candies[i], candies[i-1] + 1);
            }
        }
        for(int i= n - 2; i >= 0; i--){
            if(ratings[i] > ratings[i+1]){
                candies[i] = max(candies[i], candies[i+1] + 1);
            }
        }
        for(int i = 0; i < n; i++) ans += candies[i];
        return ans;
    }
};