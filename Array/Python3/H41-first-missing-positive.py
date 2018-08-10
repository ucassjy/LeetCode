# time:  O(n)
# space: O(1)

class Solution:
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.append(0)
        l = len(nums)
        if l == 1:
            return 1

        for i in range(l):
            if nums[i] < 0 or nums[i] >= l:
                nums[i] = 0
                
        for i in range(l):
            nums[nums[i] % l] += l
            
        for i in range(1, l):
            if nums[i] // l == 0:
                return i
        return l