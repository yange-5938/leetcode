# Given two strings s and t, return true if t is an anagram of s, and false otherwise.

# An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

# Example 1:

# Input: s = "anagram", t = "nagaram"
# Output: true
# Example 2:

# Input: s = "rat", t = "car"
# Output: false


class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # check length
        if len(s) != len(t):
            return False
        
        # check same amount of char

        count_s = {}
        count_t = {}

        for char in s:
            if char in count_s:
                count_s[char] += 1
            else:
                count_s[char] = 1
        
        for char in t:
            if char in count_t:
                count_t[char] += 1
            else:
                count_t[char] = 1
        
        return count_s == count_t
            
