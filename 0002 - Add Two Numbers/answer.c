#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *add_lists_r(struct ListNode *l1, struct ListNode *l2, int carry)
{
	struct ListNode *res = malloc(sizeof(*res));
	int v1 = 0, v2 = 0;

	if (!l1 && !l2 && !carry)
		return (NULL);

	if (l1)
		v1 = l1->val;
	if (l2)
		v2 = l2->val;

	res->val = v1 + v2 + carry;
	res->next = add_lists_r(l1 ? l1->next : NULL, l2 ? l2->next : NULL, res->val / 10);
	res->val %= 10;

	return (res);
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	return (add_lists_r(l1, l2, 0));
}
