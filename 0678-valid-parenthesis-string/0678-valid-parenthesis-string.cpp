class Solution {
public:
    bool checkValidString(string s) {
        int min, max, n, i;
        min = max = i = 0;
        n = s.length();
        for( ; i < n; i++){
            if(s[i] == '('){
                min++;
                max++;
            }else if(s[i] == ')'){
                min--;
                max--;
            }else{
                min--;
                max++;
            }
            if(max < 0) return false;
            if(min < 0) min = 0;
        }
        return min == 0;
    }
};