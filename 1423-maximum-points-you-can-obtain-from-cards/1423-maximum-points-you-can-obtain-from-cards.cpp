class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0;
        int lsum = 0;
        int rsum = 0;
        for(int i = 0; i < k; i++){
            lsum +=cardPoints[i];
        }
        sum = lsum;
        for(int i = 0; i < k; i++){
            rsum += cardPoints[n-1-i];
            lsum -= cardPoints[k-i-1];
            sum = max(sum,(lsum+rsum));
        }
        return sum;
    }
};