 class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxn = 0;
        map<int,int>m; // 表示包含key的最大的连续的长度value

        for(int i=0;i<nums.size();i++){
            if(m.count(nums[i])==0){
                int len_left = m.count(nums[i]-1)>0?m[nums[i]-1]:0;
                int len_right = m.count(nums[i]+1)>0?m[nums[i]+1]:0;
                int cur_len = len_right+len_left+1;

                maxn = max(maxn, cur_len);

                m[nums[i]] = cur_len;
                m[nums[i]-len_left] = cur_len;
                m[nums[i]+len_right] = cur_len; 
            }
        }
        return maxn;
    }
};

// 感觉是最自然的O(N)的方法了，利用map来代替每个位置查num[i],num[i]+1,...,num[i]+x的最大长度
// 由于只考虑m中没有的，即现在是孤立的点，所以只要left,num[i],right连上了，之后都不会再用到了，所以只需要维护边界的最大长度即可。 
