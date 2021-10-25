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

// 0����-1��ǰ׺�� + map�洢��һ�γ��ֵ�λ�á� sum[i]==sum[j]��ʱ��i+1~j�ͻᱣ֤sum=0 
