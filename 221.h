class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int dp[305][305][2];
        memset(dp,0,sizeof(dp));
        int m = matrix.size();
        int n = matrix[0].size();

        if(matrix[0][0]=='1')dp[0][0][0]=dp[0][0][1]=1;

        for(int i=1;i<m;i++){
            if(matrix[i][0]=='1'){
                dp[i][0][0] = 1;
                dp[i][0][1] = dp[i-1][0][1]+1;
            }
        }
        for(int i=1;i<n;i++){
            if(matrix[0][i]=='1'){
                dp[0][i][1] = 1;
                dp[0][i][0] = dp[0][i-1][0]+1;
            }
        }
        int res = 0;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]=='1'){
                    dp[i][j][0] = dp[i][j-1][0]+1;
                    dp[i][j][1] = dp[i-1][j][1]+1;
                }
            }
        }
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                int len = min(dp[i][j][0], dp[i][j][1]);
                for(int k=1;k<=min(dp[i][j][0],dp[i][j][1]);k++){
                    len = min(len, dp[i][j-k+1][1]);
                    if(len<=k)break;
                }
                res = max(res, len*len);
            }
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<dp[i][j][0]<<" ";
        //     }
        //     cout<<endl;
        // }
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<dp[i][j][1]<<" ";
        //     }
        //     cout<<endl;
        // }
        return res;
    }
};


// DP，和 85最大矩形 类似 
