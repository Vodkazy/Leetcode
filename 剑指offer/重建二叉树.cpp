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

// ��������ĵ�һ����root������root�����������λ�ÿ��Ի�������������������
// �������������root��ߵ�Ԫ�ظ��������ж�����������н����ŵĶ��ٸ�Ԫ�����������ġ�
// �Ӷ����Ի��ֳ��������������������+����������У��Լ��������ģ����еݹ顣��r<lʱ����ΪNULL�� 
