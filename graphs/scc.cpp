// SCC - Strongest connected components

const int N = 2e5;
vector<int> V[N], Vt[N];
vector<bool> vis(N);
vector<int> ord;

void dfs1(int v) {
    vis[v] = 1;
    for (int u : V[v]) {
        if (!vis[u]) dfs1(u);
    }
    ord.push_back(v);
}

void dfs2(int v) {
    vis[v] = 1;
    // comp.push_back(v)
    for (auto u : Vt[v]) {
        if (!vis[u]) dfs2(u);
    }
}

// main - dfs1(root) ; clear vis ; for (auto u : ord) if (!vis[u]) dfs2(u)