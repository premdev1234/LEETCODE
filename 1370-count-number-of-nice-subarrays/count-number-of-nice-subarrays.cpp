#include <vector>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0;
        int sub = 0;
        int odd = 0;
        
        while (l < n) {
            while (r < n && odd < k) {
                if (nums[r] % 2 == 1)odd++;
                r++;
            }
            if (odd == k) {
                int temp = r;
                while (temp < n && nums[temp] % 2 == 0) temp++;
                sub += (temp - r + 1);
            } else break;
            if (nums[l] % 2 == 1)  odd--;
            l++;
        }
        
        return sub;
    }
};