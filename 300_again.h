class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int dp[2505];
        fill(dp,dp+2505,1);
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j])dp[i]=max(dp[i],dp[j]+1);
            }
        }
        int maxn = 0;
        for(int i=0;i<nums.size();i++)maxn=max(maxn,dp[i]);
        return maxn;
    }
}; // O(N^2)

class Solution {
public:
    int binary_search(int dp[], int target, int len){
        if(len==0)return 0;
        int l = 0;
        int r = len;
        while(l<r){
            int mid = (l+r)>>1;
            if(dp[mid]==target){
                return mid;
            }
            else if(dp[mid]>target){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        return l;
    }    

    int lengthOfLIS(vector<int>& nums) {
        int dp[2505];
        memset(dp,0,sizeof(dp));
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            int index = binary_search(dp, nums[i], cnt);
            dp[index] = nums[i];
            if(index==cnt)cnt++;
        }
        return cnt;
    }
}; // O(NlogN)

// O(N^2)很朴素，dp[i]的含义为以i位置为结尾的最长长度。
// 非0、-1、无穷大，用fill函数初始化，fill(a,a+n,value) 
// O(NlogN)的方法的思想，dp[i]表示LCS为i+1的子序列的结尾值，对于每个num[i]二分dp数组查找大于它的值的下标（右边界），即代表以num[i]为结尾的LCS的长度 
