class Solution {
public:
    int minDistance(string word1, string word2) {
        int dp[505][505];
        memset(dp,0x3f3f3f3f,sizeof(dp));
        dp[0][0] = 0;
        for(int i=1;i<=word1.length();i++){
            dp[i][0] = i;
        }
        for(int i=1;i<=word2.length();i++){
            dp[0][i] = i;
        }
        for(int i=1;i<=word1.length();i++){
            for(int j=1;j<=word2.length();j++){
                dp[i][j] = min(word1[i-1]==word2[j-1]?dp[i-1][j-1]:dp[i-1][j-1]+1, min(dp[i-1][j]+1, dp[i][j-1]+1));
            }
        }
        return dp[word1.length()][word2.length()];
    }
};

// dp[i][j]，从word1[0..i]到word2[0..j]所需要的最少变化次数，dp[i][j]怎么来？ 
// 可能是word1[0..i]变换到word2[0..j-1]，再加一次操作是word2[0..j-1]变换到word2[0..j]，也就是插入操作 
// 也可能是word1[0..i-1]变换到word2[0..j]，再加一次操作是word1[0..i]变换到word1[0..i-1]，也是添加操作
// 还有可能是 word1[0..i-1]变换到word2[0..j-1]，然后如果word1[i]==word2[j]，那就正好，不用再动了；否则就word1[i]替换为word2[j]。 
