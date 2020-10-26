#include <bits/stdc++.h>
/*
   @ 编写Solution :  209.h
   @ 主函数入口    :  main.cpp
   @ Author      :  Vodka
   @ Time        :  20-10-26 下午11:02 
*/
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size()==0)return 0;
        int l=0, r=0;
        int len = nums.size();
        int sum = 0;
        int min_len = 999999;
        while(r>=0 && r<len && l>=0 && l<len){
            sum += nums[r];
            while(sum>=s){
                min_len = min(min_len, r-l+1);
                sum -= nums[l];
                l++;
            }
            r++;
        }
        // cout<<min_len;
        if (min_len != 999999)
            return min_len;
        return 0;
    }
};


/*  解决思路 & 复杂度
    双指针滑动窗口，通过l和r的移动，维护满足sum>=s区间，同时不断计算最小区间长度。
*/

/*  Main函数入口
    int main(){
        int s=7;
        vector<int>nums = {2,3,1,2,4,3};
        Solution ans = Solution();
        ans.minSubArrayLen(s,nums);
        return 0;
    }
*/