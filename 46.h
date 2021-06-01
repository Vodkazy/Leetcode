class Solution {
public:
    int vis[7];
    vector<vector<int>> res;

    void dfs(vector<int>& nums, vector<int>& ans, int dep){
        if(dep==nums.size()){
            res.push_back(ans);
        }
        for(int i=0;i<nums.size();i++){
            if(!vis[i]){
                vis[i] = 1;
                ans.push_back(nums[i]);
                dfs(nums, ans, dep+1);
                ans.pop_back();
                vis[i] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ans;
        memset(vis,0,sizeof(vis));
        dfs(nums, ans, 0);
        return res;
    }
};

// 简单回溯，进入下一状态前锁定当前状态，回来之后解除锁定。 
