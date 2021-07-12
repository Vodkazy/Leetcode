class Solution {
public:

    int uniquePaths(int m, int n) {
        int dp[101][101];
        memset(dp, 0, sizeof(dp));
        dp[0][0]=1;
        for(int i=0;i<m;i++)dp[i][0]=1;
        for(int i=0;i<n;i++)dp[0][i]=1;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

// 简单dp，一开始没算好复杂度以为dfs能过的，结果T了 
// 当搜索过程有重复子结构的时候，用dp。记忆式搜索。 

class Solution {
public:
    int cnt = 0;
    
    int vis[101][101];

    void dfs(int i, int j, int m, int n){
        if(i==m && j==n){
            cnt++;
            return;
        }
        if(i+1<=m && !vis[i+1][j]){
            vis[i+1][j] = 1;
            dfs(i+1, j, m, n);
            vis[i+1][j] = 0;
        }
        if(j+1<=n && !vis[i][j+1]){
            vis[i][j+1] = 1;
            dfs(i, j+1, m, n);
            vis[i][j+1] = 0;
        }
        return;
    }

    int uniquePaths(int m, int n) {
        memset(vis, 0, sizeof(vis));
        vis[0][0] = 1;
        dfs(0,0,m-1,n-1);
        return cnt;
    }
};
