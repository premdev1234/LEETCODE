class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](auto &a, auto &b){
            return a[1] < b[1];  // ✅ Ascending end time
        });

        set<int> availableDays;
        for (int i = 1; i <= 1e5; ++i) availableDays.insert(i);  // All possible days

        int count = 0;
        for (auto &event : events) {
            int start = event[0], end = event[1];
            auto it = availableDays.lower_bound(start);
            if (it != availableDays.end() && *it <= end) {
                ++count;
                availableDays.erase(it);  // Use this day
            }
        }
        return count;
    }
};
