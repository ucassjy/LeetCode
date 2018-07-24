# time:  O(n)
# space: O(h)

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0
        
        if not (root.left or root.right):
            return 1
        
        return max(self.maxDepth(root.left), self.maxDepth(root.right)) + 1

	# faster solution
	def maxDepth(self, root):
		"""
        :type root: TreeNode
        :rtype: int
        """
        
        if not root:
            return 0
        
        depth = 0
        nodes_at_depth = [root]
        while nodes_at_depth:
            depth += 1
            temp_nodes_at_depth = []
            for node in nodes_at_depth:
                if node.left:
                    temp_nodes_at_depth.append(node.left)
                if node.right:
                    temp_nodes_at_depth.append(node.right)
            nodes_at_depth = temp_nodes_at_depth
        
        return depth
