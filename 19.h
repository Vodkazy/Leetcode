/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr)return nullptr;
        ListNode* dummy_head = new ListNode();
        dummy_head->next = head;
        ListNode* fast = head;
        ListNode* slow = dummy_head;
        for(int i=0;i<n;i++)fast = fast->next;
        while(fast){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummy_head->next;
    }
};

// 快慢指针，利用快慢指针之间相距n，来表达“倒数第n个”的概念 
