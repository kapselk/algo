// Fenwick Tree
// Point update Range sum

template<typename T>
struct Fenwick {
    vector<T> tree;
    int n;

    Fenwick(int n_) {
        n = n_;
        tree.assign(n, 0);
    }
    Fenwick(vector<T> &a) {
        n = (int) a.size();
        tree.assign(n, 0);
        for (int i = 0; i < n; i++) add(i, a[i]);
    }
    T query(int r) {
        T ret = 0;
        while (r >= 0) {
            ret += tree[r];
            r = (r & (r + 1)) - 1;
        }
        return ret;
    }
    T query(int l, int r) { return query(r) - query(l - 1); }
    void add(int id, T v) {
        while (id < n) {
            tree[id] += v;
            id |= (id + 1);
        }
    }
};