#include <bits/stdc++.h>
/*
   @ 编写Solution :  435.h
   @ 主函数入口    :  main.cpp
   @ Author      :  Vodka
   @ Time        :  20-10-6 下午11:04 
*/
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0)
            return 0;
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){
            return a[1] < b[1];
        });
        int cnt = 0;
        int _index = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] < _index){
                cnt++;
            } else{
                _index = intervals[i][1];
            }
        }
        return cnt;
    }
};


/*  解决思路 & 复杂度
    选择的区间结尾越小,余留给其它区间的空间就越大,就越能保留更多的区间。因此,我们采取的贪心策略为,优先保留结尾小且不相交的区间。
    对所有区间按照结尾位置排序，每次取结尾离得最近的，这样可以尽可能的覆盖更多的区间。如果与之前已经取过的区间发生重叠，则丢弃。
    当集合为空时要直接输出0。

    另一种做法：动态规划
    如果我们按照起始点对区间进行排序，可以很大程度上简化问题。
    一旦完成之后，我们就可以使用一个 dp 数组，其中 dp[i] 存储着只考虑到 第i个 区间范围内（包括其本身），最大可能的区间数。
    现在，当计算 dp[i+1] 时，我们不能只考虑 dp[i] 的值，因为前面的 i 个区间都可能与 第 i+1 个区间发生重叠。
    因此，我们需要考虑能够使得 j≤i 且与第 i+1 个区间不发生重叠的所有 dp[j] 中的最大值。状态转移方程如下：
    dp[i+1]=max(dp[j])+1,
    其中对于所有 j≤i ，第 i 个和第 j 个区间不发生重叠。
    最终的结果为区间的总数减去dp 数组中的最大值。
    */

/*  Main函数入口
    int main() {
        Solution ans = Solution();
        vector<int> v1 = {1,2};
        vector<int> v2 = {2,4};
        vector<int> v3 = {1,3};
        vector<vector<int>>intervals = {v1,v2,v3};
        cout<< ans.eraseOverlapIntervals(intervals);
        return 0;
    }
*/