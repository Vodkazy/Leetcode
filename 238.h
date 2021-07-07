class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        
        vector<int>res(n,1);

        int left = 1;
        for(int i=0;i<n;i++){
            res[i] = left;
            left *= nums[i];
        }

        
        int right = 1;
        for(int i=n-1;i>=0;i--){
            res[i] *= right;
            right *= nums[i];
        }

        return res;

    }
};

// 无聊...还限制不能用除法，就左右来回遍历两边即可，时间复杂度O(N)，空间复杂度O(1) 
