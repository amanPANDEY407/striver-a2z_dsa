class Solution {
public:
    int reverse(int x) {
        long long rev = 0;
        if(x<0){
        while(x!=0){
            rev = rev*10 + x%(-10);
            x= x/10;
        }
        }else{
            while(x!=0){
            rev = rev*10 + x%10;
            x= x/10;
            }
        }
        long long MAX = pow(2,31) - 1;
        long long MIN = -1 * pow(2,31);
        if(rev >= MIN && rev <= MAX){
            return (int)rev;
        }
        else{
            return 0;
        }
    }
};