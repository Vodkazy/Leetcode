class Solution {
public:
    vector<vector<int>> res;

    void dfs(vector<int>& nums, int i, vector<int>& temp){
        if(i==nums.size()){
            res.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        dfs(nums, i+1, temp);
        temp.pop_back();
        dfs(nums, i+1, temp);

        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        dfs(nums, 0, temp);
        return res;
    }
};
