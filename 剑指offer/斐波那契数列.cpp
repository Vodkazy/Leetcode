class Solution {
public:
    int a [105];

    int fib(int n) {
        int mod = 1000000007;
        a[0] = 0;
        a[1] = 1;
        a[2] = 1;
        for(int i=3;i<=100;i++){
            a[i] = (a[i-1]%mod + a[i-2]%mod)%mod;
        }
        return a[n];
    }
};
