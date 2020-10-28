#include <bits/stdc++.h>

using namespace std;

/*
   @ 编写Solution :  455.h
   @ 主函数入口    :  main.cpp
   @ Author      :  Vodka
   @ Time        :  20-10-6 下午8:29 
*/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int _index = g.size()-1;
        int cnt = 0;
        for(int i = s.size()-1; i >= 0; i--){
            for(int j = _index; j >= 0; j--){
                if(g[j] <= s[i]){
                    cnt += 1;
                    _index = j-1;
                    break;
                }
            }
        }
        return cnt;
    }
};

/*  解决思路 & 复杂度
    贪心，为每个饼干找它所能满足的最大的孩子饥饿度，物尽其用即可。
*/

/*  Main函数入口
    int main() {
        Solution ans = Solution();
        vector<int> g = {1,2,3};
        vector<int>s = {1,1};
        cout<<ans.findContentChildren(g,s);
        return 0;
    }
*/