class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (k > s.length()) return false;

        unordered_set<string> binary_codes;
        string code = s.substr(0, k);
        binary_codes.insert(code);

        for (int i = k; i < s.length(); ++i) {
            code.erase(0, 1);
            code += s[i];
            binary_codes.insert(code);
        }

        return binary_codes.size() == (1 << k);
    }
};
