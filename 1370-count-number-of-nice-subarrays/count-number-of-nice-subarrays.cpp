class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;
        
        int odd = 0, result = 0;
        for (int num : nums) {
            odd += num % 2;
            result += prefixCount[odd - k];
            prefixCount[odd]++;
        }
        
        return result;
    }
};
