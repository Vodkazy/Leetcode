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

// ��λ���^�������Լ�^�Լ�=0�����Ա�Ȼż���Ķ�Ϊ0��ֻʣһ�������� 
