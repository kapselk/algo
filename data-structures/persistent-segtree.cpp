// Persistent segment tree

struct Node {
    Node *l, *r;
    ll sum;

    Node(ll val) {
        l = r = nullptr;
        sum = val;
    }
    Node(Node *l_, Node *r_) {
        l = l_;
        r = r_;
        sum = 0;
        if (l) sum += l->sum;
        if (r) sum += r->sum;
    }
};

Node* build(vector<int> &a, int l, int r) {
    if (l == r) return new Node*(a[l]);
    int m = (l + r) >> 1;
    return new Node(build(a, l, m), build(a, m + 1, r));
}

ll query(Node* root, int a, int b, int l, int r) {
    if (a < = l && b >= r) return root->sum;
    if (b < l || a > r) return 0;
    int m = (l + r) >> 1;
    return query(root->l, a, b, l, m) + query(root->r, a, b, m + 1, r);
}

Node* update(Node *root, int id, ll v, int l, int r) {
    if (l == r) return new Node(v);
    int m = (l + r) >> 1;
    if (id <= m) return update(root->l, id, v, l, m);
    else return update(root->r, id, v, m + 1, r);
}