class Solution {
public:
    int lengthOfLongestSubstring(const string& s) {
        int freq[256] = {-1}; // ASCII character size
        fill(freq, freq + 256, -1);
        int left = 0;
        int len_max = 0;
        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            if (freq[c] >= left) left = freq[c] + 1;
            freq[c] = right; // update last seen index
            len_max = max(len_max, right - left + 1);
        }

        return len_max;
    }
};