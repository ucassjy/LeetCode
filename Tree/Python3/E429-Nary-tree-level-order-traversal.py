# time:  O(n)
# space: O(n)

"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
class Solution(object):
    def levelOrder(self, root):
        """
        :type root: Node
        :rtype: List[List[int]]
        """
        
        if not root:
            return []
        
        t1 = [root]
        res = []
        while t1:
            res.append([node.val for node in t1])
            t1 = [child for node in t1 for child in node.children if child]
                
        return res