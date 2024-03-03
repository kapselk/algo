// Dijkstra - using priority_queue

const int N = 2e5;
const ll INF = 1e18;
vector<pair<int, ll>> V[N];
vector<ll> dist(N, INF);
vector<int> par(N);

typedef pair<long long, int> pli;
void dijkstra(int src) {
    dist[src] = 0;
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push({0, src});
    while (!pq.empty()) {
        int v = pq.top().second;
        ll dv = pq.top().first;
        q.pop();
        if (dv != dist[v]) continue;
        for (auto e : V[v]) {
            int u = e.first;
            ll w = e.second;
            if (dist[v] + w < dist[u]) {
                dist[u] = dist[v] + w;
                parent[u] = v;
                q.push({dist[u], u});
            }
        }
    }
}