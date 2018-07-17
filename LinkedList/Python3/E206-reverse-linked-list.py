# time:  O(n)
# space: O(1)

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    # My solution, recursively
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        return self.reverse(head)
        
    def reverse(self, fhalf, shalf=None):
        if fhalf is None:
            return shalf
        f = fhalf.next
        fhalf.next = shalf
        return self.reverse(f, fhalf)

    # Iterative, faster
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        prev = None
        while head:
            curr = head
            head = head.next
            curr.next = prev
            prev = curr
        return prev
}
