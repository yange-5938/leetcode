# Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

# The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

# Return the quotient after dividing dividend by divisor.

# Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.

 

# Example 1:

# Input: dividend = 10, divisor = 3
# Output: 3
# Explanation: 10/3 = 3.33333.. which is truncated to 3.
# Example 2:

# Input: dividend = 7, divisor = -3
# Output: -2
# Explanation: 7/-3 = -2.33333.. which is truncated to -2.

class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        INT_MAX = 2**31 - 1
        INT_MIN = -2**31

        result = 0

        if dividend == 0:
            return 0

        if divisor == 1:
            result = min(INT_MAX, dividend)
        elif divisor == -1:
            result = max(min(-dividend, INT_MAX), INT_MIN)
        else:
            sign = 1 if (dividend > 0) == (divisor > 0) else -1
            dividend, divisor = abs(dividend), abs(divisor)

            while dividend >= divisor:
                temp, multiple = divisor, 1
                while(dividend > (temp<<1)):
                    temp <<= 1
                    multiple <<= 1
                dividend -= temp
                result += multiple

            result = result if (sign == 1) else -result

        
        return min(max(result, INT_MIN), INT_MAX)
