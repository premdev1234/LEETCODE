class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;
        
        vector<pair<int, char>> v;
        for (auto [c, f] : freq) v.emplace_back(f, c);
        
        sort(v.begin(), v.end(), greater<>());  // descending by frequency
        
        string res;
        for (auto [f, c] : v) {
            res += string(f, c);
        }
        return res;
    }
};
