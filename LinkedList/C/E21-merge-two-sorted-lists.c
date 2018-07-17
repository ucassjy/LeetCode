// Time:  O(m + n)
// Space: O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode{
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, strust ListNode* l2){
	if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    struct ListNode *pa, *pb, *pc, *l3;
	pa = l1;
	pb = l2;

	if(pa->val <= pb->val){
		l3 = pc = pa;
		pa = pa->next;
	}else{
		l3 = pc = pb;
		pb = pb->next;
	}

	while(pa && pb){
		if(pa->val <= pb->val){
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}else{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	
	pc->next = pa?pa : pb;
	return l3;
}
