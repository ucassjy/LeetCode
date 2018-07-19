# time:  O(n)
# space: O(n)

class Solution:
    def calPoints(self, ops):
        """
        :type ops: List[str]
        :rtype: int
        """
        tmp = []
        for op in ops:
            if op == "C":
                tmp.pop()
            elif op == "D":
                tmp.append(tmp[-1] * 2)
            elif op == "+":
                tmp.append(tmp[-1] + tmp[-2])
            else:
                tmp.append(int(op))

        return sum(tmp)
