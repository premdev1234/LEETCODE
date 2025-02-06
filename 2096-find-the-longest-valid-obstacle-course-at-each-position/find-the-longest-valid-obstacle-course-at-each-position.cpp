class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> res(n, 0);
        vector<int> tails;
        for (int i = 0; i < n; ++i) {
            // Find the rightmost index where obstacles[i] can be appended.
            // upper_bound because we allow equal values (non-decreasing)
            auto it = upper_bound(tails.begin(), tails.end(), obstacles[i]);
            int pos = it - tails.begin();
            if (it == tails.end())
                tails.push_back(obstacles[i]);
            else
                *it = obstacles[i];
            res[i] = pos + 1;
        }
        return res;
    }
};