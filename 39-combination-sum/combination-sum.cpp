class Solution {
public:
    vector<vector<int>> result;
    vector<int> currentCombination;

    void backtrack(const vector<int>& coins, int startIndex, int target) {
        if (target == 0) {
            result.push_back(currentCombination);
            return;
        }
        for (int i = startIndex; i < coins.size(); ++i) {
            if (coins[i] > target) break; //early termination
            currentCombination.push_back(coins[i]);
            backtrack(coins, i, target - coins[i]); // i, not i+1 → unlimited usage
            currentCombination.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end()); // necessary for break optimization
        backtrack(coins, 0, target);
        return result;
    }
};
