class Solution {
public:
    vector<string> res;

    void dfs(string now, int left, int right, int step, int total){
        if(step>total||right>total||right>left)return;
        if(step==total&&left==right){
            res.push_back(now);
            return;
        }
        dfs(now+'(', left+1, right, step+1, total);
        dfs(now+')', left, right+1, step+1, total);
        return;
    }

    vector<string> generateParenthesis(int n) {
        dfs("(", 1, 0, 1, 2*n);
        return res;
    }
};

// easy dfs 
