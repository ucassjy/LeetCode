# time:  O(n)
# space: O(n)

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def constructMaximumBinaryTree(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        m = max(nums)
        i = nums.index(m)
        
        t = TreeNode(m)
        if i != 0:
            t.left = self.constructMaximumBinaryTree(nums[:i])
        if i != len(nums)-1:
            t.right = self.constructMaximumBinaryTree(nums[i+1:])
        
        return t
		
	# faster solution
	def constructMaximumBinaryTree(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        s = []
        for num in nums:
            cur = TreeNode(num)
            while s and s[-1].val < num:
                cur.left = s.pop()
            if s:
                s[-1].right = cur
            s.append(cur)
        return s[0]