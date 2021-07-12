class Solution {
public:
    vector<vector<int>>res;

    void dfs(vector<int>& candidates, vector<int>& tmp, int i, int sum, int target){
        if(sum==target){
            res.push_back(tmp);
            return;
        }
        if(sum>target||i>=candidates.size()) return;
        tmp.push_back(candidates[i]);
        dfs(candidates, tmp, i, sum+candidates[i], target);
        tmp.pop_back();
        dfs(candidates, tmp, i+1, sum, target);
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> tmp;
        dfs(candidates, tmp, 0, 0, target);
        return res;
    }
};

// 回溯，为了防止答案顺序不重复，就按位置遍历，如果当前位置还能继续加，那就加；如果不加了，过了，那就再也不会回头来加这个数了。 
