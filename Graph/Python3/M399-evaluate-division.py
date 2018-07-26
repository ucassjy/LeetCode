# time:  O(n^3)
# space: O(n^2)

class Solution:
    def calcEquation(self, equations, values, queries):
        """
        :type equations: List[List[str]]
        :type values: List[float]
        :type queries: List[List[str]]
        :rtype: List[float]
        """
        
        mat = collections.defaultdict(dict)
        for (first, second), val in zip(equations, values):
            mat[first][first] = mat[second][second] = 1.0
            mat[first][second] = val
            mat[second][first] = 1 / val
            
        for i in mat:
            for j in mat[i]:
                for k in mat[i]:
                    mat[j][k] = mat[j][i] * mat[i][k]
                    
        return [mat[f].get(s, -1.0) for (f, s) in queries]