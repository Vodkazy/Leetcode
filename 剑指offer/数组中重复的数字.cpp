class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            while(nums[i]!=i){
                if(nums[i]==nums[nums[i]]){
                    return nums[i];
                }
                int temp = nums[i];
                nums[i] = nums[temp];
                nums[temp] = temp;
            }
        }
        return 0;
    }
};

# O(N)���Ӷȣ���i�����Ӧ�ó����ڵ�i��λ�ã�O(N)���������ͬʱ������Ӧ�ó����ڸ�λ�õ���ֵ
# �Ե���������Ե�����������ͬ����˵���������ظ����� 
