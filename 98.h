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
    TreeNode* max = nullptr;

    bool isValidBST(TreeNode* root) {
        if(root==nullptr)return true;

        bool flag = true;

        bool flag_left = isValidBST(root->left);
        if( max!=nullptr && root->val <= max->val) flag = false;

        max = root;

        bool flag_right = isValidBST(root->right);
        // if( max!=nullptr && root->val >= max->val) flag = false;

        return(flag_right && flag_left && flag);
    }
};

// 最简单的方法是看中序遍历是否为升序
// 难点的递归的方法，就是还是中序遍历，同时保存前一个节点遍历完的最大值，那么 左/中/右 ，这样的顺序一定还是满足 当前节点的值 大于 上一步节点的最大值 
