class Solution {
public:
    vector<int> encode(const string &s) {
        unordered_map<char, int> mapping;
        vector<int> pattern;
        int id = 0;
        for (char c : s) {
            if (mapping.find(c) == mapping.end()) {
                mapping[c] = id++;
            }
            pattern.push_back(mapping[c]);
        }
        return pattern;
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<int> target = encode(pattern);
        vector<string> result;
        for (const string &word : words) {
            if (encode(word) == target) {
                result.push_back(word);
            }
        }
        return result;
    }
};
