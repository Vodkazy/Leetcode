#include <bits/stdc++.h>

using namespace std;

/*
   @ 编写Solution :  416.h
   @ 主函数入口    :  main.cpp
   @ Author      :  Vodka
   @ Time        :  20-10-28 下午10:30 
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int dp[10005];
        memset(dp, 0, sizeof(dp));
        int sum = 0;
        for(int i=0;i<nums.size();i++) sum += nums[i];
        if(sum%2!=0)return false;
        int N = sum/2;
        for(int i=0;i<nums.size();i++){
            for(int j=N;j>=nums[i];j--){
                dp[j] = max(dp[j], dp[j-nums[i]]+nums[i]);
            }
        }
        return dp[N]==N;
    }
};


/*  解决思路 & 复杂度
    将题目转化成经典01背包问题，也就是有限个物品能否放满容量为sum/2的背包。
    for(遍历物品){
        for(从最大容量开始，到当前物品){
            更新dp;
        }
    }
*/

/*  Main函数入口
    int main(){
        Solution ans = Solution();
        vector<int>a = {1,5,11,5};
        ans.canPartition(a);
        return 0;
    }
*/