# time:  O(n)
# space: O(h)

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDiffInBST(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def TtN(n, l):
            if n.left:
                TtN(n.left, l)
                
            l.append(n.val)
            
            if n.right:
                TtN(n.right, l)
                
        l = []
        TtN(root, l)
        return min([abs(a - b) for a, b in zip(l, l[1:])])