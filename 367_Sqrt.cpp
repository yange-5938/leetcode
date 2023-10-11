// Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

// You must not use any built-in exponent function or operator.

// For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 

// Example 1:

// Input: x = 4
// Output: 2
// Explanation: The square root of 4 is 2, so we return 2.

class Solution {
        // there's much better numerical method I remember from Numerik. But maybe next time.

public:
    int mySqrt(int x) {
        // stupid method: go through 1..n, till found the biggest n which n^2 <= x
        long sqr = 0;
        int biggest = 0;
        for(long i = 0; i <=x;i++){
            sqr = i*i;
            if (sqr <= x){
                biggest = i;
            } else{
                break;
            }
        }
        return biggest;
    }
};
