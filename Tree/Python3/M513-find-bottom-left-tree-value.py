# time:  O(n)
# space: O(n)

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
        nl = [root]
        while(1):
            tnl = []
            
            for n in nl:
                if n.left:
                    tnl.append(n.left)
                if n.right:
                    tnl.append(n.right)
                    
            if tnl:
                nl = tnl
            else:
                return nl[0].val