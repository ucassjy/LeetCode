# Time:  O(m + n)
# Space: O(1)

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
	# My solution, iteratively	
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        l3 = pc = ListNode(0)

        while l1 and l2:
            if l1.val <= l2.val:
                pc.next = l1
                l1 = l1.next
            else:
                pc.next = l2
                l2 = l2.next
			pc = pc.next

        pc.next = l1 if l1 else l2
        return l3.next
		
	# recursively
	def mergeTwoLists(self, l1, l2):
		if not l1 or not l2:
			return l1 or l2
		if l1.val < l2.val:
			l1.next = self.mergeTwoLists(l1.next, l2)
			return l1
		else:
			l2.next = self.mergeTwoLists(l1, l2.next)
			return l2