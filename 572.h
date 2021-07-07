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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==nullptr && subRoot==nullptr)return true;
        if(root==nullptr && subRoot!=nullptr)return false;
        return (isSametree(root,subRoot) || isSubtree(root->left,subRoot) || isSubtree(root->right, subRoot));
    }

    bool isSametree(TreeNode* a, TreeNode* b){
        if(a==nullptr && b==nullptr)return true;
        if((a==nullptr&&b!=nullptr)||(a!=nullptr&&b==nullptr))return false;
        return (a->val==b->val)&&isSametree(a->left,b->left)&&isSametree(a->right,b->right);
    }
};

// ตÝน้ 
