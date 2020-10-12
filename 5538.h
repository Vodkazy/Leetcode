#include <bits/stdc++.h>
/*
   @ 编写Solution :  5538.h
   @ 主函数入口    :  main.cpp
   @ Author      :  Vodka
   @ Time        :  20-10-11 下午11:36 
*/
using namespace std;

class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        #define inf 0x3f3f3f3f
        int dis[16][16];
        memset(dis, inf ,sizeof(dis));
        for(int i=0;i<n;i++){
            dis[i][i] = 0;
        }
        int dp[(1<<n)+1]; // 表示子树k的最大距离,k表示成二进制，从右数第i位为1表示第i个节点在子集中，为0表示不在
        memset(dp, 0 ,sizeof(dp));

        for(int i=0;i<edges.size();i++){
            dis[edges[i][0]-1][edges[i][1]-1] = 1;
            dis[edges[i][1]-1][edges[i][0]-1] = 1;
            dp[(1<<(edges[i][0]-1)) + (1<<(edges[i][1]-1))] = 1; // 直连的两边最小距离为1
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dis[i][k]!=inf && dis[k][j]!=inf && dis[i][j] > dis[i][k] + dis[k][j]){
                        dis[i][j] = dis[i][k] + dis[k][j];
                        dis[j][i] = dis[i][k] + dis[k][j];
                    }
                }
            }
        }

        for(int k=1;k<(1<<n);k++){ // 枚举每个子集
            if(dp[k]==0)continue;
            // 把节点i加入到子树k中，从子树k扩展到子树k+(1<<i)
            for(int i=0;i<n;i++){
                if(((1<<i)&k)!=0 || dp[k+(1<<i)]!=0)continue; // i本身在子树k中，或者k+(1<<i)已经被计算过了
                for(int j=0;j<n;j++){ // 遍历子树k中是否有和i直接相连的点
                    if(((1<<j)&k)!=0 && dis[i][j]==1){
                        dp[k+(1<<i)] = dp[k];
                        break;
                    }
                }
                if(dp[k+(1<<i)] == 0) continue; // i和子树k不连通
                for(int j=0;j<n;j++){ // 更新子树k的最大距离，只需计算i和k中每个节点的最大距离即可
                    if(((1<<j)&k)!=0){
                        dp[k+(1<<i)] = max(dp[k+(1<<i)], dis[i][j]);
                    }
                }
            }
        }
        vector<int> ans(n-1, 0);
        for(int i=0;i<(1<<n);i++){
            if(dp[i]!=0) ans[dp[i]-1]++;
        }
        return ans;
    }
};


/*  解决思路 & 复杂度
 考虑到n≤15：看到状态有限集合、看到数比较小->想到状态压缩dp
 节点编号0base [0, n-1]。然后设dp[k]表示k所对应的二进制状态所代表的子集的最大距离。
 例如，k=5=101(二进制)，就代表0号和2号节点组成的子集。

 由于某些节点子集并不能构成一棵子树（因为不连通），因此对于这样的子集，我们标记 dp[k]=∞。

 如何不重不漏的统计子树呢？
 其实就是遍历所有状态。设子树的状态为k0，那么每一次更新都是遍历所有非子树内部顶点是不是这个子树的邻接顶点。
 也就是是否与这个子树中的某个点直接相连，即遍历是否存在i使得dist[i][k \in k0]=1。
 若不存在，那么说明没有其他节点和该状态子树相连，因此直接挂掉。
 否则的话，就可以用子树k的状态去更新子树k+(1<<i)的状态，后者的状态就是 自身 和 i和子树中节点的最大距离

 由于两点数量<=15，可以直接Floyd算出所有点对的距离。

 ！！！ 注意在用按位&|^的时候，一定要加()... ((1<<j)&k)!=0 和 (1<<j)&k!=0 是不一样的...
 ！！！ 我就因为这个卡了一个多小时，长教训了
*/

/*  Main函数入口
    int main(){
        Solution ans = Solution();
        vector<vector<int>> edges = {{1,2},{2,3},{2,4}};
        vector<int> ans_vec = ans.countSubgraphsForEachDiameter(4, edges);
        // for(int i=0;i<ans_vec.size();i++)
            // cout<< ans_vec[i] <<endl;
        return 0;
    }
*/