#include <bits/stdc++.h>

using namespace std;

/*
   @ 编写Solution :  14.h
   @ 主函数入口    :  main.cpp
   @ Author      :  Vodka
   @ Time        :  20-10-31 下午8:49 
*/

class Solution {
public:
    int cuttingRope(int n) {
        int dp[60];
        memset(dp,0,sizeof(dp));
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                dp[i]= max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }
        return dp[n];
    }
};


/*  解决思路 & 复杂度
    简单dp，首先上来先分析一下问题结构，长为n的绳子截成m段的最大值，由于不管截成几段绳子的总长度都是不变的，所以其实这里的m并不work
    所以相当于还是问长为n的绳子的最大值，那么当长为n-i时也是同样最优子结构的问题，而n和n-i之间，实际上是转移变化就是把n长度的绳子剪成了i和n-i两端
    所以转移方程也算有了的，直接dp即可。
*/

/*  Main函数入口
    int main(){
        Solution ans = Solution();
        ans.cuttingRope(2);
        return 0;
    }
*/