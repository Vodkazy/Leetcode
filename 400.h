#define ll long long

class Solution {
public:
    int findNthDigit(int n) {
        ll len = 1;
        ll base = 1;
        ll m = n;
        while(m > 9*base*len){
            m -= 9*base*len;
            len ++;
            base *= 10;
        }
        ll curNum = (ll) (base + (m-1) / len);
        return (to_string(curNum)[(ll) ((m - 1) % len)] - '0');
    }
};
