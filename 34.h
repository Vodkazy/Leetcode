class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto a = lower_bound(nums.begin(), nums.end(), target);
        auto b = upper_bound(nums.begin(), nums.end(), target);
        vector<int>res;
        if(a==b){
            res.push_back(-1);
            res.push_back(-1);
        }else{
            res.push_back(a-nums.begin());
            res.push_back(b-nums.begin()-1);
        }
        return res;
    }
};

// ����lower_bound��upper_bound��ȷ������ĳ��ֵ��λ�� 
