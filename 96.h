class Solution {
public:

    int numTrees(int n) {
        int dp[20];
        dp[0] = 1;
        for(int i=1;i<=n;i++){
            int sum = 0;
            for(int j=1;j<=i;j++){
                sum += dp[j-1] * dp[i-j];
            }
            dp[i] = sum;
        }
        return dp[n];
    }
};

// 找规律，每个点为根节点的方案=左子树*右子树。
// G(n) = G(0)*G(n-1)+G(1)*(n-2)+...+G(n-1)*G(0) 
