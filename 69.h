class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        int r = x/2+1;
        while(l<=r){
            int mid = (l+r)/2;
            if ((long)mid*mid == x) return mid;
            else if ((long)mid*mid > x) r = mid-1;
            else l = mid+1;
        }
        return r;
    }
};
