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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* endA = headA;
        ListNode* endB = headB;
        int lenA = 0;
        int lenB = 0;
        while(endA!=nullptr){
            lenA ++;
            endA = endA->next;
        }
        while(endB!=nullptr){
            lenB ++;
            endB = endB->next;
        }
        endA = headA, endB = headB;
        if(lenA>lenB){
            for(int i=0;i<lenA-lenB;i++){
                endA = endA->next;
            }
            while(endA!=nullptr){
                if(endA==endB) return endA;
                endA = endA->next;
                endB = endB->next;
            }
        }else{
            for(int i=0;i<lenB-lenA;i++){
                endB = endB->next;
            }
            while(endA!=nullptr){
                if(endA==endB) return endA;
                endA = endA->next;
                endB = endB->next;
            }
        }
        return nullptr;
    }
};
