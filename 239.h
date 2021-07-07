class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>res;
        deque<int>dq;
        dq.push_back(0); //注意这里Push的是index，是为了记录最大值是否已经超出窗口
        for(int i=1;i<k;i++){
            while(!dq.empty()&&nums[i]>=nums[dq.back()])dq.pop_back();
            dq.push_back(i);
        }
        res.push_back(nums[dq.front()]);
        for(int i=k;i<nums.size();i++){
            // 每次删除比当前值小的，因为那些必然用不到
            while(!dq.empty()&&nums[i]>=nums[dq.back()])dq.pop_back();
            dq.push_back(i);
            // 如果当前最大值已经出格了，则pop
            while(i-(dq.front())+1>k)dq.pop_front();
            res.push_back(nums[dq.front()]);
        }
        return res;
    }
};

// 练习使用deque，双向队列。front(),back(),pop_front(),pop_back()

// 核心是，窗口内比当前值小的都没用，只有比当前值大，且在窗口内的才有用。 
