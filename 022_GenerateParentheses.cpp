// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2:

// Input: n = 1
// Output: ["()"]

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<std::string> result;
        backtrack("",0,0,n,result);
        return result;
    }

private:
    void backtrack(std::string s, int left, int right, int n, vector<std::string>& result){
        if (s.length() == 2 * n){
            result.push_back(s);
            return;
        }

        if(left < n) backtrack(s+'(', left + 1, right, n, result);
        if(right<left) backtrack(s+')', left, right+1, n , result);
    }
};
