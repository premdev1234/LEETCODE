class Solution {
public:
    long long countOperationsToEmptyArray(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<std::pair<int, int>> numWithIndex;
        numWithIndex.reserve(n);
        
        for (int i = 0; i < n; ++i) {
            numWithIndex.emplace_back(nums[i], i);
        }
        
        std::sort(numWithIndex.begin(), numWithIndex.end());
        
        long long operations = n;
        for (int i = 1; i < n; ++i) {
            if (numWithIndex[i].second < numWithIndex[i - 1].second) {
                operations += (n - i);
            }
        }
        
        return operations;
    }
};