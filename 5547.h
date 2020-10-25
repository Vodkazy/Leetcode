#include <bits/stdc++.h>
/*
   @ 编写Solution :  5547.h
   @ 主函数入口    :  main.cpp
   @ Author      :  Vodka
   @ Time        :  20-10-25 下午4:11 
*/
using namespace std;

class Solution {
public:
    bool judge(vector<int>& now_arr){
        sort(now_arr.begin(), now_arr.end());
        if(now_arr.size()==1)return true;
        int gap = now_arr[1]-now_arr[0];
        for(int i=1;i<now_arr.size();i++){
            if((now_arr[i]-now_arr[i-1]) != gap){
                return false;
            }
        }
        return true;
    }

    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool>res;
        for(int i=0;i<l.size();i++){
            int now_l = l[i];
            int now_r = r[i];
            vector<int>now_arr;
            for(int j=now_l;j<=now_r;j++)now_arr.push_back(nums[j]);
            res.push_back(judge(now_arr));
        }
        for(int i=0;i<res.size();i++)cout<<res[i]<<" ";
        return res;
    }
};


/*  解决思路 & 复杂度
    暴力就可以过...m次查询，每次排个序然后遍历一遍检查下是否等差
*/

/*  Main函数入口
    int main(){
        Solution ans = Solution();
        vector<int> nums = {4,6,5,9,3,7};
        vector<int> l = {0,0,2};
        vector<int> r = {2,3,5};
        ans.checkArithmeticSubarrays(nums, l, r);
        return 0;
    }
*/