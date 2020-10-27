#include <bits/stdc++.h>
/*
   @ 编写Solution :  222.h
   @ 主函数入口    :  main.cpp
   @ Author      :  Vodka
   @ Time        :  20-10-27 下午2:35 
*/
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};


/*  解决思路 & 复杂度
    简单递归....就这题还medium????
*/

/*  Main函数入口
    ...
*/