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

// 层次遍历看每层是否是回文串，比较坑的是nullptr也得算着占位，但是用什么数来表示它比较玄学。 
// 官方做法好像是递归，看左右子树镜像。其实也是队列，只不过一开始是root,root进队，然后每次下一层是一起取两个，保证处于镜像位置的两个连在一起入队
// 入队的时候是左边的先push左子树，右边的先push右子树，然后左边的右子树，右边的左子树。 
