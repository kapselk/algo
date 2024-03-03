// Sparse segment tree - dynamic segment tree

template<typename T>
struct Node {
    int l, r;
    T sum = 0;
    Node *lchild = nullptr, *rchild = nullptr;

    Node(int l_, int r_) {
        l = l_;
        r = r_;
    }

    void extend() {
        if (!lchild && l < r) {
            int m = (l + r) >> 1;
            lchild = new Node<T>(l, m);
            rchild = new Node<T>(m + 1, r);
        }
    }

    void add(int id, T v) {
        extend();
        sum += v;
        if (lchild) {
            if (id <= lchild->r) lchild->add(id, v);
            else rchild->add(id, v);
        }
    }
    T query(int a, int b) {
        if (l <= a && b >= r) return sum;
        if (b < l || a > r) return 0;
        extend();
        return lchild->query(a, b) + rchild->query(a, b);
    }
};