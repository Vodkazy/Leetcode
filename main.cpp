#include "435.h"

int main() {
    Solution ans = Solution();
    vector<int> v1 = {1,2};
    vector<int> v2 = {2,4};
    vector<int> v3 = {1,3};
    vector<vector<int>>intervals = {v1,v2,v3};
    cout<< ans.eraseOverlapIntervals(intervals);
    return 0;
}