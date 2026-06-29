class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col = 1;
        int n = matrix.size() - 1;
        int m = matrix[0].size() - 1;
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m;  j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    if(j == 0){
                        col = 0;
                    }
                    else{
                        matrix[0][j] = 0;
                    }
                }
            }
        }
        for(int i = n;  i >= 0; i--){
            for(int j = m; j >= 0; j--){
                if(matrix[i][0] == 0){
                    matrix[i][j] = 0;
                }
                else if(j == 0 && col == 0){
                    matrix[i][j] = 0;
                }
                else if(j != 0 && matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
                else{
                    //bhag le bete
                }
            }
        }
    }
};