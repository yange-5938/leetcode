// Write an algorithm to determine if a number n is happy.

// A happy number is a number defined by the following process:

// Starting with any positive integer, replace the number by the sum of the squares of its digits.
// Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
// Those numbers for which this process ends in 1 are happy.
// Return true if n is a happy number, and false if not.


// Example 1:

// Input: n = 19
// Output: true
// Explanation:
// 12 + 92 = 82
// 82 + 22 = 68
// 62 + 82 = 100
// 12 + 02 + 02 = 1
// Example 2:

// Input: n = 2
// Output: false

class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int> seen;
        bool haveSeen = false;
        while (!haveSeen){
            n = getSumSquare(n);
            if (n == 1){
                return true;
            } else if (seen.contains(n)){
                haveSeen = true;
            } else {
                seen.insert(n);
            }
        }
        return false;
    }

    int getSumSquare(int & n){
        std::vector<int> digits;
        while(n != 0){
            int digit =  n % 10;
            n /= 10;
            digits.push_back(digit);
        }
        int result = std::accumulate(digits.begin(), digits.end(),0, [](int a, int b)   {return a + b*b;});

        return result;
    }
};
