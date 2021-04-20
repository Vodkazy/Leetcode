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

// dp[i][j]����word1[0..i]��word2[0..j]����Ҫ�����ٱ仯������dp[i][j]��ô���� 
// ������word1[0..i]�任��word2[0..j-1]���ټ�һ�β�����word2[0..j-1]�任��word2[0..j]��Ҳ���ǲ������ 
// Ҳ������word1[0..i-1]�任��word2[0..j]���ټ�һ�β�����word1[0..i]�任��word1[0..i-1]��Ҳ����Ӳ���
// ���п����� word1[0..i-1]�任��word2[0..j-1]��Ȼ�����word1[i]==word2[j]���Ǿ����ã������ٶ��ˣ������word1[i]�滻Ϊword2[j]�� 
