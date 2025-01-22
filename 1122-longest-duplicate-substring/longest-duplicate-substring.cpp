class Solution {
public:
    string longestDupSubstring(string s) {
        int low = 1, high = s.size() - 1; 
        string result = "";
        const long long base = 131;      
        const long long mod = (1LL << 31) - 1; 

        while (low <= high) {
            int mid = low + (high - low) / 2;
            string duplicate = findDuplicate(s, mid, base, mod);

            if (!duplicate.empty()) {
                result = duplicate;
                low = mid + 1;
            } else {
                high = mid - 1; 
            }
        }

        return result;
    }

private:
    string findDuplicate(const string &s, int length, long long base, long long mod) {
        unordered_map<long long, int> hashMap; 
        long long hash = 0, power = 1;

        for (int i = 1; i < length; i++) {
            power = (power * base) % mod;
        }

        for (int i = 0; i < length; i++) {
            hash = (hash * base + (s[i] - 'a' + 1)) % mod;
        }
        hashMap[hash] = 0;

        for (int i = 1; i <= s.size() - length; i++) {
            hash = (hash - (s[i - 1] - 'a' + 1) * power % mod + mod) % mod;

            hash = (hash * base + (s[i + length - 1] - 'a' + 1)) % mod;

            if (hashMap.find(hash) != hashMap.end()) {
                int startIdx = hashMap[hash];
                if (s.compare(startIdx, length, s, i, length) == 0) {
                    return s.substr(i, length); 
                }
            }

            hashMap[hash] = i; 
        }

        return ""; 
    }
};
