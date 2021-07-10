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
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        ListNode* head = new ListNode();
        ListNode* res = head;
        for(int i=0;i<lists.size();i++)if(lists[i]!=nullptr)pq.push(lists[i]);
        while(!pq.empty()){
            ListNode* now = pq.top();
            pq.pop();
            head->next = now;
            head = head->next;
            if(now->next)
                pq.push(now->next);
        }
        return res->next;
    }
};

// 最小堆，自动调整当前的最小值。 
