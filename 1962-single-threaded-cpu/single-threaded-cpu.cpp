class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<array<int, 3>> indexedTasks; // {enqueue, processing, index}
        for (int i = 0; i < n; ++i) {
            indexedTasks.push_back({tasks[i][0], tasks[i][1], i});
        }

        // Step 1: Sort by enqueue time
        sort(indexedTasks.begin(), indexedTasks.end());

        // Step 2: Min-heap based on processing time, then index // {processing time, index}
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> pq;

        vector<int> result;
        long long time = 0; // Use long long to avoid overflow
        int i = 0;

        while (i < n || !pq.empty()) {
            // Load all tasks available at current time
            while (i < n && indexedTasks[i][0] <= time) {
                pq.emplace(indexedTasks[i][1], indexedTasks[i][2]);
                ++i;
            }

            if (!pq.empty()) {
                auto [procTime, idx] = pq.top(); pq.pop();
                time += procTime;
                result.push_back(idx);
            } else {
                // No task available, jump to next task arrival
                time = indexedTasks[i][0];
            }
        }

        return result;
    }
};
