struct DSU {
    vector<int> parent, size;
    DSU(int n) : parent(n), size(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU dsu(n);
        unordered_map<string, int> emailToId;

        // Union by email occurrence
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) {
                string& email = accounts[i][j];
                if (!emailToId.count(email))
                    emailToId[email] = i;
                else
                    dsu.unite(i, emailToId[email]);
            }
        }

        // Map from root to list of emails (use vector instead of set)
        unordered_map<int, vector<string>> rootToEmails;
        for (auto& [email, id] : emailToId) {
            int root = dsu.find(id);
            rootToEmails[root].push_back(email);
        }

        // Construct result
        vector<vector<string>> res;
        for (auto& [root, emails] : rootToEmails) {
            sort(emails.begin(), emails.end());
            vector<string> acc = {accounts[root][0]}; // root's name
            acc.insert(acc.end(), emails.begin(), emails.end());
            res.push_back(move(acc));
        }

        return res;
    }
};
