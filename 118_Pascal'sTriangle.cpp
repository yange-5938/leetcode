// Given an integer numRows, return the first numRows of Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


// Example 1:

// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows==0) return {};
        else if (numRows==1) return {{1}};
        
        auto preRows = generate(numRows-1);
        vector<int> currrentRow(numRows,1);
    
        for (int i = 1; i< numRows-1; ++i){
            currrentRow[i] = preRows.back()[i] + preRows.back()[i-1];
        }

        preRows.push_back(currrentRow);
        return preRows;
    }
};
