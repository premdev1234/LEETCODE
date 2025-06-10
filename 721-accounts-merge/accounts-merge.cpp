struct DSU {
    vector<int> parent, size;
    DSU(int n) : parent(n), size(n, 1) {
        iota(parent.begin(),parent.end(), 0);
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n =  accounts.size();
        DSU dsu(n);
        unordered_map<string, int> emailToAccount;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) {
                const string& email = accounts[i][j];
                if (emailToAccount.find(email) != emailToAccount.end()) dsu.unite(i, emailToAccount[email]);
                else emailToAccount[email] = i;
            }
        }
        unordered_map<int, set<string>> mergedEmails;
        for (int i = 0; i < n; ++i) {
            int root = dsu.find(i);
            for (int j = 1; j < accounts[i].size(); ++j) mergedEmails[root].insert(accounts[i][j]);
        }
        vector<vector<string>> result;
        for (auto& [root, emails] : mergedEmails) {
            vector<string> account;
            account.push_back(accounts[root][0]); // Add name
            account.insert(account.end(), emails.begin(), emails.end()); // Add sorted emails
            result.push_back(account);
        }
        
        return result;
    }
};