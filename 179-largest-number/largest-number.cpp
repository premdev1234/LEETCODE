class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            string A = to_string(a), B = to_string(b);
            return A + B > B + A;
        });

        if (nums[0] == 0) return "0";  // Handle all zeros case

        string res;
        for (int num : nums) res += to_string(num);
        return res;
    }
};
