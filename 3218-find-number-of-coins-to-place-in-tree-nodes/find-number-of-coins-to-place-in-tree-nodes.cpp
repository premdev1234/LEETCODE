class Solution {
public:
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        int n = cost.size();
        vector<vector<int>> tree(n);

        for (const auto& edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }

        vector<long long> coin(n, 0);

        function<tuple<vector<int>, vector<int>>(int, int)> dfs = 
            [&](int node, int parent) -> tuple<vector<int>, vector<int>> {
            vector<int> top_max = {cost[node], INT_MIN, INT_MIN};
            vector<int> top_min = {cost[node], INT_MAX, INT_MAX};

            for (int child : tree[node]) {
                if (child == parent) continue;

                auto [child_max, child_min] = dfs(child, node);

                // Merge child's top_max into current node's top_max
                for(int val : child_max) {
                    if (val > top_max[0]) {
                        top_max[2] = top_max[1];
                        top_max[1] = top_max[0];
                        top_max[0] = val;
                    } else if (val > top_max[1]) {
                        top_max[2] = top_max[1];
                        top_max[1] = val;
                    } else if (val > top_max[2]) {
                        top_max[2] = val;
                    }
                }

                // Merge child's top_min into current node's top_min
                for (int val : child_min) {
                    if (val < top_min[0]) {
                        top_min[2] = top_min[1];
                        top_min[1] = top_min[0];
                        top_min[0] = val;
                    } else if (val < top_min[1]) {
                        top_min[2] = top_min[1];
                        top_min[1] = val;
                    } else if (val < top_min[2]) {
                        top_min[2] = val;
                    }
                }
            }

            // Remove INT_MIN and INT_MAX if present to get actual top 3 max and top 2 min
            vector<int> final_max;
            for(int val : top_max){
                if(val != INT_MIN) final_max.push_back(val);
            }
            vector<int> final_min;
            for(int val : top_min){
                if(val != INT_MAX) final_min.push_back(val);
            }

            if (final_max.size() < 3) {
                coin[node] = 1;
            } else {
                long long product_max = 1LL * final_max[0] * final_max[1] * final_max[2];
                long long product_min = (final_min.size() >= 2) ? 1LL * final_min[0] * final_min[1] * final_max[0] : -1;
                coin[node] = max({product_max, product_min, 0LL});
            }

            // Return only valid values
            vector<int> ret_max, ret_min;
            for(int i = 0; i < 3; ++i) if(top_max[i] != INT_MIN) ret_max.push_back(top_max[i]);
            for(int i = 0; i < 2; ++i) if(top_min[i] != INT_MAX) ret_min.push_back(top_min[i]);
            return {ret_max, ret_min};
        };

        dfs(0, -1);
        return coin;
    }
};