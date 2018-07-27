# time:  O(n+e)
# space: O(n+e)

class Solution:
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        
        def dfs(ver, oud, visited):
            if visited[ver]:
                return False
            visited[ver] = 1
            
            for v in oud[ver]:
                if v in self.noRing:
                    continue
                if not dfs(v, oud, visited):
                    return False
                
            self.noRing.add(ver)
            return True
            
        self.noRing = set()
        visited = [0] * numCourses
        oud = [[] for _ in range(numCourses)]
        
        for i, j in prerequisites:
            oud[j].append(i)
            
        for i in range(numCourses):
            
            if i in self.noRing:
                continue
                
            if oud[i] != []:
                if not dfs(i, oud, visited):
                    return False
            
        return True