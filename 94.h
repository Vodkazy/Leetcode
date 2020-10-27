#include <bits/stdc++.h>
/*
   @ 编写Solution :  94.h
   @ 主函数入口    :  main.cpp
   @ Author      :  Vodka
   @ Time        :  20-10-27 下午3:13 
*/
using namespace std;

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
    vector<int> ans;

    void dfs(TreeNode* root){
        if(root == nullptr){
            return;
        }
        dfs(root->left);
        ans.push_back(root->val);
        dfs(root->right);
        return;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return ans;
    }
};


/*  解决思路 & 复杂度
    略
*/

/*  Main函数入口
    ...
*/