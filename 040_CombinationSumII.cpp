// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.

 

// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]
// Example 2:

// Input: candidates = [2,5,2,1,2], target = 5
// Output: 
// [
// [1,2,2],
// [5]
// ]

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result{};
        vector<int> path{};
        std::sort(candidates.begin(), candidates.end());
        backtrack(candidates,target, result, path, 0);
        return result;
    }
private:
    void backtrack(vector<int> &candidates, int target, vector<vector<int>>& result, vector<int> path, int start){
        if (target == 0) {
            result.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size(); ++i){
            if (i > start && candidates[i] == candidates[i-1]) continue;
            else if (candidates[i] > target) continue;
            else {
                path.push_back(candidates[i]);
                backtrack(candidates, target-candidates[i], result, path, i+1);
                path.pop_back();
            }

        }
    }
};
