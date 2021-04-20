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

// O(N^2)�����أ�dp[i]�ĺ���Ϊ��iλ��Ϊ��β������ȡ�
// ��0��-1���������fill������ʼ����fill(a,a+n,value) 
// O(NlogN)�ķ�����˼�룬dp[i]��ʾLCSΪi+1�������еĽ�βֵ������ÿ��num[i]����dp������Ҵ�������ֵ���±꣨�ұ߽磩����������num[i]Ϊ��β��LCS�ĳ��� 
