# time:  O(n)
# space: O(1)

class Solution:
    def findPoisonedDuration(self, timeSeries, duration):
        """
        :type timeSeries: List[int]
        :type duration: int
        :rtype: int
        """
        if timeSeries == []:
            return 0
        
        res = duration
        for i in range(1, len(timeSeries)):
            res += min(timeSeries[i] - timeSeries[i-1], duration)
            
        return res
		
# faster solution
class Solution:
    def findPoisonedDuration(self, timeSeries, duration):
        """
        :type timeSeries: List[int]
        :type duration: int
        :rtype: int
        """
        res = 0
        start = -1
        next = -1
        for time in timeSeries:
            if time < next:
                next = time + duration
            else:
                res += next - start
                start = time
                next = time + duration
        return res + next - start