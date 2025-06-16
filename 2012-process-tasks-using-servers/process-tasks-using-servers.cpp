#define pq1 priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>
#define pq2 priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>>
#define forn(N) for(int i = 0 ; i < (N) ; ++i)
#define vi vector<int>
#define SZ(a) a.size()
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        pq1 freeServers;
        pq2 busyServers;
        forn(SZ(servers))freeServers.emplace(servers[i], i);
        int time = 0;
        vi result;
        forn(SZ(tasks)){
            time = max(time, i);
            // Free up any busy servers that are now available
            while (!busyServers.empty() && get<0>(busyServers.top()) <= time) {
                auto [availTime, weight, idx] = busyServers.top(); busyServers.pop();
                freeServers.emplace(weight, idx);
            }

            if (freeServers.empty()) {
                // No server is free now — fast-forward time to earliest busy server
                time = get<0>(busyServers.top());
                while (!busyServers.empty() && get<0>(busyServers.top()) <= time) {
                    auto [availTime, weight, idx] = busyServers.top(); busyServers.pop();
                    freeServers.emplace(weight, idx);
                }
            }

            auto [weight, idx] = freeServers.top(); freeServers.pop();
            result.push_back(idx);
            busyServers.emplace(time + tasks[i], weight, idx);
        }

        return result;
    }
};
