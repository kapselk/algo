// Heavy-Light decomposition

struct HLD {
    vector<int> par, depth, heavy, head, id;
    int T = 0;
    HLD(int n) {
        par.assign(n+1, 0);
        depth.assign(n+1, 0);
        heavy.assign(n+1, -1);
        head.assign(n+1, 0);
        id.assign(n+1, 0);
    }
    int dfs(int v) {
        int sz = 1, maxsz = 0;
        for (int u : V[v]) {
            if (u != par[v]) {
                par[u] = v;
                depth[u] = depth[v] + 1;
                int usz = dfs(u);
                sz += usz;
                if (usz > maxsz) {
                    maxsz = usz;
                    heavy[v] = u;
                }
            }
        }
        return sz;
    }
    void decompose(int v, int h) {
        head[v] = h;
        id[v] = ++T;
        if (heavy[v] != -1) decompose(heavy[v], h);
        for (int u : V[v]) {
            if (u != par[v] && u != heavy[v]) {
                decompose(u, u);
            }
        }
    }
    // RMQ
    int query(int a, int b) {
        // st - segment tree
        ll res = 0;
        while (head[a] != head[b]) {
            if (depth[a] < depth[b]) swap(a, b);
            res = max(res, st.query(id[head[a]], id[a]));
            a = par[head[a]];
        }
        if (depth[a] < depth[b]) swap(a, b);
        res = max(res, st.query(id[b], id[a]));
        return res;
    }
};