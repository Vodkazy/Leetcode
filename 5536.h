#include <bits/stdc++.h>

using namespace std;

/*
   @ 编写Solution :  5536.h
   @ 主函数入口    :  main.cpp
   @ Author      :  Vodka
   @ Time        :  20-10-11 下午11:02 
*/

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int arr[101];
        bool dis[101][101];
        memset(arr, 0, sizeof(arr));
        memset(dis, 0, sizeof(dis));
        for(int i=0;i<roads.size();i++){
            arr[roads[i][0]] += 1;
            arr[roads[i][1]] += 1;
            dis[roads[i][0]][roads[i][1]] = 1;
            dis[roads[i][1]][roads[i][0]] = 1;
        }
        int max_cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                max_cnt = max(max_cnt, arr[i]+arr[j]-dis[i][j]);
            }
        }
        return max_cnt;
    }
};


/*  解决思路 & 复杂度
    简单题，只需要在一开始遍历的时候统计各点的度数，以及各点对之间的连接情况，最后N^2遍历节点，两点和-两点重叠共有边。
*/

/*  Main函数入口
    int main() {
        Solution ans = Solution();
        vector<vector<int>> roads = {{0,1},{0,3},{1,2},{1,3},{2,3},{2,4}}
        cout<<ans.maximalNetworkRank(5, roads);
        return 0;
    }
*/