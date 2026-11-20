class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> digit;
        digit.assign(digits.begin(), digits.end());
        int n = digit.size();
        for(int i = n-1; i >= 0; i--){
            if(digit[i] != 9){
                digit[i]++;
                return digit;
            }else{
                digit[i] = 0;
            }
        }
        if(digit[0] == 0){
            digit.insert(digit.begin(),1);
        }else digit[0]++;
        return digit;
    }
};