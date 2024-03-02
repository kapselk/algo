// Lazy Segment Tree
// Query Sum
// Update: Add / Chmin / Chmax

template<typename T>
struct LazySegTree {
    const T ID = 0;
    int sz;
    vector<T> seg, lazy;
    void init(int n) {
        sz = 1;
        while (sz < n) { sz <<= 1; }
        seg.assign(2 * sz + 2, 0);
        lazy.assign(2 * sz + 2, 0);
    }
    LazySegTree(int n) { init(n); }
    LazySegTree(int n, vector<T> a) {
        init(n);
        for (int i = 0; i < n; i++) { seg[i + sz] = a[i]; }
        for (int i = sz - 1; i >= 1; i--) { seg[i] = seg[i << 1] + seg[(i << 1) + 1]; }
    }
    void push(int x, int l, int r) {
        if (lazy[x]) {
            int m = (l + r) >> 1;
            seg[x << 1] += (m - l + 1) * lazy[x];
            seg[(x << 1) + 1] += (r - (m + 1) + 1) * lazy[x];
            lazy[x << 1] += lazy[x];
            lazy[(x << 1) + 1] += lazy[x];
            lazy[x] = 0;
        }
    }
    void update(int a, int b, T v, int x, int l, int r) {
        if (b < l || a > r) return;
        if (a <= l && b >= r) {
            seg[x] += (r - l + 1) * v;
            lazy[x] += v;
            return;
        }
        push(x, l, r);
        int m = (l + r) >> 1;
        update(a, b, v, x << 1, l, m);
        update(a, b, v, (x << 1) + 1, m+1, r);
        seg[x] = seg[x << 1] + seg[(x << 1) + 1];
    }
    void update(int a, int b, T v) { update(a, b, v, 1, 0, sz-1); }
    T query(int a, int b, int x, int l, int r) {
        if (b < l || a > r) return ID;
        if (a <= l && b >= r) return seg[x];
        push(x, l, r);
        int m = (l + r) >> 1;
        return query(a, b, x << 1, l, m) + query(a, b, (x << 1) + 1, m + 1, r);
    }
    T query(int a, int b) { return query(a, b, 1, 0, sz-1); }
};