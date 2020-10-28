#include <bits/stdc++.h>

using namespace std;

/*
   @ 编写Solution :  105.h
   @ 主函数入口    :  main.cpp
   @ Author      :  Vodka
   @ Time        :  20-10-28 上午9:58 
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    map<int,int>inMap;

    TreeNode* traverse(vector<int>& preorder, vector<int>& inorder, int preorder_l, int preorder_r, int inorder_l, int inorder_r){
        if(preorder_l > preorder_r || inorder_l > inorder_r){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[preorder_l]);
        int inorder_root = inMap[preorder[preorder_l]];
        int leftChildNum = inorder_root - inorder_l;

        root->left = traverse(preorder, inorder, preorder_l+1, preorder_l+leftChildNum,
                              inorder_l, inorder_root-1);
        root->right = traverse(preorder, inorder, preorder_l+leftChildNum+1, preorder_r,
                               inorder_root+1, inorder_r);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for(int i=0;i<n;i++){
            inMap[inorder[i]] = i;
        }
        return traverse(preorder, inorder, 0, n-1, 0, n-1);
    }
};


/*  解决思路 & 复杂度
    经典的 用先序+中序 建树，递归的思想。
    我们考虑最初的情况，在先序里，根节点一定是最先被访问的，也就是[根节点， [左子树], [右子树]]
    在中序里，根节点一定是最中间的，在根节点左边的一定是它的左子树，右边的是右子树，也就是[[左子树], 根节点， [右子树]]
    那么我们可以根据先序来顺序枚举子树的根节点root，那么在中序序列里root左边的一定是左子树，那么左子树的节点个数m就可以知道了
    然后再拿这个节点个数m去先序里面找紧跟着root的m个节点，那么左子树的先序+中序就可以得到了，剩下的就是右子树的先序+中序
    这样的话再以左子树为最初的情况，可以发现是一样的流程，从而可以用递归的方法去做，终止条件就是区间为负（用两个int模拟子树区间边界选取）
*/

/*  Main函数入口
    ...
*/