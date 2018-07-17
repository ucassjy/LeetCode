// time:  O(n)
// space: O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *	   int val;
 *	   struct ListNode *next;
 * };
 */
// Iteratively
struct ListNode* reverseList(struct ListNode* head){
	struct ListNode* retl = NULL;
    
	while(head){
		struct ListNode* tmp = head;
        head = head->next;
		tmp->next = retl;
		retl = tmp;
	}
	return retl;
}
// Recursively
struct ListNode* reverseList(struct ListNode* head){
	if(NULL == head || NULL == head->next) return head;

	struct ListNode *p = head->next;
	head->next = NULL;
	struct ListNode *newhead = reverseList(p);
	p->next = head;

	return newhead;
}
