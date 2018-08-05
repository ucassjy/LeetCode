# time:  O(len(S) * T(in))
# space: O(1)

class Solution:
    def numJewelsInStones(self, J, S):
        """
        :type J: str
        :type S: str
        :rtype: int
        """
        res = 0
        
        for s in S:
            if s in J:
                res += 1
                
        return res