// Bellman-Ford algorithm

const int N = 2e5;
const int INF = 1e9;
vector<array<int, 3>> E;

void belman_ford(int src, int n) {
    vector<int> dist(n+1, INF), par(n+1, -1);
    dist[src] = 0;
    int end_node = -1;
    for (int i = 0; i <= n; i++) {
        end_node = -1;
        for (auto e : E) {
            int a = e[0], b = e[1], w = e[2];
            if (dist[a] < INF) {
                if (dist[a] + w < dist[b]) {
                    dist[b] = dist[a] + w;
                    par[b] = a;
                    end_node = b;
                }
            }
        }
    }
    if (end_node != -1) {
        // negative cycle with end_node
    }
}