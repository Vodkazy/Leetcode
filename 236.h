/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
//  方法1：dfs，判断pq是否存在于子树 
class Solution {
public:
    TreeNode* ans;

    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return false;
        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);
        if(lson && rson) ans = root;
        if((root->val==p->val || root->val==q->val) && (lson || rson)) ans = root;
        return lson || rson || (root->val == p->val || root->val == q->val);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }
};



//  方法2：并查集，存储每个节点的祖先 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        map<TreeNode*, TreeNode*>pre;
        pre[root] = root;
        stack<TreeNode*>que;
        que.push(root);
        while(!que.empty()){
            TreeNode* now = que.top();
            que.pop();
            if(now->left){
                pre[now->left] = now;
                que.push(now->left);
            }
            if(now->right){
                pre[now->right] = now;
                que.push(now->right);
            }
        }
        vector<TreeNode*>pre_p;
        TreeNode* now_p = p;
        while(now_p!=root){
            pre_p.push_back(now_p);
            now_p = pre[now_p];
        }
        pre_p.push_back(root);

        vector<TreeNode*>pre_q;
        TreeNode* now_q = q;
        while(now_q!=root){
            pre_q.push_back(now_q);
            now_q = pre[now_q];
        }
        pre_q.push_back(root);

        TreeNode* ans ;
        for(int i=0;i<pre_p.size();i++){
            bool flag = false;
            for(int j=0;j<pre_q.size();j++){
                if(pre_p[i]==pre_q[j]){
                    ans = pre_p[i];
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        return ans;
    }
}; 
