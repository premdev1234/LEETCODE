class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;

        priority_queue<pair<int, char>> pq;
        for (auto [c, f] : freq) pq.push({f, c});

        string result;
        while (!pq.empty()) {
            auto [f, c] = pq.top(); pq.pop();
            result += string(f, c);
        }
        return result;
    }
};
