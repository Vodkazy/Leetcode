#include <bits/stdc++.h>

using namespace std;

/*
   @ 编写Solution :  322.h
   @ 主函数入口    :  main.cpp
   @ Author      :  Vodka
   @ Time        :  20-10-28 下午1:09 
*/

class Solution {
public:
    int dp[10005];

    int coinChange(vector<int>& coins, int amount) {
        memset(dp, 0x3f3f3f, sizeof(dp));
        dp[0] = 0;
        for(int i=0;i<=amount;i++){
            for(int j=coins.size()-1;j>=0;j--){
                if(i-coins[j]<0) continue;
                dp[i] = min(dp[i], dp[i-coins[j]]+1);
            }
        }
        // for(int i=0;i<=amount;i++)cout<<dp[i]<<" ";cout<<endl;
        if(dp[amount]>amount) return -1;
        else return dp[amount];
    }
};


/*  解决思路 & 复杂度
    DP问题，重叠子问题、最优子结构、状态转移方程是动态规划三要素。
    思路： 明确 base case(特殊情况比如为0的时候直接返回啥，到n的时候该怎么结束)
        -> 明确「状态」(有哪些变量是会变化的，就有可能作为dp[状态]，比如背包问题里的容量)
        -> 明确「选择」（也就是导致状态产生变化的行为，比如背包问题里的物品的质量）
        -> 定义 dp 数组/函数的含义（一般来说，函数参数就是「状态」，值就是题目要求计算的量，如dp[状态]=该状态下最多放多少质量的物品）。
*/

/*  Main函数入口
    int main(){
        Solution ans = Solution();
        vector<int>coins = {2};
        int amount = 3;
        ans.coinChange(coins, amount);
    }
*/