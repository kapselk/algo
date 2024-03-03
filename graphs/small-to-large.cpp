// Small to large technique 

const int N = 2e5 + 4;
vector<int> V[N];

struct SL {
    vector<int> val;
    map<int, int> cnt[N];
    SL(vector<int> &v) { val = v; }
    void comb(int a, int b) {
        bool swapped = 0;
        if (cnt[a].size() < cnt[b].size()) { swap(a, b); swapped = 1; }
        for (auto e : cnt[b]) {
            cnt[a][e.first] += e.second;
        }
        cnt[b].clear();
        if (swapped) cnt[a].swap(cnt[b]);
    }
    void calc(int v, int p=-1) {
        cnt[v][val[v]]++;
        for (int u : V[v]) {
            if (u != p) {
                calc(u, v);
                comb(u, v);
            }
        }
        
    }
};