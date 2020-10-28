#include <bits/stdc++.h>

using namespace std;

/*
   @ 编写Solution :  121.h
   @ 主函数入口    :  main.cpp
   @ Author      :  Vodka
   @ Time        :  20-10-28 下午3:26 
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
//        滑动窗口维护
//        if(prices.size()==0 || prices.size()==1)return 0;
//        int minn = prices[0];
//        int maxn = 0;
//        for(int i=1;i<prices.size();i++){
//            int gap = prices[i]-minn;
//            maxn = max(maxn, gap);
//            minn = min(minn, prices[i]);
//        }
//        return maxn;


//        dp状态转移
        if(prices.size()==0)return 0;
        int dp[100005][2]; // 第二维的 0 1 代表目前有无股票
        memset(dp,0,sizeof(dp));
        for(int i=0;i<prices.size();i++){
            if(i==0){
                dp[i][0] = 0;
                dp[i][1] = -prices[i]; //当天买入之后应该是亏本的
                continue;
            }
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]); //两种来源，一种是前一天也没股票，今天也没操作；另一种是前一天持有，今天卖了
            dp[i][1] = max(-prices[i], dp[i-1][1]); //两种来源，一种是今天刚买入；一种是昨天也持有
        }
        return dp[prices.size()-1][0];
    }
};


/*  解决思路 & 复杂度
    维护一个最小值，遍历的时候，维护 当前节点与当前最小值的最大差距（认为是在当前最小值时买入，当前节点差距最大时卖出；如果当前节点比之前的最小值还小，那就在当前节点买入）
    也可以拿dp做，dp[i][0 or 1]表示第i天持有/未持有股票的最大收益
*/

/*  Main函数入口
    int main(){
        vector<int>prices = {7,1,5,3,6,4};
        Solution ans = Solution();
        ans.maxProfit(prices);
    }
*/