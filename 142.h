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
    ListNode *detectCycle(ListNode *head) {
        ListNode* pre = new ListNode(0);
        pre->next = head;

        if(head==nullptr||head->next==nullptr)return nullptr;

        ListNode* slow = head->next;
        ListNode* fast = head->next->next; // ����ָ�룬��ָ���ʼ��Ϊhead->next����ָ��Ϊhead->next->next�����һ����head��һ����head->next->next����û���Ǹ������ˡ�

        while(fast!=slow){
            if(fast==nullptr || fast->next==nullptr || fast->next->next==nullptr)return nullptr;
            else{
                fast = fast->next->next;
                slow = slow->next;
            }
        }

        slow = head;

        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
