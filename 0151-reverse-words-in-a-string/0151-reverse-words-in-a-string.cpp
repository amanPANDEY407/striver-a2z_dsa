class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int count = 0;
        int j = 0;
        while(s[j] == ' '){
            j++;
        }
        s = s.substr(j, s.length() - j);
        for(int i = s.length() - 1; i >= 0 ; i--){
            if(s[i] != ' '){
                count++;
            }
            else if(s[i] == ' ' && count != 0){
                ans = ans  + s.substr(i+1, count);
                if(i != 0){
                    ans = ans + " ";
                }
                count  = 0;
            }
            else{
                count = 0;
            }
        }
        if(s[0] != ' '){
            ans = ans + s.substr(0, count);
        }
        return ans;
    }
};