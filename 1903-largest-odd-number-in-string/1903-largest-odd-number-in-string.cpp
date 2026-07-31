class Solution {
public:
    string largestOddNumber(string num) {
       int l = num.length();
       string answer = "";
       for(int i = l - 1; i>=0; i--){
          char ch = num[i];
          int x = ch - '0';
          if(x % 2 != 0){
            answer = num.substr(0, i+1);
            break;
          }
       }
       return answer;
    }
};