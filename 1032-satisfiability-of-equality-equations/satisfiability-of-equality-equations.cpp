struct DSU {
    vector<int> parent, size;
    DSU(int n) : parent(n), size(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (x != parent[x]) parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DSU dsu(26); // For lowercase letters a-z (0 to 25)

        // Step 1: Process all equality equations (==) to group variables
        for (const string& eq : equations) {
            if (eq[1] == '=') { // Check for ==
                int x = eq[0] - 'a'; // Convert char to index (0-25)
                int y = eq[3] - 'a';
                dsu.unite(x, y); // Unite variables that are equal
            }
        }

        // Step 2: Check inequality equations (!=) for contradictions
        for (const string& eq : equations) {
            if (eq[1] == '!') { // Check for !=
                int x = eq[0] - 'a';
                int y = eq[3] - 'a';
                if (dsu.find(x) == dsu.find(y)) { // If in same group, contradiction
                    return false;
                }
            }
        }

        return true;
    }
};