# time:  O(n)
# space: O(h)

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findBottomLeftValue(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def bottomLeft(root, depth):
            if not root:
                return
            
            if depth > self.maxDepth:
                self.res = root.val
                self.maxDepth = depth
                
            bottomLeft(root.left, depth+1)
            bottomLeft(root.right, depth+1)
            
        self.res = 0
        self.maxDepth = 0
        bottomLeft(root, 1)
        return self.res