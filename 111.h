#include <bits/stdc++.h>

using namespace std;

/*
   @ 编写Solution :  111.h
   @ 主函数入口    :  main.cpp
   @ Author      :  Vodka
   @ Time        :  20-10-28 下午2:45 
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        while(!q.empty())q.pop();
        pair<TreeNode*, int>head = make_pair(root, 1);
        q.push(head);
        int ans = 0;
        while(!q.empty()){
            pair<TreeNode*, int> now_node = q.front();
            q.pop();
            if(now_node.first==nullptr){
                continue;
            }
            if(now_node.first->left==nullptr && now_node.first->right==nullptr){
                ans = now_node.second;
                break;
            }
            pair<TreeNode*, int> new_node1 = make_pair(now_node.first->left, now_node.second+1);
            q.push(new_node1);
            pair<TreeNode*, int> new_node2 = make_pair(now_node.first->right, now_node.second+1);
            q.push(new_node2);
        }
        return ans;
    }
};


/*  解决思路 & 复杂度
    bfs，层次遍历，遇到第一个叶子节点break即可。
*/

/*  Main函数入口
    ...
*/