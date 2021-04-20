class Solution {
public:
    int vis[305][305];

    void dfs(vector<vector<char>>&grid, int x, int y){
        int dir[4][2] = {0,1,0,-1,-1,0,1,0};
        for(int i=0;i<4;i++){
            int dx = x+dir[i][0];
            int dy = y+dir[i][1];
            if(dx<0||dx>=grid.size()||dy<0||dy>=grid[0].size())continue;
            if(grid[dx][dy]=='1'&&!vis[dx][dy]){
                vis[dx][dy] = 1;
                dfs(grid, dx, dy);
            }
        } 
        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        memset(vis, 0, sizeof(vis));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt += 1;
                    vis[i][j] = 1;
                    dfs(grid, i,j);
                }
            }
        }
        return cnt;
    }
};
