class NumArray {
private:
    struct SegmentTree {
        int n;
        vector<int> tree;

        SegmentTree(int size) {
            n = size;
            tree.assign(4 * n, 0);
        }

        void build(vector<int> &a, int v, int tl, int tr) {
            if (tl == tr) {
                tree[v] = a[tl];
            } else {
                int tm = (tl + tr) / 2;
                build(a, v * 2, tl, tm);
                build(a, v * 2 + 1, tm + 1, tr);
                tree[v] = tree[v * 2] + tree[v * 2 + 1];
            }
        }

        void update(int v, int tl, int tr, int pos, int val) {
            if (tl == tr) {
                tree[v] = val;
            } else {
                int tm = (tl + tr) / 2;
                if (pos <= tm)
                    update(v * 2, tl, tm, pos, val);
                else
                    update(v * 2 + 1, tm + 1, tr, pos, val);
                tree[v] = tree[v * 2] + tree[v * 2 + 1];
            }
        }

        int query(int v, int tl, int tr, int l, int r) {
            if (l > r) return 0;
            if (l == tl && r == tr) return tree[v];
            int tm = (tl + tr) / 2;
            return query(v * 2, tl, tm, l, min(r, tm)) +
                   query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        }
    };

    SegmentTree* st;
    int n;

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        st = new SegmentTree(n);
        st->build(nums, 1, 0, n - 1); // build at node 1
    }

    void update(int index, int val) {
        st->update(1, 0, n - 1, index, val);
    }

    int sumRange(int left, int right) {
        return st->query(1, 0, n - 1, left, right);
    }
};
