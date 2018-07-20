# time:  O(n)
# space: O(1)

class Solution:
    def findDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        
        res = []
        for x in nums:
            if nums[abs(x) - 1] < 0:
                res.append(abs(x))
            else:
                nums[abs(x) - 1] *= -1
                
        return res

    # a faster solution
    def findDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        l=[0]*(len(nums)+1)
        res=[]
        for i in nums:
            if l[i]==1:
                res.append(i)
            else:
                l[i]=1
        return res
