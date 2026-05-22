class Solution {
public:
    bool isPalindrome(int x) {
       if(x<0){
        return false;
       } 
       else{
        long long rev=0;
        int temp=x;
        while(temp !=0){
            rev = rev*10 + temp % 10;
            temp = temp / 10;
        }
        if(rev >= INT_MIN && rev <=INT_MAX && rev == x){
            return true;
        }
        else{
            return false;
        }
       }
    }
};