/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==nullptr)return false;
        ListNode* slow = head;
        ListNode* fast = head->next;
        bool flag_loop = false;
        bool flag_null = false;
        while(slow&&fast){
            if(slow==fast){
                flag_loop = true;
                break;
            }
            if(fast->next==nullptr || fast->next->next==nullptr){
                flag_null = true;
                break;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        if(flag_loop)return true;
        return false;
    }
};
