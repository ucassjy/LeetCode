# time:  O(n)
# space: O(n)

class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        ht = {}
        for i in range(len(nums)):
            
            if nums[i] in ht:
                return [ht[nums[i]], i]
            
            ht[target-nums[i]] = i