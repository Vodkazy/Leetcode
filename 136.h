class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int num:nums){
            res = res^num;
        }
        return res;
    }
};

// 按位异或^，满足自己^自己=0，所以必然偶数的都为0，只剩一个奇数。 
