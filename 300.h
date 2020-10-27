#include <bits/stdc++.h>
/*
   @ 编写Solution :  300.h
   @ 主函数入口    :  main.cpp
   @ Author      :  Vodka
   @ Time        :  20-10-27 上午9:43 
*/
using namespace std;

class Solution {
public:
//     dp 做法
//    int dp[10005];
//    int lengthOfLIS(vector<int>& nums) {
//        if(nums.size()==0){
//            return 0;
//        }
//        memset(dp, 0, sizeof(dp));
//        int len = nums.size();
//        int maxn = 1;
//        for(int i=0;i<len;i++){
//            dp[i] = 1;
//            for(int j=0;j<i;j++){
//                if(nums[i]>nums[j]){
//                    dp[i] = max(dp[i], dp[j]+1);
//                }
//            }
//            maxn = max(maxn, dp[i]);
//        }
//        return maxn;
//    }

//     贪心+二分 做法
    vector<int>dp; // dp[i]表示长度为i+1的所有LIS的结尾最小值

    int binary_search(vector<int>&dp, int l, int r, int target){ // 二分查找第一个小于target的数
        int left = l, right = r;
        int pos = -1;
        while(left <= right){
            int mid = left + ((right-left)>>1);

            if(dp[mid] >= target){
                right = mid - 1;
            }else{
                left = mid + 1;
                pos = left;
            }
        }
        return pos;
    }

    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        dp = vector<int>(nums.size()+5, 0);
        dp[0] = nums[0];
        int now_len = 1;
        int max_len = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>dp[now_len-1]){
                dp[now_len++] = nums[i];
            }else{
                int _index = binary_search(dp, 0, now_len-1, nums[i]);  // 维护第一个大于nums[i]的dp[i]，不需要把后续的全部更新，因为如果后续有比dp[i]大的数并且比dp[i+1]还小的话，会先更新dp[i+1]，然后再来一个再更新dp[i+2]...
                if(_index == -1){
                    dp[0] = nums[i];
                    continue;
                }
                dp[_index] = nums[i];
            }
        }
        return now_len;
    }
};


/*  解决思路 & 复杂度
    经典最长上升子序列问题，两种做法：
    一种是dp，复杂度O(N^2)维护以nums[i]结尾的最长长度，两层for循环，外层遍历i，内层找i之前的所有节点中dp[i]最大的，转移方程为dp[i]=max(dp[i], dp[j]+1)（if nums[i]>nums[j]）
    另一种是贪心+二分，O(NlogN)，要使子序列最长，就要使得序列上涨的最慢，也就是维护长度为i的最长上升子序列的结尾的最小值dp[i]（它是满足递增性质的），
    具体做法是外层遍历nums，内层在有序dp数组里二分查找第一个nums[i]的数，然后更新dp里第一个大于nums[i]的值，如果没有比nums[i]大的数，就将其置为最小值，这样的话不会产生反向传播影响，因为现有的dp里的数值都是通过以往已经遍历过的数值算出来的
    最终dp能最多有几个元素，就说明最长上升子序列最长有多长。
*/

/*  Main函数入口
    int main(){
        Solution ans = Solution();
        vector<int>nums = {1,3,6,7,9,4,10,5,6};
        ans.lengthOfLIS(nums);
        return 0;
    }
*/