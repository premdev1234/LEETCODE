class Solution {
public:
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right)
            if (s[left++] != s[right--])
                return false;
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> reversedIndex;
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            string rev = words[i];
            reverse(rev.begin(), rev.end());
            reversedIndex[rev] = i;
        }
        vector<vector<int>> result;
        for (int i = 0; i < n; ++i) {
            const string& word = words[i];
            int len = word.size();
            for (int split = 0; split <= len; ++split) {
                if (isPalindrome(word, split, len - 1)) {
                    string prefix = word.substr(0, split);
                    if (reversedIndex.count(prefix) &&
                        reversedIndex[prefix] != i)
                        result.push_back({i, reversedIndex[prefix]});
                }
                if (split > 0 && isPalindrome(word, 0, split - 1)) {
                    string suffix = word.substr(split);
                    if (reversedIndex.count(suffix) &&
                        reversedIndex[suffix] != i)
                        result.push_back({reversedIndex[suffix], i});
                }
            }
        }
        return result;
    }
};
