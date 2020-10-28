#include <bits/stdc++.h>

using namespace std;

/*
   @ 编写Solution :  124.h
   @ 主函数入口    :  main.cpp
   @ Author      :  Vodka
   @ Time        :  20-10-28 上午9:38 
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
    int ans = INT_MIN;
    int maxPathSum(TreeNode* root) {
        traverse(root);
        return ans;
    }

    int traverse(TreeNode* root){
        if(root == nullptr) return 0;
        int left = traverse(root->left);
        int right = traverse(root->right);
        ans = max(ans, max(0, max(left, max(right, left+right)))+root->val);
        return max(0, max(left, right))+root->val; // return是没有left+right的，因为如果子树都左右边都有的话就无法和父节点连成路径了
    }
};

/*  解决思路 & 复杂度
    虽说是hard，但实际还是一个树的后续遍历的问题，用一个全局变量维护最长路径值，递归返回的是以每个节点为头节点（不能是 左儿子，自身，右儿子 这样的）的最长路径
    ans在每次迭代维护的是包含该节点的路径的最长路径=max(左儿子的最长路径, 右儿子的最长路径，0)+自身val。
*/

/*  Main函数入口
    ...
*/