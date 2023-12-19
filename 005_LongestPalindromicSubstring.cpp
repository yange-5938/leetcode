// Given a string s, return the longest 
// palindromic
 
// substring
//  in s.

 

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.
// Example 2:

// Input: s = "cbbd"
// Output: "bb"

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();

        // create a dp table
        std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));

        int start = 0;
        int max_len = 0;

        // each variable with length 1
        for (int i = 0; i < n; ++i){
            dp[i][i] = true;
            max_len = 1;
        }

        // check length 2
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i+1]){
                dp[i][i+1] = true;
                start = i;
                max_len = 2;
            }
        }

        // check length 3 and more
        for (int len = 3; len <= n; ++len){
            for (int i = 0; i <= n - len; ++ i){
                int j = i+len-1;
                if (dp[i+1][j-1] && s[i]==s[j]){
                    dp[i][j] = true;
                    start = i;
                    max_len = len;
                }    
            }
        }

        return s.substr(start, max_len);
    }
};
