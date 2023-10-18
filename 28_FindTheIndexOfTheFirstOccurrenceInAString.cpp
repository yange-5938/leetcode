// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

// Example 1:

// Input: haystack = "sadbutsad", needle = "sad"
// Output: 0
// Explanation: "sad" occurs at index 0 and 6.
// The first occurrence is at index 0, so we return 0.

class Solution {
public:
    int strStr(string haystack, string needle) {
        char* stack = &haystack[0];
        char* need = &needle[0];
        bool allSame;

        for (int i=0; i < haystack.length(); i++){
            if (stack[i]==need[0]){
                allSame = true;
                for (int j=0; j < needle.length(); j++){
                    if (stack[j+i]!=need[j]) {
                        allSame = false;
                        break;
                    }
                }
                if (allSame) return i;
            }
        }
        return -1;
    }
};
