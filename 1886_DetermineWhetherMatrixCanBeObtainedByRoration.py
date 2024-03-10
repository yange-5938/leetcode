# Given two n x n binary matrices mat and target, return true if it is possible to make mat equal to target by rotating mat in 90-degree increments, or false otherwise.

 

# Example 1:


# Input: mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
# Output: true
# Explanation: We can rotate mat 90 degrees clockwise to make mat equal target.
# Example 2:


# Input: mat = [[0,1],[1,1]], target = [[1,0],[0,1]]
# Output: false
# Explanation: It is impossible to make mat equal to target by rotating mat.

class Solution:
    def findRotation(self, mat: List[List[int]], target: List[List[int]]) -> bool:
        # Rotate 4 times 
        for _ in range(4):
            if(target == mat):
                return True
            mat[:] = list(map(list, zip(*mat[::-1])))
        return False