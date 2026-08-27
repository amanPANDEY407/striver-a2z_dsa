class Solution {
private:
    double solve(double x, long long n) {
        if(n == 0){
            return 1.0;
        }
        if(n == 1){
            return x;
        }
        if(n % 2 == 0){
            return solve(x * x, n / 2);
        } else {
            return x * solve(x, n - 1);
        }
    }

public:
    double myPow(double x, int n) {
        long long nn = n; 
        
        if(nn < 0){
            x = 1.0 / x;
            nn = -nn;     
        }
        
        return solve(x, nn);
    }
};