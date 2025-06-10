class Solution {
    vector<char> parents;
    void _union(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ)
            return;
        parents[rootP] = rootQ;
    }
    bool connected(int p, int q) {
        return find(p) == find(q);
    }
    int find(int x) {
        if (parents[x] != x)
            parents[x] = find(parents[x]);
        return parents[x];
    }
public:
    bool equationsPossible(vector<string>& equations) {
        parents = vector<char>(26);
        for (int i = 0; i < parents.size(); i++)
            parents[i] = i;
        // handles "==" equations first, make union find forest
        for (auto& e : equations)
            if (e[1] == '=')
                _union(e[0] - 'a', e[3] - 'a');
        // check "!=" equations after
        for (auto& e : equations)
            if (e[1] == '!' && connected(e[0] - 'a', e[3] - 'a'))
                return false;
        return true;
    }
};