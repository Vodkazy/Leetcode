#include <bits/stdc++.h>

using namespace std;

/*
   @ 编写Solution :  2.h
   @ 主函数入口    :  main.cpp
   @ Author      :  Vodka
   @ Time        :  19-6-21 上午11:38
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *start = new ListNode(0);
        ListNode *p = l1, *q = l2, *cur = start;
        int c = 0;
        while(p!=NULL || q!=NULL){
            int x ;
            if(p!=NULL)x=p->val;
            else x = 0;
            int y ;
            if(q!=NULL)y=q->val;
            else y = 0;
            int ans = c+x+y;
            if(ans>=10){
                c = ans/10;
                ans %= 10;
            }
            else c = 0 ;
            ListNode *t = new ListNode(ans);
            cur->next = t;
            cur = cur->next;
            if(p!=NULL) p = p->next;
            if(q!=NULL) q = q->next;
        }
        if(c>0){
            ListNode *tt = new ListNode(c);
            cur->next = tt;
        }
        return start->next;
    }
};

/*  解决思路 & 复杂度
    由于题目给的链表本来就是倒序存储的，所以可以尝试直接模拟加法的过程，从低位到高位进行运算，逢10进1，若遇到最高位进位，则新建一个node进行存储。
*/

/*  Main函数入口
    int main() {
        Solution ans = Solution();
        ListNode a1 = ListNode(2);
        ListNode a2 = ListNode(4);
        ListNode a3 = ListNode(5);
        a1.next = &a2;
        a2.next = &a3;
        ListNode b1 = ListNode(5);
        ListNode b2 = ListNode(6);
        ListNode b3 = ListNode(4);
        b1.next = &b2;
        b2.next = &b3;
        ListNode* c = ans.addTwoNumbers(&a1,&b1);
        while(true){
            if(c==NULL)break;
            cout<<c->val;
            c = c->next;
        }
        return 0;
    }
*/