class Solution {
public:
    int m,n;
    int maxn = 0;
    int dp[205][205];
    int vis[205][205];
    int dir[4][2] = {1,0,-1,0,0,1,0,-1};

    void dfs(vector<vector<int>>& matrix, int x, int y, int now_len){
        if( x<0 || x>=m || y<0 || y>=n ) return;
        if( now_len+1 > dp[x][y] ) dp[x][y] = now_len+1;
        maxn = max(maxn, dp[x][y]);
        for(int i=0;i<4;i++){
            int dx = x+dir[i][0];
            int dy = y+dir[i][1];
            if(dx<0||dx>=m||dy<0||dy>=n||(dp[dx][dy]>now_len+1)||(matrix[dx][dy]<=matrix[x][y]))continue;
            else{
                vis[dx][dy] = 1;
                dfs(matrix, dx, dy, dp[x][y]);
            }
        }
        return;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        for(int i=0;i<205;i++)
            for(int j=0;j<205;j++)
                dp[i][j] = 1;
        memset(vis, 0, sizeof(vis));

        m = matrix.size();
        n = matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j])
                    vis[i][j] = 1;
                    dfs(matrix, i, j, 0);
            }
        }
        return maxn;
    }
};

// DFS+¼ÇÒä»¯ËÑË÷ 
