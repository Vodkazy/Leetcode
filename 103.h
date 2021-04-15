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
            //返回true时，说明a与b之间的大小 和 T本身的比较运算一致
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

// 就是一个层次遍历，然后每层BFS维护一个先进后出的堆。
// 同时维护一个从哪边开始的flag，每一行遍历完之后!flag一下。
// 尼玛的我又读错题了，以为给的树是个完全二叉树，结果自己手动用堆维护了一个三元组。。。
// 核心难想的是怎么在每层遍历完之后换行。（我一开始以为是完全二叉树然后就用“完全二叉树节点个数为2^k-1”去做了。。。）
// 最终的方案是，while里每一次循环由遍历每个节点，改为，遍历每一层。
// 相当于在每一层遍历一开始的时候，这时候还没有添加下一层的任何节点，所以可以直接计算当前堆里有几个节点，来直接确定这层遍历几次。 
