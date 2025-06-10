class Solution {
public:
    bool isvalid(vector<int>& bloomDay, int day, int m, int k) {
        int count = 0, consecutive = 0;
        for (const int& bloom : bloomDay) {
            if (bloom <= day) {
                consecutive++;
                if (consecutive == k) {
                    count++;
                    consecutive = 0; // reset after making bouquet
                    if (count == m) return true;
                }
            } else {
                consecutive = 0;
            }
        }
        return count >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long total = 1LL * m * k;
        if (bloomDay.size() < total) return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (isvalid(bloomDay, mid, m, k)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};
