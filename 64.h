class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int dp[205][205];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = grid[0][0];

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(i==0&&j==0)continue;
                int minn = 999999;
                if(i-1>=0)minn=min(minn,dp[i-1][j]);
                if(j-1>=0)minn=min(minn,dp[i][j-1]);
                dp[i][j] = minn + grid[i][j];
            }
        }
        
        return dp[grid.size()-1][grid[0].size()-1];
    }
};
