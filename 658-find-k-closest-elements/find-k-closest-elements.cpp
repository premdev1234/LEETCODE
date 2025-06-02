class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        map<int, vector<int>> mp; // Ordered map to maintain ascending distance
        for (int a : arr) {
            mp[abs(a - x)].push_back(a);
        }

        vector<int> res;
        for (auto &[dist, group] : mp) {
            for (int v : group) {
                if (k > 0) {
                    res.push_back(v);
                    --k;
                } else break;
            }
            if (k == 0) break;
        }

        sort(res.begin(), res.end());
        return move(res);
    }
};
