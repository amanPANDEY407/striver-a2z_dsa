class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        for(int i = 0; i < numRows; i++){
            vector<int> row;
            for(int j = 0; j <= i; j++){
                if(j == i || j == 0){
                    row.push_back(1);
                    continue;
                }
                row.push_back(v[i-1][j - 1] + v[i-1][j]);
            }
            v.emplace_back(row);
        }
        return v;
    }
};