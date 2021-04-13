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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* pre = new ListNode(0); // 最头上的指针
        pre->next = head;
        ListNode* h = pre;
        
        while(head){
            ListNode* t = h;
            for(int i=0;i<k;i++){
                t = t->next;
                if(t==nullptr)return pre->next;
            }
            ListNode* next_k_head = t->next;

            pair<ListNode*, ListNode*>result = reverse(head,t);
            head = result.first;
            t = result.second;

            h->next = head;
            t->next = next_k_head;

            h = t;
            head = t->next;
        }
        return pre->next;
    }

    pair<ListNode*,ListNode*> reverse(ListNode* head, ListNode* tail){
        ListNode* _end = tail->next;
        ListNode* p = head;
        while (tail!=_end) {
            ListNode* nex = p->next;
            p->next = _end;
            _end = p;
            p = nex;
        }
        return {tail, head};
    }
};

// 非常麻烦的模拟..需要各种注意细节 
