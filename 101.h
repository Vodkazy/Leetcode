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
    bool check(vector<int>& vec){
        int n = vec.size();
        for(int i=0;i<n/2;i++){
            if(vec[i]!=vec[n-1-i])return false;
        }
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)return true;
        queue<TreeNode*>q;
        q.push(root);
        int cnt = 0;
        while(!q.empty()){
            cnt ++;
            int size = q.size();
            vector<int> tmp;
            int cnt_null = 0;
            for(int i=0;i<size;i++){
                TreeNode* top = q.front();
                if(top==nullptr){
                    cnt_null ++;
                    tmp.push_back(0x3f3f3f3f);
                    q.push(nullptr);
                    q.push(nullptr);
                }else{
                    tmp.push_back(top->val);
                    q.push(top->left);
                    q.push(top->right);
                }
                q.pop();
            }
            if(cnt_null==size)break;
            // cout<<cnt<<" "<<check(tmp)<<" "<<q.size()<<endl;
            if(!check(tmp))return false;
        }
        return true;
    }
};

// ��α�����ÿ���Ƿ��ǻ��Ĵ����ȽϿӵ���nullptrҲ������ռλ��������ʲô������ʾ���Ƚ���ѧ�� 
// �ٷ����������ǵݹ飬����������������ʵҲ�Ƕ��У�ֻ����һ��ʼ��root,root���ӣ�Ȼ��ÿ����һ����һ��ȡ��������֤���ھ���λ�õ���������һ�����
// ��ӵ�ʱ������ߵ���push���������ұߵ���push��������Ȼ����ߵ����������ұߵ��������� 
