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

    struct cmp {
        bool operator()(pair<pair<TreeNode*,int>,int>a, pair<pair<TreeNode*,int>,int>b) {
            //����trueʱ��˵��a��b֮��Ĵ�С �� T����ıȽ�����һ��
            if(a.first.second>b.first.second) return true;
            else if(a.first.second==b.first.second){
                if(a.second<b.second)return true;
                return false;
            }
            return false;
        }
    };

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==nullptr){
            vector<vector<int>>tmp;
            return tmp;
        }
        priority_queue<pair<pair<TreeNode*,int>,int>, vector<pair<pair<TreeNode*,int>,int>>, cmp>s;
        s.push(make_pair(make_pair(root,0), 0));
        vector<vector<int>>res;
        bool flag = false;
        int vis[10005];
        memset(vis,0,sizeof(vis));
        int cnt = 0;
        int cntt = 1;
        while(!s.empty()){
            int len = s.size();
            for(int i=0;i<len;i++){
                cnt ++;

                pair<pair<TreeNode*,int>,int> now = s.top();
                s.pop();
                if(now.first.first==nullptr)continue;

                if(!vis[now.first.second]){
                    vector<int> tmp;
                    res.push_back(tmp);
                }
                vis[now.first.second] = 1;
                res[now.first.second].push_back(now.first.first->val);
                if(flag){
                    // cout<<"111"<<endl;
                    s.push(make_pair(make_pair(now.first.first->right,now.first.second+1),cntt++));
                    s.push(make_pair(make_pair(now.first.first->left,now.first.second+1),cntt++));
                }else{
                    // cout<<"222"<<endl;
                    s.push(make_pair(make_pair(now.first.first->left, now.first.second+1),cntt++));
                    s.push(make_pair(make_pair(now.first.first->right, now.first.second+1),cntt++));
                }
                // cout<<now.first.first->val<<" "<<cnt<<endl;
            }
            flag=!flag;
        }
        return res;
    }
};

// ����һ����α�����Ȼ��ÿ��BFSά��һ���Ƚ�����Ķѡ�
// ͬʱά��һ�����ı߿�ʼ��flag��ÿһ�б�����֮��!flagһ�¡�
// ��������ֶ������ˣ���Ϊ�������Ǹ���ȫ������������Լ��ֶ��ö�ά����һ����Ԫ�顣����
// �������������ô��ÿ�������֮���С�����һ��ʼ��Ϊ����ȫ������Ȼ����á���ȫ�������ڵ����Ϊ2^k-1��ȥ���ˡ�������
// ���յķ����ǣ�while��ÿһ��ѭ���ɱ���ÿ���ڵ㣬��Ϊ������ÿһ�㡣
// �൱����ÿһ�����һ��ʼ��ʱ����ʱ��û�������һ����κνڵ㣬���Կ���ֱ�Ӽ��㵱ǰ�����м����ڵ㣬��ֱ��ȷ�����������Ρ� 
