# Given a string s, return the longest 
# palindromic
 
# substring
#  in s.

 

# Example 1:

# Input: s = "babad"
# Output: "bab"
# Explanation: "aba" is also a valid answer.
# Example 2:

# Input: s = "cbbd"
# Output: "bb"


class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)

        # create a dp table
        dp = [[False] * n for _ in range(n)]

        # all substring with length 1 is palindrome
        for i in range(n):
            dp[i][i] = True

        start = 0
        max_len = 1

        # check substring of length 2
        for i in range(n-1):
            if s[i] == s[i+1]:
                dp[i][i+1] = True
                start = i
                max_len = 2

        # check substring of length 3 and more
        for length in range(3,n+1):
            for i in range(n - length + 1):
                j = i + length - 1
                if dp[i+1][j-1] and s[i] == s[j]:
                    dp[i][j] = True
                    start = i
                    max_len = length

        return s[start:start+max_len]
