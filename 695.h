class Solution {
public:
    int maxn = 0;
    int vis[51][51];

    int now_size = 0;

    void dfs(vector<vector<int>>& grid, int x, int y, int n, int m){
        now_size += 1;
        int dir[4][2] = {0,-1,0,1,1,0,-1,0};
        for(int i=0;i<4;i++){
            int dx = x+dir[i][0];
            int dy = y+dir[i][1];
            if(dx<0||dx>=n||dy<0||dy>=m||vis[dx][dy]==1||grid[dx][dy]==0)continue;
            vis[dx][dy] = 1;
            dfs(grid, dx, dy, n, m);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size()==0)return 0;
        memset(vis,0,sizeof(vis));
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1&&!vis[i][j]){
                    vis[i][j] = 1;
                    dfs(grid, i, j, n, m);
                    maxn = max(maxn, now_size);
                    now_size = 0;
                }
            }
        }
        return maxn;
    }
};
