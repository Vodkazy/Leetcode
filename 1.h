#include <bits/stdc++.h>
/*
   @ 编写Solution :  1.h
   @ 主函数入口    :  main.cpp
   @ Author      :  Vodka
   @ Time        :  19-6-20 上午10:59
*/
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]] = i+1;
        }
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(m[target-nums[i]]&&i!=m[target-nums[i]]-1){
                ans.push_back(i);
                ans.push_back(m[target-nums[i]]-1);
                return  ans;
            }
        }
    }
};


/*  解决思路 & 复杂度
    由于题目保证了没有重复元素，所以可以直接在读入的时候先用hash的办法为每个值做个索引
    那么当我再遍历一遍的时候的时候 我就可以直接判断 “target-当前值” 的这个值是否存在(并且不能是本身)
    时间复杂度 O(n)
*/

/*  Main函数入口
    int main() {
        Solution ans = Solution();
        vector<int>v = {2,7,11,15};
        int target = 9;
        vector<int>w = ans.twoSum(v,target);
        cout<<w[1]<<" "<<w[2]<<endl;
        return 0;
    }
*/