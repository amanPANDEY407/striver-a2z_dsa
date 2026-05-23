class Solution {
  public:
    bool armstrongNumber(int n) {
        // code here
        if(n>=1000 && n<100){
            return false;
        }
        else{
            int z=0;
            int temp = n;
            while(temp != 0){
                z=z + pow(temp % 10, 3);
                temp = temp/10;
            }
            if(z==n){
                return true;
            }
            else{
                return false;
            }
        }
    }
};
