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

// ��򵥵ķ����ǿ���������Ƿ�Ϊ����
// �ѵ�ĵݹ�ķ��������ǻ������������ͬʱ����ǰһ���ڵ����������ֵ����ô ��/��/�� ��������˳��һ���������� ��ǰ�ڵ��ֵ ���� ��һ���ڵ�����ֵ 
