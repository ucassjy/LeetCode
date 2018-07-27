# time:  O(n + e)
# space: O(e)

class Solution:
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        
        ind = [0] * numCourses
        oud = [[] for _ in range(numCourses)]
        
        for i, j in prerequisites:
            ind[i] += 1
            oud[j].append(i)
            
        res = []
        tmp = []
        for i in range(numCourses):
            if ind[i] == 0:
                res.append(i)
                tmp.append(i)
                
        while tmp:
            tmp2 = []
            for x in tmp:
                for y in oud[x]:
                    ind[y] -= 1
                    if ind[y] == 0:
                        tmp2.append(y)
                        res.append(y)
                    
            tmp = tmp2
            
        return res if len(res) == numCourses else []