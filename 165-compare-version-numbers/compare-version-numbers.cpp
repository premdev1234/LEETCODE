class Solution {
public:
    vector<int> split(const string& s) {
        vector<int> result;
        string temp;
        for (char c : s) {
            if (c == '.') {
                if (!temp.empty()) {
                    int num = 0;
                    for (char ch : temp)
                        num = 10 * num + (ch - '0');
                    result.push_back(num);
                    temp.clear();
                }
            } else {
                temp += c;
            }
        }
        if (!temp.empty()) {
            int num = 0;
            for (char ch : temp)
                num = 10 * num + (ch - '0');
            result.push_back(num);
        }
        return result;
    }

    int compareVersion(string version1, string version2) {
        vector<int> v1 = split(version1), v2 = split(version2);
        int n = max(v1.size(), v2.size());
        for (int i = 0; i < n; i++) {
            int num1 = i < v1.size() ? v1[i] : 0;
            int num2 = i < v2.size() ? v2[i] : 0;
            if (num1 < num2) return -1;
            if (num1 > num2) return 1;
        }
        return 0;
    }
};
