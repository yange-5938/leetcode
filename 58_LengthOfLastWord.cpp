// Given a string s consisting of words and spaces, return the length of the last word in the string.

// A word is a maximal substring consisting of non-space characters only.

 

// Example 1:

// Input: s = "Hello World"
// Output: 5
// Explanation: The last word is "World" with length 5.

class Solution {
public:
    int lengthOfLastWord(string s) {
        bool start = false;
        int count = 0;
        for (std::string::reverse_iterator rit=s.rbegin(); rit!=s.rend(); ++rit){
            if (*rit == ' '){
                if (start){
                    break;
                } else {
                    continue;
                }
            } else {
                start = true;
                count++;
            }
        }
        return count;
    } 
};
