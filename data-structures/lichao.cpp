// Li Chao tree - convex hull trick using segment tree

const ll INF = 1e18;

struct Line {
    // line y = ax + b
    ll a, b;
    Line(ll a_, ll b_) {
        a = a_;
        b = b_;
    }
    Line() : { Line(0, -INF) }
    ll val(ll x) {
        return a * x + b;
    }
    
};

struct LiChao {
    int size = 0;
    vector<Line> seg;
    LiChao(int n) {
        size = 1;
        while (size < n) size <<= 1;
        seg.reszie(2 * size + 2);
    }
    void add_line(Line nl, int x, int l, int r) {
        int m = (l + r) >> 1;
        bool lef = nl.val(l) < line[x].val(l);
        bool mid = nl.val(m) < line[x].val(m);
        if (mid) swap(nl, line[x]);
        if (l == r) return;
        else if (lef != mid) add_line(nl, x << 1, l, m);
        else add_line(nl, (x << 1) + 1, m + 1, r);
    }
    void add_line(Line nl) { add_line(nl, 1, 0, sz-1); }
    ll query(int pt, int x, int l, int r) {
        int m = (l + r) >> 1;
        if (l == r) return line[x].val(pt);
        else if (x <= m) return min(line[x].val(pt), query(pt, x << 1, l, m));
        else return min(line[x].val(pt), query(pt, (x << 1) + 1, m + 1, r));
    }
    ll query(int pt) { return query(pt, 1, 0, sz-1); }
};