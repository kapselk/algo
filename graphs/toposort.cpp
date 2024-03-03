// Topological sorting

const int N = 2e5;
vector<int> V[N], order;
vector<bool> vis(N, false);

void dfs(int v) {
    vis[v] = 1;
    for (int u : V[v]) {
        if (!vis[u]) dfs(u);
    }
    order.push_back(v);
}

void toposort() {
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i);
    }
    reverse(order.begin(), order.end());
}