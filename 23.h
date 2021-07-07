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

    struct cmp{
        bool operator () (ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return nullptr;

        ListNode head = ListNode(0);

        priority_queue<ListNode*, vector<ListNode*>, cmp> q;

        for(int i=0;i<lists.size();i++)if(lists[i]!=nullptr)q.push(lists[i]);

        ListNode* p = &head;

        while(!q.empty()){
            p->next = q.top();
            p = p->next;
            q.pop();
            if(p->next != nullptr)q.push(p->next);
        }
        return head.next;
    }
};

// 优先队列，同时维护多个ListNode数组指针，每次取优先级最高的，然后动态调整取完之后的数组 
