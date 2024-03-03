// Mo Algorithm
// Answer queries offline, complexity T((N+Q)sqrt(N))

const int N;
int ans[N], oc[N], BS;
vector<array<int, 3>> Q;

bool cmp(array<int, 3> &a, array<int, 3> &b) {
    if (a[0] / BS != b[0] / BS) return a[0] < b[0];
    return ((a[0] / BS) % 2 ? a[1] < b[1] : a[1] > b[1]);
}

int L = 0, R = -1, answer = 0;

void modify(int x, int delta) {
    // 
}

int calc(int l, int r) {
    while (L > l) modify(--L, 1);
    while (R < r) modify(++R, 1);
    while (L < l) modify(L++, -1);
    while (R > r) modify(R--, -1);
    return answer;
}

void solve() {
    int n;
    BS = sqrt(n);
    sort(Q.begin(), Q.end(), cmp);
    for (auto q : Q) {
        ans[q[2]] = calc(ans[q[0]], ans[q[1]]);
    }
}