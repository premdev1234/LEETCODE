class Solution {
    static const int MODULO = 1e9 + 7;
    vector<long long> fact, inv;
public:
    int waysToBuildRooms(vector<int>& prevRoom) {   
        int n = prevRoom.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; i++) {
            adj[prevRoom[i]].push_back(i);
        }
        
        // Precompute factorial and inverse factorial dynamically
        fact.resize(n + 1, 1);
        inv.resize(n + 1, 1);
        for (int i = 2; i <= n; i++) {
            fact[i] = fact[i - 1] * i % MODULO;
        }
        inv[n] = modpow(fact[n], MODULO - 2, MODULO);
        for (int i = n - 1; i >= 1; i--) {
            inv[i] = inv[i + 1] * (i + 1) % MODULO;
        }

        return dfs(0, adj).first;
    }

private:
    long long modpow(long long a, long long b, long long mod) {
        long long res = 1;
        while (b > 0) {
            if (b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }

    pair<long long, int> dfs(int u, vector<vector<int>>& adj) {
        long long ways = 1;
        int subtree_size = 1;
        for (int v : adj[u]) {
            auto [child_ways, child_size] = dfs(v, adj);
            ways = ways * child_ways % MODULO;
            ways = ways * fact[subtree_size + child_size - 1] % MODULO * inv[child_size] % MODULO * inv[subtree_size - 1] % MODULO;
            subtree_size += child_size;
        }
        return {ways, subtree_size};
    }
};
