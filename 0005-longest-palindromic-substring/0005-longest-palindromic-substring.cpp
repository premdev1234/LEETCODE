class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size() , start = 0 , len = 1;
        auto expand = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) left-- , right++;
            int curr = right - left - 1;
            if (curr > len) len = curr , start = left + 1;
        };
        for (int i = 0; i < n; i++) {
            expand(i,i);
            expand(i,i+1);
        }
        return s.substr(start, len);
    }
};