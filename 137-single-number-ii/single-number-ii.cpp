class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < 32; i++) {
            int sum = 0;
            for (int num : nums) if (num & (1 << i)) sum++;
            if (sum % 3) result |= (1 << i);
        }
        return result;
    }
};