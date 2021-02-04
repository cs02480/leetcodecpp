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
    ListNode* oddEvenList(ListNode* head) {
		if (head == NULL)return head;
		ListNode * odd = head;
		ListNode * oddend = head;
		ListNode * even = head->next;
		ListNode * evenend = even;
		if (even == NULL)return odd;
		if (even && (even->next == NULL))return head;

		while (oddend && oddend->next)
		{
			if (evenend != oddend->next)
			{
				evenend->next = oddend->next;
				evenend = evenend->next;
			}
			oddend->next = oddend->next->next;
			if (oddend->next == NULL)break;
			oddend = oddend->next;
		}
		if (evenend != NULL)
			evenend->next = NULL;
		oddend->next = even;
		return odd;

	}
};