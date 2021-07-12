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

    int summ = 0;

    void dfs(TreeNode* root, int sum){
        if(root->left==nullptr && root->right==nullptr){
            sum = sum*10 + root->val;
            summ += sum;
            return;
        }
        if(root->right)
            dfs(root->right, sum*10+root->val);
        if(root->left)
        dfs(root->left, sum*10+root->val);
    }

    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return summ;
    }
};
