class TimeMap {
    unordered_map<string, vector<pair<int, string>>> store;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        store[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp) {
        if (!store.count(key))
            return "";
        const auto& entries = store[key];
        int l = 0, r = entries.size() - 1, res = -1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (entries[m].first <= timestamp) {
                res = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return res == -1 ? "" : entries[res].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */