class Solution {
private:
    void dfs(int n, unordered_map<int, int>& freq, 
             vector<int>& path, vector<vector<int>>& res) {
        if (path.size() == n) {
            res.push_back(path);
            return;
        }
        for (auto& [num, count] : freq) {
            if (count > 0) {
                path.push_back(num);
                freq[num]--;
                dfs(n, freq, path, res);
                path.pop_back();
                freq[num]++;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }        
        dfs(nums.size(), freq, path, res);
        return res;
    }
};