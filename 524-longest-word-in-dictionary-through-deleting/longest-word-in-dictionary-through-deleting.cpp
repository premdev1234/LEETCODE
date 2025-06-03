class Solution {
public:
    // Returns true if 'a' is smaller than 'b' lexicographically or longer
    bool is_smaller(const string& a, const string& b) {
        if (a.length() > b.length()) return true;
        if (a.length() < b.length()) return false;
        return a < b; // lexicographical comparison if same length
    }

    // Checks if target is a subsequence of source
    bool is_subsequence(const string& source, const string& target) {
        int i = 0, j = 0;
        while (i < source.length() && j < target.length()) {
            if (source[i] == target[j]) ++j;
            ++i;
        }
        return j == target.length();
    }

    string findLongestWord(string s, vector<string>& dictionary) {
        string best = "";
        for (const string& word : dictionary) {
            if (is_subsequence(s, word)) {
                if (is_smaller(word, best)) {
                    best = word;
                }
            }
        }
        return best;
    }
};
