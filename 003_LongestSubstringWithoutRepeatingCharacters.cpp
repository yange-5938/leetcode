// Given a string s, find the length of the longest 
// substring
//  without repeating characters.

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLen = 0;
        int left = 0, right = 0;
        std::unordered_set<char> charSet;

        while (right < n){
            if (charSet.find(s[right]) == charSet.end()){
                charSet.insert(s[right]);
                maxLen = std::max(maxLen, right-left+1);
                ++right;
            } else {
                charSet.erase(s[left]);
                ++left;
            }
        }

        return maxLen;
    }
};
