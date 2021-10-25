class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int res[100005];
        map<int,int>m;
        m[0] = -1;
        int sum = 0;
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)sum-=1;
            else sum+=1;
            res[i] = sum;
            if(m.count(sum)==0){
                m[sum] = i;
            }else{
                ans = max(ans, i - m[sum]);
            }
        }
        return ans;
    }
};

// 0当作-1，前缀和 + map存储第一次出现的位置。 sum[i]==sum[j]的时候，i+1~j就会保证sum=0 
