class CustomStack {
    vector<int> stk;
    vector<int> inc;
    int maxSize;

public:
    CustomStack(int maxSize) : maxSize(maxSize) {}

    void push(int x) {
        if (stk.size() < maxSize) {
            stk.push_back(x);
            inc.push_back(0);  // No pending increment for this element initially
        }
    }

    int pop() {
        if (stk.empty()) return -1;

        int i = stk.size() - 1;
        int res = stk[i] + inc[i];

        if (i > 0) inc[i - 1] += inc[i];  // propagate increment down
        stk.pop_back();
        inc.pop_back();

        return res;
    }

    void increment(int k, int val) {
        int i = min(k, (int)stk.size()) - 1;
        if (i >= 0) inc[i] += val;  // only touch one element — lazy update
    }
};
