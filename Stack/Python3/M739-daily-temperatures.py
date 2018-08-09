# time:  O(n)
# space: O(n)

class Solution:
    def dailyTemperatures(self, temperatures):
        """
        :type temperatures: List[int]
        :rtype: List[int]
        """
        st = []
        res = [0] * len(temperatures)
        for i in range(len(temperatures)):
            while len(st) > 0 and temperatures[st[-1]] < temperatures[i]:
                j = st.pop()
                res[j] = i - j
                
            st.append(i)
            
        return res
		
# faster solution, not using stack
class Solution:
    def dailyTemperatures(self, temperatures):
        """
        :type temperatures: List[int]
        :rtype: List[int]
        """
		n = len(temperatures)
		res = [0] * n
		for i in range(n-2, -1, -1):
			j = i + 1
			while True:
				if temperatures[j] > temperatures[i]:
					res[i] = j - 1
					break
				elif res[i] == 0:
					break
				j += res[j]
				
		return res