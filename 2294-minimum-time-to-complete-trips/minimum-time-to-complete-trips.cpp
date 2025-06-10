class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long left = 1;
        long long right = (long long)*min_element(time.begin(), time.end()) * totalTrips;
        
        while (left < right) {
            long long mid = left + (right - left) / 2;
            long long total = 0;
            for (int t : time) {
                total += mid / t;
                if (total >= totalTrips) {
                    break;
                }
            }
            if (total >= totalTrips) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};