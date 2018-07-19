class Solution:

    # time:  O(n)
    # space: O(n)
    def scoreOfParentheses(self, S):
        """
        :type S: str
        :rtype: int
        """
        S = S.replace('()', '1')
        layer = result = 0
        for c in S:
            if c == '(':
                layer += 1
            elif c == ')':
                layer -= 1
            else:
                result += 1 << layer

        return result
    
    def scoreOfParentheses(self, S):
        """
        :type S: str
        :rtype: int
        """
        return eval(S.replace(')(', ')+(').replace('()', '1').replace(')',')*2'))
