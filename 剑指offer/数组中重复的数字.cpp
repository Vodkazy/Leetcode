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

# O(N)复杂度，第i大的数应该出现在第i个位置，O(N)遍历数组的同时调整本应该出现在该位置的数值
# 对调法，如果对调的两个数相同，就说明出现了重复数字 
