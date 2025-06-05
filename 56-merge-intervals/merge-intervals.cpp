class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {return a[0] < b[0];});

        vector<vector<int>> merged;
        merged.reserve(intervals.size());
        merged.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i) {
            auto& last = merged.back();
            if (last[1] < intervals[i][0])merged.push_back(intervals[i]);
            else last[1] = max(last[1], intervals[i][1]);
        }
        return merged;
    }

};
