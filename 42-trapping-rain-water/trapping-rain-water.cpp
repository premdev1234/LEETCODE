

class Solution {
public:
    int trap(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;

    vector<int> leftMax(n), rightMax(n);
    leftMax[0] = height[0];
    rightMax[n - 1] = height[n - 1];

    #pragma omp parallel for
    for (int i = 1; i < n; i++) {
        leftMax[i] = max(leftMax[i - 1], height[i]);
    }

    #pragma omp parallel for
    for (int i = n - 2; i >= 0; i--) {
        rightMax[i] = max(rightMax[i + 1], height[i]);
    }

    int totalWater = 0;
    #pragma omp parallel for reduction(+:totalWater)
    for (int i = 0; i < n; i++) {
        totalWater += max(0, min(leftMax[i], rightMax[i]) - height[i]);
    }

    return totalWater;
}
};