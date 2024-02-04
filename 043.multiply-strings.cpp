/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
        // Handle edge cases where either num1 or num2 is zero
        if (num1 == "0" || num2 == "0") return "0";

        size_t len1 = num1.size();
        size_t len2 = num2.size();
        
        // Initialize a vector to store the result
        vector<int> result(len1 + len2, 0);

        // Multiply digits and update result
        for (size_t i = len1 - 1; i != SIZE_MAX; --i) {
            int carry = 0;
            for (int j = len2 - 1; j != SIZE_MAX; --j) {
                int tempSum = (num1[i] - '0') * (num2[j] - '0') + result[i + j + 1] + carry;
                result[i + j + 1] = tempSum % 10;
                carry = tempSum / 10;
            }
            result[i] += carry;
        }

        // Convert result to string
        string resultStr = "";
        for (int digit : result) {
            resultStr += (digit + '0');
        }

        // Remove leading zeros
        size_t startPos = resultStr.find_first_not_of('0');
        if (startPos != string::npos) {
            resultStr = resultStr.substr(startPos);
        } else {
            resultStr = "0";
        }

        return resultStr;
    }
};
// @lc code=end

