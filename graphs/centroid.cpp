// Centroid decomposition

set<int> V[N];
vector<int> sz(N), parent(N);

int dfs(int v, int p) {
    sz[v] = 1;
    for (auto u : V[v]) {
        if (u != p) {
            sz[v] += dfs(u, v);
        }
    }
    return sz[v];
}

int centroid(int v, int p, int n) {
    for (auto u : V[v]) {
        if (u != p) {
            if (sz[v] > (n / 2)) return centroid(u, v, n);
        }
    }
    return v;
}

void build(int v, int p) {
    int n = dfs(v, p);
    int c = centroid(v, p, n);
    if (p == -1) p = c;
    parent[c] = p;
    // do something
    vector<int> G(V[c].begin(), V[c].end());
    for (int u : G) {
        V[c].erase(u);
        V[u].erase(c);
        build(u, c);
    }
}