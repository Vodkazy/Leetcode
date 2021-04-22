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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>>res;
        if(root==nullptr)return res;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int>tmp;
            for(int i=0;i<size;i++){
                TreeNode* now = q.front();
                q.pop();
                tmp.push_back(now->val);
                if(now->left)q.push(now->left);
                if(now->right)q.push(now->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};

// 简单层次遍历，注意空的情况 
