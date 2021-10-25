/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    void build(Node* root, Node*& head, Node*& tail){
        if(root==nullptr)return;
        build(root->left, head, tail);
        if(head==nullptr){
            head = tail = root;
        }else{
            tail->right = root;
            root->left = tail;
            tail = tail->right;
        }
        build(root->right, head, tail);
    }

    Node* treeToDoublyList(Node* root) {
        if(root==nullptr)return nullptr;
        Node* head = nullptr;
        Node* tail = nullptr;
        build(root, head, tail);
        head->left = tail;
        tail->right = head;
        return head;
    }
};
