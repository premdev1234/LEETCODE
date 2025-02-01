class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        vector<double> angles;
        int sameLocation = 0;
        
        // Convert points to angles relative to location
        for(const auto& point : points) {
            if(point[0] == location[0] && point[1] == location[1]) {
                sameLocation++;
                continue;
            }
            
            double ang = atan2(point[1] - location[1], point[0] - location[0]) * 180.0 / M_PI;
            if(ang < 0) ang += 360.0;
            angles.push_back(ang);
        }
        
        // Sort angles
        sort(angles.begin(), angles.end());
        
        // Duplicate angles array and add 360 to handle wraparound
        int n = angles.size();
        for(int i = 0; i < n; i++) {
            angles.push_back(angles[i] + 360.0);
        }
        
        // Sliding window to find maximum points visible
        int maxPoints = 0;
        int left = 0;
        
        for(int right = 0; right < angles.size(); right++) {
            while(left < right && angles[right] - angles[left] > angle) {
                left++;
            }
            maxPoints = max(maxPoints, right - left + 1);
        }
        
        // Add points at same location
        return maxPoints + sameLocation;
    }
};