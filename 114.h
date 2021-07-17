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
    TreeNode* pre = nullptr;

    void pre_visit(TreeNode* root){
        if(root==nullptr)return;
        pre_visit(root->right);
        pre_visit(root->left);
        
        root->right = pre;
        root->left = nullptr;

        pre = root;
        return;
    }

    void flatten(TreeNode* root) {
        pre_visit(root);
        return;
    }
};

// �൱�ڻ��ǵݹ飬�ȴ�������˼����Ҫ��ֱ ��������root������������Ҫ����ֱ����������������������Ҫ�ȱ��������ٱ���root
// ������߻������ұߵģ���Ϊroot���ұ�Ҫ�ı䣬�ӵ��������ĺ�ߣ���Ŀԭ����ǰ���������������Ҫ������������������������ȷ���˱�����˳�� 
// Ȼ���ڱ����Ĺ����У�����Ӧ����ô�㣿��Ȼ�ǵݹ飬�ǿ϶����Ե�����ȥ�������������root��root������������ϵ���Ǿ�����Ҫ��¼һ��root���²���ʵ�Ԫ��
// �ŵ�Ҷ�ӽڵ��������ȱ����ұߣ������Ǹ�null���ٱ�����ߣ�����Ҳ�Ǹ�null������Ҷ�ӽڵ�ĺ����Ǹ�null�������ߣ��ȱ���������������Ȼ����Ҫ����������root�ӵ������������ȥ
// ���ڱ�����������ʱ�����Ƿ��֣������������½ǵ�Ҷ�ӽڵ������ȱ����ʵ��ģ�����Ӧ������������ײ�Ľڵ㣬���ԾͿ����ø�preָ���¼��һ�εĽڵ㣬�ѵ�ǰ�ڵ�ĺ�̽ڵ���Ϊǰһ���ڵ� 
// Ȼ��������֮��pre�ͱ�����Լ������ֿ��Է�����һ�㣬�ӵ�root���档
// preָ���˼���ڶ�������������˳�������зǳ�ʵ�á� 
