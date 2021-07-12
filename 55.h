class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxn = 0;
        bool flag = true;
        for(int i=0;i<nums.size();i++){
            if(i>maxn){
                flag = false;
                break;
            }else{
                maxn = max(maxn, i+nums[i]);
            }
        }
        return flag;
    }
};
