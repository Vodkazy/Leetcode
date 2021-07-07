class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int dp[100005][2];
        memset(dp,0,sizeof(dp));

        if(nums.size()==0)return 0;

        int n = nums.size();

        dp[0][0] = dp[0][1] = nums[0];

        int maxn = nums[0];

        for(int i=1;i<n;i++){
            dp[i][0] = min(dp[i-1][0]*nums[i], min(dp[i-1][1]*nums[i], nums[i]));
            dp[i][1] = max(dp[i-1][0]*nums[i], max(dp[i-1][1]*nums[i], nums[i]));
            maxn = max(maxn, dp[i][1]);
        }

        return maxn;

    }
};

// ��dp����ǰλ�õ�ֵ��ǰһλ�õ�����ֵ �� ��ǰλ�õ�ֵ ���� 
