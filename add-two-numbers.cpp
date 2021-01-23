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
    private:
    ListNode * addingTwoNumber(ListNode* l1, ListNode* l2,int cary)
    {
        if( l1 && l2)
        {
            int tmp = l1->val + l2->val + cary;
            cary =0;
            ListNode * cur=NULL;
            if(tmp > 9)
            {
                cur = new ListNode(tmp%10);
                cary = 1;
            }
            else
            {
                cur = new ListNode(tmp);
            }
            cur->next = addingTwoNumber(l1->next,l2->next,cary);
            return cur;
        }
        if(l1)
        {
            int tmp = l1->val + cary;
            cary =0;
            ListNode * cur=NULL;
            if(tmp > 9)
            {
                cur = new ListNode(tmp%10);
                cary = 1;
            }
            else
            {
                cur = new ListNode(tmp);
            }
            cur->next = addingTwoNumber(l1->next,NULL,cary);
            return cur;
        }
        if(l2)
        {
            int tmp = l2->val + cary;
            cary =0;
            ListNode * cur=NULL;
            if(tmp > 9)
            {
                cur = new ListNode(tmp%10);
                cary = 1;
            }
            else
            {
                cur = new ListNode(tmp);
            }
            cur->next = addingTwoNumber(NULL,l2->next,cary);
            return cur;
        }
        
        if(cary)
        {
            return new ListNode(1);
        }
        
        return NULL;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        return addingTwoNumber(l1,l2,0);
    }
};