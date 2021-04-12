/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* build(vector<int>& preorder, int p_l, int p_r, vector<int>& inorder, int i_l, int i_r){
        if(p_r<p_l || i_r<i_l)return NULL;
        TreeNode* root = new TreeNode(preorder[p_l]);
        int middle = 0;
        for(middle=i_l;middle<i_r;middle++){
            if(inorder[middle]==preorder[p_l]){
                break;
            }
        }
        root->left = build(preorder, p_l+1, p_l+middle-i_l, inorder, i_l, middle-1);
        root->right = build(preorder, p_l+middle-i_l+1, p_r, inorder, middle+1, i_r);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};

// 先序遍历的第一个是root，根据root在中序遍历的位置可以划分左子树和右子树。
// 根据中序遍历中root左边的元素个数可以判断在先序遍历中紧跟着的多少个元素是左子树的。
// 从而可以划分成左子树的先序遍历序列+中序遍历序列，以及右子树的，进行递归。当r<l时代表为NULL。 
