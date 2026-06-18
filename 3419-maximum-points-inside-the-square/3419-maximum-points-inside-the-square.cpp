class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        vector<int> dist;
        unordered_map<char, vector<int>> mp;
        int n = points.size();
        for(int i = 0; i < n; i++) {
            int d = max(abs(points[i][0]), abs(points[i][1]));
            dist.push_back(d);
            mp[s[i]].push_back(d);
        }
        int badEdge = INT_MAX;
        for(auto &[ch, v] : mp) {
            if(v.size() < 2) continue;
            sort(v.begin(), v.end());
            badEdge = min(badEdge, v[1]);
        }
        if(badEdge == INT_MAX) return n;
        int ans = 0;
        for(int d : dist)if(d < badEdge)ans++;
        return ans;
    }
};