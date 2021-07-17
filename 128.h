 class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxn = 0;
        map<int,int>m; // ��ʾ����key�����������ĳ���value

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

// �о�������Ȼ��O(N)�ķ����ˣ�����map������ÿ��λ�ò�num[i],num[i]+1,...,num[i]+x����󳤶�
// ����ֻ����m��û�еģ��������ǹ����ĵ㣬����ֻҪleft,num[i],right�����ˣ�֮�󶼲������õ��ˣ�����ֻ��Ҫά���߽����󳤶ȼ��ɡ� 
