class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (char c : tasks) freq[c]++;
        priority_queue<int> pq;
        for (auto& [task, count] : freq) pq.push(count);

        int totalTime = 0;

        while (!pq.empty()) {
            int cycle = n + 1;  // max tasks we can do in one round
            vector<int> temp;
            while (cycle > 0 && !pq.empty()) {
                int curr = pq.top(); pq.pop();
                curr--;
                if (curr > 0) temp.push_back(curr); // push back for reuse
                totalTime++;
                cycle--;
            }
            for (int cnt : temp) pq.push(cnt);

            if (!pq.empty()) totalTime += cycle; 
        }

        return totalTime;
    }
};
