// Segment Tree
// 1D point update and range query

template<typename T>
struct SegTree {
    T comb(T a, T b) { return a + b; }
    const T ID = 0;
    int sz;
    vector<T> seg;
    void init(int n) {
        sz = 1;
        while (sz < n) { sz <<= 1; }
        seg.assign(2 * sz + 2, ID);
    }
    SegTree(int n) { init(n); }
    SegTree(int n, vector<T> v) {
        init(n);
        for (int i = 0; i < n; i++) {
            seg[i + sz] = v[i];
        }
        for (int i = sz - 1; i >= 1; i--) {
            seg[i] = comb(seg[i<<1], seg[(i << 1) + 1]);
        }
    }
    void update(int id, T v) {
        id += sz;
        seg[id] = v; id >>= 1;
        while(id) {
            seg[id] = comb(seg[id<<1], seg[(id << 1) + 1]);
            id >>= 1;
        }
    }
    T query(int a, int b, int x, int l, int r) {
        if (b < l || a > r) return ID;
        if (a <= l && b >= r) return seg[x];
        int m = (l + r) >> 1;
        return comb(query(a, b, x << 1, l, m), query(a, b, (x << 1) + 1, m + 1, r));
    }
    T query(int a, int b) { return query(a, b, 1, 0, sz-1); }
}