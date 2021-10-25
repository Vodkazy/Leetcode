class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int dp[20005];
        int cnt[20005];
        fill(dp, dp+nums.size(), 1);
        fill(cnt, cnt+nums.size(), 1);
        int maxn = 0;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(dp[j]+1 > dp[i]){
                        dp[i] = dp[j]+1;
                        cnt[i] = cnt[j];
                    } else if (dp[j]+1 == dp[i]){
                        cnt[i] += cnt[j];
                    }
                }
            }
            maxn = max(maxn, dp[i]);
        }
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            if(dp[i]==maxn){
                ans += cnt[i];
            }
        }

        return ans;
    }
};
