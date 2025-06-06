class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int n = s.size();
        int left = 0, right = 0, res = 0;

        while (right < n) {
            while (st.count(s[right])) {
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            res = max(res, right - left + 1);
            right++;
        }

        return res;
    }
};
