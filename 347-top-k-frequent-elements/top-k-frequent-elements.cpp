class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int minVal = INT_MAX, maxVal = INT_MIN;

        for (int num : nums) {
            minVal = min(minVal, num);
            maxVal = max(maxVal, num);
        }

        int range = maxVal - minVal + 1;

        // Each pair stores (number, frequency)
        vector<pair<int, int>> count(range, {0, 0});
        for (int i = 0; i < range; ++i)
            count[i].first = i + minVal;

        for (int num : nums)
            count[num - minVal].second++;

        // Sort by frequency descending
        sort(count.begin(), count.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });

        // Extract top k elements
        vector<int> res;
        for (int i = 0; i < k; ++i)
            res.push_back(count[i].first);

        return res;
    }
};
