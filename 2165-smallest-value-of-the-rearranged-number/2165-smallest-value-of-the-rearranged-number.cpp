class Solution {
public:
    long long smallestNumber(long long num) {
        int sign = 0;
        if(num < 0){
            sign = 1;
            num = num*(-1);
        }
        long long ans = 0;
        vector<int> v(10,0);
        int temp;
        while(num != 0){
            temp = (int)(num%10);
            v[temp]++;
            num = num/10;
        }
        if(sign){
          for(int i = 9; i >= 0; i--){
              while(v[i] != 0){
                  ans = ans*10 + i;
                  v[i]--;
              }
          }
          return ans*(-1);
        }
        else{
            for(int i = 1; i <= 9; i++){
              while(v[i] != 0){
                  ans = ans*10 + i;
                  v[i]--;
                  while(v[0] != 0){
                    ans = ans*10;
                    v[0]--;
                  }
              }
          }
          return ans;
        }
    }
};