// Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

// The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

// Return the quotient after dividing dividend by divisor.

// Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.

 

// Example 1:

// Input: dividend = 10, divisor = 3
// Output: 3
// Explanation: 10/3 = 3.33333.. which is truncated to 3.
// Example 2:

// Input: dividend = 7, divisor = -3
// Output: -2
// Explanation: 7/-3 = -2.33333.. which is truncated to -2.

class Solution {
public:
    int divide(int dividend, int divisor) {
        int result = 0;

        if(dividend == 0) return 0;

        if (divisor == 1) return std::min(dividend, INT_MAX);
        else if (divisor == -1) {
            if (dividend == INT_MIN) return INT_MAX;
            else return std::min(-dividend, INT_MAX);
        }
        else {
            int sign = (dividend > 0) == (divisor > 0) ? 1 : -1;
            long absDividend = std::abs(dividend);
            long absDivisor = std::abs(divisor);

            while (absDividend >= absDivisor){
                long temp = absDivisor, multiple = 1;
                while (absDividend >= (temp << 1)){
                    temp <<= 1;
                    multiple <<= 1;
                }
                absDividend -= temp;
                result += multiple;
            }
            result = (sign == 1) ? result : -result;
        }
        return result;
    }
};
