#include <bits/stdc++.h>

using namespace std;

/*
   @ 编写Solution :  198.h
   @ 主函数入口    :  main.cpp
   @ Author      :  Vodka
   @ Time        :  20-10-28 下午4:50 
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)return 0;
        if(nums.size()==1)return nums[0];
        int dp[405][3];
        memset(dp, 0, sizeof(dp));
        dp[1][0] = 0;
        dp[1][1] = nums[0];
        for(int i=2;i<=nums.size();i++){
            dp[i][0] = max(dp[i-1][1], dp[i-1][0]);
            dp[i][1] = dp[i-1][0]+nums[i-1];
        }
        return max(dp[nums.size()][0],dp[nums.size()][1]);
    }
};


/*  解决思路 & 复杂度
    dp[i][0 or 1]代表，偷前i家里，第i家偷/不偷的情况下的最大值。由于“相邻两家不能偷”是对前一个状态的选取有限制作用，所以把偷还是不偷当作一个维度可以更加直观地检查是否满足约束。
*/

/*  Main函数入口
    int main(){
        vector<int> nums = {1,2,3,1};
        Solution ans = Solution();
        ans.rob(nums);
        return 0;
    }
*/