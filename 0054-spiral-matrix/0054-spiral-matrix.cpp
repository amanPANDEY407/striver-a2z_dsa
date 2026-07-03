class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.empty() || matrix[0].empty()) return ans; // Edge case safety
        
        int n = matrix.size();
        int m = matrix[0].size();
        int left = 0;
        int right = m - 1;
        int top = 0;
        int bottom = n - 1;
        
        while(top <= bottom && left <= right){
            // 1. Move Right
            for(int i = left; i <= right; i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            
            // 2. Move Down
            for(int i = top; i <= bottom; i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
            
            // 3. Move Left (Check if a valid row still exists)
            if (top <= bottom) {
                for(int i = right; i >= left; i-- ){
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            
            // 4. Move Up (Check if a valid column still exists)
            if (left <= right) {
                for(int i = bottom; i >= top; i-- ){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};