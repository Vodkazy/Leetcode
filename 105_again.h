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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0||inorder.size()==0)return nullptr;
        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }

    TreeNode* build(vector<int>& preorder, int p_l, int p_r, vector<int>& inorder, int i_l, int i_r){
        if(p_l>p_r || i_l>i_r) return nullptr;
        TreeNode* root = new TreeNode(preorder[p_l]);
        auto p_index = find(inorder.begin(), inorder.end(), preorder[p_l]);
        int pos = p_index-inorder.begin();
        root->left = build(preorder, p_l+1, p_l+pos-i_l, inorder, i_l, pos-1);
        root->right = build(preorder, p_l+pos-i_l+1, p_r, inorder, pos+1, i_r);
        return root;
    }
};
