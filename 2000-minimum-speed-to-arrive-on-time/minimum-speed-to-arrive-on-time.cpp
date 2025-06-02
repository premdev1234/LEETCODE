class Solution {
public:
    bool canReach(const vector<int>& dist, double hour, int speed) {
        double total = 0.0;
        int n = dist.size();
        for (int i = 0; i < n - 1; ++i)
            total += ceil((double)dist[i] / speed);
        total += (double)dist[n - 1] / speed;
        return total <= hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        if (hour <= n - 1) return -1;  // can't make it even with infinite speed

        int left = 0 , right = 1e7, ans = -1;
        while (left <= right) {
            int speed = (left + right) / 2;
            if (canReach(dist, hour, speed)) {
                ans = speed;
                right = speed - 1;
            } else {
                left = speed + 1;
            }
        }
        return ans;
    }
};
