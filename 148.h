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
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }

    ListNode* mergeSort(ListNode* head){
        if(head==nullptr || head->next==nullptr)return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=nullptr&&fast->next!=nullptr){ // 找中点
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* right_head = mergeSort(slow->next);
        slow->next = nullptr;
        ListNode* left_head = mergeSort(head);
        return merge(left_head, right_head);
    }

    ListNode* merge(ListNode* l, ListNode* r){
        ListNode* dummy = new ListNode(0);
        ListNode* pre = dummy;
        while(l!=nullptr && r!=nullptr){
            if(l->val < r->val){
                pre->next = l;
                l = l->next;
                pre = pre->next;
            }else{
                pre->next = r;
                r = r->next;
                pre = pre->next;                
            }
        }
        while(l!=nullptr)pre->next=l,l=l->next,pre=pre->next;
        while(r!=nullptr)pre->next=r,r=r->next,pre=pre->next;
        pre->next = nullptr;
        return dummy->next;
    }

};

// 链表版 归并排序，需要通过快慢指针找中点了。并且判断完中点是先mergeSort右半边，再把中点截断next=0，再mergeSort左半边，最后再merge。 
