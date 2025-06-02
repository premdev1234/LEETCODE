class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
    int xor_sum = 0;
    for (int num : nums) xor_sum ^= num;
    unsigned int diff_bit = xor_sum & -((unsigned int)xor_sum);

    int a = 0, b = 0;
    for (int num : nums) {
        if (num & diff_bit) a ^= num;
        else b ^= num;
    }

    return {a, b};
}

};