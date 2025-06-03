class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int res[9] = {1,10,91,739,5275,32491,168571,712891,2345851};
        return res[n];
    }
};