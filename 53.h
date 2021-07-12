class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxn = -99999999;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            maxn = max(maxn, sum);
            if(sum<0)sum=0;
        }
        return maxn;
    }
};
