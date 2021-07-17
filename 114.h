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
    TreeNode* pre = nullptr;

    void pre_visit(TreeNode* root){
        if(root==nullptr)return;
        pre_visit(root->right);
        pre_visit(root->left);
        
        root->right = pre;
        root->left = nullptr;

        pre = root;
        return;
    }

    void flatten(TreeNode* root) {
        pre_visit(root);
        return;
    }
};

// 相当于还是递归，先从上往下思考，要捋直 左子树，root，右子树，需要先捋直左子树和右子树，所以需要先遍历子树再遍历root
// 是先左边还是先右边的？因为root的右边要改变，接到左子树的后边（题目原本是前序遍历），所以需要先右子树再左子树，这样先确定了遍历的顺序 
// 然后在遍历的过程中，具体应该怎么搞？既然是递归，那肯定是自底向上去看，我们如何让root和root的子树产生关系，那就是需要记录一下root的下层访问的元素
// 放到叶子节点来看，先遍历右边，发现是个null，再遍历左边，发现也是个null，于是叶子节点的后续是个null，往回走，先遍历完了右子树，然后需要把右子树的root接到左子树的最后去
// 而在遍历左子树的时候我们发现，左子树最右下角的叶子节点是最先被访问到的，并且应该是左子树最底层的节点，所以就可以用个pre指针记录上一次的节点，把当前节点的后继节点设为前一个节点 
// 然后设置完之后，pre就变成了自己，就又可以返回上一层，接到root后面。
// pre指针的思想在二叉树遍历更改顺序题型中非常实用。 
