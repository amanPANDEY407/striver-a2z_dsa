class Solution {
public:
    int MOD = 1e9 + 7;
    long long power(long long x, long long n) {
        if (n == 0) return 1;
        long long half = power(x, n / 2);
        half = (half * half) % MOD;
        if (n % 2 == 0) {
            return half;
        } else {
            return (x * half) % MOD;
        }
    }
    int countGoodNumbers(long long n) {
        long long e = (n + 1) / 2;
        long long o = n / 2;
        long long ec = power(5, e);
        long long oc = power(4, o);
        return (ec * oc) % MOD;
    }
};