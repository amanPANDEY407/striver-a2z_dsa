class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int l = s.length();
        int ans = 0;
        for(char ch : s){
            if(ch == ' '){
                i++;
            }
            else{
                break;
            }
        }
        //s = s.substr(cnt, l - cnt);
        //l -= cnt;
        bool flag = true;
        if(s[i] == '-'){
            //s = s.substr(1, l - 1);
            //l -= 1;
            i++;
            flag = false;
        }
        else if(s[i] == '+'){
            //s = s.substr(1, l - 1);
            //l -= 1;  
            i++;
        }
        while(i < l){
            int digit = s[i] - '0';
            if(isdigit(s[i])){
                if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > 7)) {
              if (flag) {
                return INT_MAX; // Round to 2^31 - 1
              } else {
                  return INT_MIN; // Round to -2^31
                }
            }
                ans = ans*10 + (s[i]- 48);
            }
            else{
                break;
            }
            i++;
        }
        if(!flag){
            ans = ans*(-1);
        }
        return ans;
    }
};