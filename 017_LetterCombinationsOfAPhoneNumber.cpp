// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// Example 2:

// Input: digits = ""
// Output: []


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        std::unordered_map<char, std::string> digits_map ={
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        vector<std::string> result;
        std::string current;

        backtrack(digits, 0, current, result, digits_map);

        return result;
    }
    void backtrack(const std::string& digits, int index, std::string& current, vector<std::string>& result, const std::unordered_map<char, std::string>& digits_map){
        if (index == digits.size()){
            result.push_back(current);
            return;
        }

        char currentDigit = digits[index];

        const std::string& letters = digits_map.at(currentDigit);
        for (char letter : letters) {
            current.push_back(letter);
            backtrack(digits, index+1, current, result, digits_map);
            current.pop_back();
        }
    }
};
