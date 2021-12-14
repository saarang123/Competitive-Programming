
//Lazy SegTree which can handle line updates in the form ax + b
template<class Node>
struct SegTree {
    vector<Node> tree;
    int n;
    SegTree(int _n) : n(_n), tree(4 * _n) {}
    Node query(int v, int l, int r, int ql, int qr) {
        if(r < ql || l > qr) return Node();
        if(ql <= l && r <= qr)
            return tree[v];
        int mid = (l + r) >> 1;
        tree[v].push(tree[v << 1], tree[v << 1|1], l, r, mid);
        return query(v << 1, l, mid, ql, qr) + query(v << 1|1, mid + 1, r, ql, qr);
    }
    Node query(int l, int r) { return query(1, 0, n - 1, l, r); }
    template<class F> 
    void update(int v, int l, int r, int ql, int qr, F f) {
        if(ql > r || l > qr) return;
        if(ql <= l && r <= qr) {
            f(tree[v], l, r);
            return;
        }
        int mid = (l + r) >> 1;
        tree[v].push(tree[v << 1], tree[v << 1|1], l, r, mid);
        update(v << 1, l, mid, ql, qr, f);
        update(v << 1|1, mid + 1, r, ql, qr, f);
        tree[v] = tree[v << 1] + tree[v << 1|1];
    }
    template<class F>
    void update(int l, int r, F f) { update(1, 0, n - 1, l, r, f); }
};
struct Node {
    array<int, 2> lazy; //slope, constant
    int sum;
    Node() : lazy({1, 0}), sum(0) {}
    friend Node operator+ (const Node &a, const Node &b) {
        Node res;
        res.sum = a.sum + b.sum;
        return res;
    }
    void push(Node &l, Node &r, int nl, int nr, int nm) {
        if(lazy[0] == 1 && lazy[1] == 0) return;
        l.apply(lazy, nl, nm);
        r.apply(lazy, nm + 1, nr);
        lazy = {1, 0}; //reset after lazy update
    }
    void apply(array<int, 2> f, int l, int r) {
        int cnt = r - l + 1;
        lazy = { //f(g(x)) = a(cx+d) + b = acx + ad + b
            lazy[0] * f[0], f[0] * lazy[1] + f[1]
        };
        sum = f[1] * cnt + f[0] * sum;
    }
};