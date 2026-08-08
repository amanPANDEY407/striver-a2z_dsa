class Solution {
public:
    int myAtoi(string s) {
        int cnt = 0;
        int l = s.length();
        int ans = 0;
        for(char ch : s){
            if(ch == ' '){
                cnt++;
            }
            else{
                break;
            }
        }
        s = s.substr(cnt, l - cnt);
        l -= cnt;
        bool flag = true;
        if(s[0] == '-'){
            s = s.substr(1, l - 1);
            l -= 1;
            flag = false;
        }
        else if(s[0] == '+'){
            s = s.substr(1, l - 1);
            l -= 1;  

        }
        for(int i = 0; i < l; i++){
            int digit = s[i] - '0';
            if (((int)s[i] <= 57 && (int)s[i] >= 48) && ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > 7)) {
              if (flag) {
                return INT_MAX; // Round to 2^31 - 1
              } else {
                  return INT_MIN; // Round to -2^31
                }
            }
            if((int)s[i] <= 57 && (int)s[i] >= 48){
                ans = ans*10 + (s[i]- 48);
            }
            else{
                break;
            }
        }
        if(!flag){
            ans = ans*(-1);
        }
        return ans;
    }
};