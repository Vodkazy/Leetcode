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
    ListNode* reverse_rec(ListNode* head){ // 自己写的递归反转指针，慢的一批 
        if(head==nullptr)return head;
        if(head->next==nullptr)return head;
        ListNode* now = reverse(head->next);
        ListNode* las = now;
        while(now->next)now=now->next;
        now->next = head;
        head->next = nullptr;
        return las;
    }
    
    ListNode* reverse_simple(ListNode* head){ // 链表倒序，好恶心
        ListNode* prev = nullptr;
        ListNode* now = head;
        while (now != nullptr) {
            ListNode* nextTemp = now->next;
            now->next = prev;
            prev = now;
            now = nextTemp;
        }
        return prev;
    }

    ListNode* findMiddleNode(ListNode* head){ // 快慢指针找链表中位数
        ListNode* l = head;
        ListNode* r = head;
        while(r->next!=nullptr && r->next->next!=nullptr){
            l = l->next;
            r = r->next->next;
        }
        return l;
    }

    void reorderList(ListNode* head) {
        if(head==nullptr)return;
        ListNode* mm = findMiddleNode(head);
        ListNode* middle = mm->next;
        mm->next = nullptr;
        ListNode* rev_head = reverse_simple(middle);
        
        ListNode* l = head;
        ListNode* r = rev_head;
        while(l!=nullptr && r!=nullptr){
            ListNode* next_l = l->next;
            ListNode* next_r = r->next;
            l->next = r;
            l = next_l;
            r->next = l;
            r = next_r;
        }
    }
};

// 核心思想，先找链表中点，然后后半部分反转，然后合并
// 链表不能像常量那样复制两份..毕竟都是直接面向公用内存操作的 
