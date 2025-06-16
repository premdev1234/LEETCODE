class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> freeServer, endTime;
        for (int i = 0; i < n; ++i) {
            freeServer.emplace(servers[i], i);
        }
        int time = 0;
        vector<int> res(m, 0);
        for (int i = 0; i < m; ++i) {
            time = max(time, i);
            if (freeServer.empty()) {
                time = endTime.top().first;
            }
            while (!endTime.empty() && endTime.top().first <= time) {
                int freeId = endTime.top().second;
                endTime.pop();
                freeServer.emplace(servers[freeId], freeId);
            }
            int curId = freeServer.top().second;
            freeServer.pop();
            endTime.emplace(time + tasks[i], curId);
            res[i] = curId;
        }
        return res;
    }
};