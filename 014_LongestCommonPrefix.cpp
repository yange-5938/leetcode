// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

 

// Example 1:

// Input: strs = ["flower","flow","flight"]
// Output: "fl"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::string ans= "";
        for(std::size_t i=0; i<strs[0].size(); i++){
            for (std::size_t j = 1; j < strs.size(); j++){
                if (strs[j][i] != strs[0][i]){
                    return ans;
                }
            }
            ans = ans+strs[0][i];
        }
        return ans;
    }
};
