// Disjoint Set Union - Union Find

struct DSU {
    vector<int> repr, cnt;
    DSU(int size) {
        repr.assign(size+1, 0);
        cnt.assign(size+1, 0);
        for (int i = 0; i <= n; i++) repr[i] = i;
    }

    int find(int x) {
        if (repr[x] == x) return x;
        return repr[x] = find(repr[x]);
    }

    void unite(int a, int b) {
        int fa = find(a), fb = find(b);
        if (cnt[fa] < cnt[fb]) swap(fa, fb);
        cnt[fa] += cnt[fb];
        repr[fb] = fa;
    }
};