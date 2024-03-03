// Low function - finding bridges and articulation points

const int N = 2e5;
vector<int> V[N];
vector<bool> vis(N);
vector<int> tin(N), tout(N);
int T = 0;

void dfs(int v, int p=-1) {
    vis[v] = 1;
    tin[v] = low[v] = T++;
    int childs = 0;
    for (int u : V[v]) {
        if (u == p) continue;
        if (vis[u]) low[v] = min(low[v], tin[u]);
        else {
            dfs(u, v);
            low[v] = min(low[v], low[u]);
            // if (low[u] > tin[v]) BRIDGE
            // if (low[u] >= tin[v] && p != -1) CUTPOINT
        }
    }
    // if (p == -1 && childs > 1) CUTPOINT
}