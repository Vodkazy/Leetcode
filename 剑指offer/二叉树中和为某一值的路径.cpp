/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> res;

    void dfs(TreeNode* root, vector<int> tmp, int sum, int target){
        if(root->left==nullptr && root->right==nullptr && sum+root->val==target){
            tmp.push_back(root->val);
            res.push_back(tmp);
            tmp.pop_back();
            return;
        }
        tmp.push_back(root->val);
        if(root->left)
            dfs(root->left, tmp, sum+root->val, target);
        if(root->right)
            dfs(root->right, tmp, sum+root->val, target);
        tmp.pop_back();
        return;
    }

    vector<vector<int>> pathSum(TreeNode* root, int target) {
        if(root==nullptr)return res;
        vector<int> tmp;
        dfs(root, tmp, 0, target);
        return res;
    }
};
