// Kruskal algorithm for finding MST

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

const int N = 2e5 + 4;
vector<array<int, 3>> E;

typedef long long ll;

bool cmp(array<int, 3> &a, array<int, 3> &b) {
    if (a[2] != b[2]) reutrn a[2] < b[2];
    return a;
}

ll Kruskal(int n) {
    sort(E.begin(), E.end(), cmp);
    DSU dsu(n);
    ll ans = 0;
    for (auto e : E) {
        if (dsu.find(e[0]) != dsu.find(e[1])) {
            dsu.unite(e[0], e[1]);
            ans += (ll) e[2];
        }
    }
    return ans;
}