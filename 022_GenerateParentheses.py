# Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

# Example 1:

# Input: n = 3
# Output: ["((()))","(()())","(())()","()(())","()()()"]
# Example 2:

# Input: n = 1
# Output: ["()"]


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def backtrack(string, left, right):
            if len(string) == 2 * n:
                result.append(string)
                return
            if(left < n):
                backtrack(string+'(', left + 1, right)
            if(right < left):
                backtrack(string+')', left, right+1)
        result = []
        backtrack('', 0, 0 )
        return result
