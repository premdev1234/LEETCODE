class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        using T = pair<double, pair<int, int>>;
        priority_queue<T> pq;

        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                double frac = (double)arr[i] / arr[j];
                pq.push({frac, {arr[i], arr[j]}});
                if(pq.size()>k) pq.pop();
            }
        }
        return {pq.top().second.first, pq.top().second.second};
    }
};
