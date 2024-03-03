// Lowest common ancestor - binary lifting

const int N = 5e5+1, M = 20;
vector<int> V[N];

int T = 0;
vector<int> tin(N), tout(N);
vector<vector<int>> jump(N, vector<int>(M, 0));

void dfs(int v, int p=0) {
    tin[v] = ++T;
    jump[v][0] = p;
    for (int j = 1; j < M; j++) {
        jump[v][j] = jump[jump[v][j-1]][j-1];
    }
    for (int u : V[v]) {
        if (u != p) {
            dfs(u, v);
        }
    }
    tout[v] = ++T;
}

bool isancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int a, int b) {
    if (isancestor(a, b)) return a;
    if (isancestor(b, a)) return b;
    for (int j = M - 1; j >= 0; j--) {
        if (!isancestor(jump[a][j], b)) a = jump[a][j];
    }
    return jump[a][0];
}