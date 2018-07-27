# time:  O(n)
# space: O(n)

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
            return []
        
        nl = [root]
        res = []
        while nl:
            tv, tn = [], []
            for n in nl:
                tv.append(n.val)
                if n.left:
                    tn.append(n.left)
                if n.right:
                    tn.append(n.right)
            
            res.append(tv)
            nl = tn
            
        return res