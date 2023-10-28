// You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

// Increment the large integer by one and return the resulting array of digits.

 

// Example 1:

// Input: digits = [1,2,3]
// Output: [1,2,4]
// Explanation: The array represents the integer 123.
// Incrementing by one gives 123 + 1 = 124.
// Thus, the result should be [1,2,4].

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        auto it = digits.rbegin();
        addOne(it, digits);
        return digits;
    }

    void addOne(std::vector<int>::reverse_iterator& it, vector<int>& digits){
        if(it == digits.rend()) {
            digits.insert(digits.begin(), 1);
        }
        else if(*it == 9 ){
            *it = 0;
            addOne(++it, digits);
        } else {
            *it += 1;
        }
    }
};
