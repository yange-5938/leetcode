#
# @lc app=leetcode.cn id=49 lang=python3
#
# [49] Group Anagrams
#

# @lc code=start
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101]
        mapping = defaultdict(list)

        for word in strs:
            key = reduce(lambda x,y:x*y, (primes[ord(char)-ord('a')] for char in word),1)
            mapping[key].append(word)
        return list(mapping.values())
                
        
# @lc code=end