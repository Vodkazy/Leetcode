class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m==0)return 0;
        int n = matrix[0].size();
        int maxn = 0;
        int dp[205][205][2]; // 第一维表示向左最多多宽，第二维表示向上最多多长
        memset(dp,0,sizeof(dp));

        if(matrix[0][0]=='1'){
            dp[0][0][0] = 1;
            dp[0][0][1] = 1;
            maxn = 1;
        }

        for(int i=1;i<n;i++){
            if(matrix[0][i]=='1'){
                dp[0][i][0] = dp[0][i-1][0]+1;
                dp[0][i][1] = 1;
            }
            maxn = max(maxn,dp[0][i][0]);
        }

        for(int i=1;i<m;i++){
            if(matrix[i][0]=='1'){
                dp[i][0][0] = 1;
                dp[i][0][1] = dp[i-1][0][1]+1;
            }
            maxn = max(maxn,dp[i][0][1]);
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]=='1'){
                    dp[i][j][0] = dp[i][j-1][0]+1;
                    dp[i][j][1] = dp[i-1][j][1]+1;
                    // maxn = max(dp[i][j][0]*dp[i][j][1], maxn);
                    int width = dp[i][j][0];
                    int height = dp[i][j][1];
                    int minHeight = height;
                    for(int k=1;k<=width;k++){
                        minHeight = min(minHeight, dp[i][j-k+1][1]);
                        maxn = max(maxn, k*minHeight);
                    }
                }
            }
        }
        return maxn;
    }
};

// DP，维护三维向量，分别看每个位置横向和纵向最长有几个1连着 
// 然后在每个位置的时候，以最下边一排为底，看每一个矩形的高最高是多少 
