class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int r = 0;
        int minn = 100000;
        int now_sum = 0;
        while(l<nums.size()&&r<nums.size()){
            if(l==r){
                now_sum = nums[l];
                if(now_sum>=target){
                    minn = 1;
                    now_sum = 0;
                    l++,r++;
                }
                else{
                    r++;
                    if(r<nums.size()){
                        now_sum += nums[r];
                    }
                }
                continue;
            }
            else{
                if(now_sum>=target){
                    minn = min(minn, r-l+1);
                    now_sum -= nums[l];
                    l++;
                }else{
                    r++;
                    if(r<nums.size()){
                        now_sum += nums[r];
                    }
                }
            }
        }
        if(minn<100000)return minn;
        else return 0;
    }
};

// 滑动窗口，维护当前窗口序列和，然后在左右指针滑动的时候做个判断 
