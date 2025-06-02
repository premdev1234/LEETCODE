class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        bitset<20001> bits;  // adjust the 20001 to max possible target+1
        bits[0] = 1;
        for (int num : nums) {
            bits |= (bits << num);
            if (bits[target]) return true;
        }
        return bits[target];
    }
};
