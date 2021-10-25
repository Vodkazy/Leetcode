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
    bool isPalindrome(ListNode* head) {
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pre = nullptr;

        while(fast&&fast->next){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* _end = nullptr;
        while(slow){
            ListNode* nex = slow->next;
            slow->next = _end;
            _end = slow;
            slow = nex;
        }

        while(head && _end){
            if(head->val != _end->val)return false;
            head = head->next;
            _end = _end->next;
        }
        return true;
    }
};

// 先找中点，反转后半段，再比较。 
