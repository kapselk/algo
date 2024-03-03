// Floyd-Warshall algorithm

const int N = 100;
const int INF = 1e9;
vector<vector<int>> dist(N, vector<int>(N, INF));

void floyd_warshall(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}