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
    int maxDepth(TreeNode* root) {
        int maxn = 0;
        if(root==nullptr)return 0;

        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root,1));
        while(!q.empty()){
            pair<TreeNode*, int> p = q.front();
            maxn = max(maxn, p.second);
            q.pop();
            if(p.first->left!=nullptr){
                q.push(make_pair(p.first->left, p.second+1));
            }
            if(p.first->right!=nullptr){
                q.push(make_pair(p.first->right, p.second+1));
            }
        }

        return maxn;

    }
};
