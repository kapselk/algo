// Sparse table - static RMQ with O(1) queries

const int N = 2e5, M = 20;
const int INF = 1e9;
vector<int> a(N), lg(N);
vector<vector<int>> st(M, vector<int>(N, INF));

void init(int n) {
    for (int i = 0; i < n; i++) st[0][i] = a[i];
    for (int j = 1; j < M; j++) {
        for (int i = 0; i + (1 << j) < n; i++) {
            st[j][i] = min(st[j - 1][i], st[j - 1][j + (1 << (j - 1))]);
        }
    }
    lg[1] = 0;
    int id = 1;
    for (int i = 2; i <= n; i++) {
        if ((1 << id) == i) {
            id++;
        }
        lg[i] = id - 1;
    }
}

int query(int l, int r) {
    int j = lg[r - l + 1];
    return min(st[j][l], st[j][r - (1 << j) + 1]);
}