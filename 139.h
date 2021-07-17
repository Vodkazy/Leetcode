class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int dp[300005];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1; // len=i
        for(int i=1;i<=s.size();i++){
            for(int j=0;j<i;j++){
                if(dp[j] && find(wordDict.begin(), wordDict.end(), s.substr(j,i-j))!=wordDict.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
   }
};

// һ��ʼ�����ֵ���+dfs�����ǻᳬʱ�������뵽dp[i]��ʾ0~(i-1)���Ӵ��ܲ��ܹ��� 
