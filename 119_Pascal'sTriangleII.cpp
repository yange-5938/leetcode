// Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


// Example 1:

// Input: rowIndex = 3
// Output: [1,3,3,1]

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) return {1};
        else if (rowIndex == 1) return {1,1};
         
        auto lastRow = getRow(rowIndex-1);
        
        vector<int> thisRow(rowIndex+1,1);

        for(int i = 1; i < lastRow.size(); ++i){
            thisRow[i] = lastRow[i] + lastRow[i-1];
        }
        return thisRow;

    }
};
