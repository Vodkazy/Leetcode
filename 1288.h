#include <bits/stdc++.h>

using namespace std;

/*
   @ 编写Solution :  1288.h
   @ 主函数入口    :  main.cpp
   @ Author      :  Vodka
   @ Time        :  20-10-28 下午6:56 
*/

class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b){
        if(a[0]==b[0])
            return b[1]<a[1];
        return a[0]<b[0];
    }

    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int cnt = 0;
        sort(intervals.begin(), intervals.end(), cmp);
        // for(int i=0;i<intervals.size();i++){
        //     cout<<intervals[i][0]<< " " << intervals[i][1] << endl;
        // }
        int l = intervals[0][0];
        int r = intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            int query_l = intervals[i][0];
            int query_r = intervals[i][1];
            if(query_l >= l && query_r <= r){
                cnt ++;
            }
            if((query_l <= r && query_r >= r) || (query_l >= r)){
                l = query_l;
                r = query_r;
            }
        }
        return intervals.size()-cnt;
    }
};


/*  解决思路 & 复杂度
    区间排序问题，套路都是对区间按照“起点升序、终点降序”的原则进行排序，然后用个双指针维护当前大区间的左端点和右端点。
    本题分为三种情况，若[1,4]和[2,3]则直接后者被包含；[1,4]和[2,5]交叉，或者像[1,2]和[2,4]不交叉的，直接区间更新成后者（因为排序过的，后续区间的起点必然>=2，终点>=5）。
*/

/*  Main函数入口
    int main(){
        Solution ans = Solution();
        vector<int>a1 = {1,4};
        vector<int>a2 = {3,6};
        vector<int>a3 = {2,8};
        vector<vector<int>>intervals = {a1,a2,a3};
        ans.removeCoveredIntervals(intervals);
        return 0;
    }
*/