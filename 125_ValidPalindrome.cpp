// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
// Given a string s, return true if it is a palindrome, or false otherwise.

// Example 1:

// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.


class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size()<2) return true;
        deque<char> str = convertStr(s);
        while (str.size()>1){
            if(str.front() != str.back()) return false;
            str.pop_back();
            str.pop_front();
        }
        return true;
    }

    deque<char> convertStr(string s){
        deque<char> temp;
        for (int i = 0; i < s.size(); i++){
            if(isalnum(s[i])) {
                if (s[i]>=65 && s[i]<=92) s[i]+=32;
                temp.push_back(s[i]);
            }
        }
        return temp;
    }
};
