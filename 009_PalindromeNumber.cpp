// Given an integer x, return true if x is a palindrome, and false otherwise.

// Example 1:

// Input: x = 121
// Output: true
// Explanation: 121 reads as 121 from left to right and from right to left.

class Solution {
public:
    bool isPalindrome(int x) {
        if(x <0){
            return false;
        }
        int temp;
        deque<char> vecs; 
        
        while (x > 0){
            temp = x%10;
            x = x / 10;
            vecs.push_back(char(temp));
            }

        while (vecs.size()>1){
            if ( vecs.back() != vecs.front()){
                return false;
            }
            vecs.pop_back();
            vecs.pop_front();
        } 
        return true;
    }
};
