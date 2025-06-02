class Solution {
public:
    void generate(int idx, const vector<int>& nums, vector<int>& curr, vector<vector<int>>& allSubsets) {
    if (idx == nums.size()) {
        allSubsets.push_back(curr);
        return;
    }

    // include
    curr.push_back(nums[idx]);
    generate(idx + 1, nums, curr, allSubsets);

    // exclude
    curr.pop_back();
    generate(idx + 1, nums, curr, allSubsets);
}
    void backtrack(int idx, const vector<int>& nums, vector<int>& subset, vector<vector<int>>& allSubsets) {
        allSubsets.push_back(subset);
        for (int i = idx; i < nums.size(); ++i) {
            subset.push_back(nums[i]);
            backtrack(i + 1, nums, subset, allSubsets);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int total = 1 << n; // 2^n
        vector<vector<int>> allSubsets;

        for (int mask = 0; mask < total; ++mask) {
            vector<int> subset;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    subset.push_back(nums[i]);
                }
            }
            allSubsets.push_back(subset);
        }
        return move(allSubsets);
        // back trACK
        // vector<vector<int>> allSubsets;
        // vector<int> subset;
        // backtrack(0, nums, subset, allSubsets);
        // return allSubsets;

        // recursion
        // vector<vector<int>> allSubsets;
        // vector<int> curr;
        // generate(0, nums, curr, allSubsets);
        // return allSubsets;
    }
};