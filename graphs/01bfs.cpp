// 0-1 BFS using deque

dist[src] = 0;
deque<int> q;
q.push_front(src);
while (!q.empty()) {
    int v = q.front();
    q.pop_front();
    for (auto e : V[v]) {
        int u = e.first;
        int w = e.second;
        if (dist[v] + w < dist[u]) {
            dist[u] = dist[v] + w;
            if (w == 0) q.push_front(u);
            else q.push_back(u);
        }
    }
}
