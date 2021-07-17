#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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

struct Node2 {
    ll lazy; //slope, constant
    ll mn;
    Node2() : lazy{0}, mn(1e16) {}
    friend Node2 operator+ (const Node2 &a, const Node2 &b) {
        Node2 res;
        res.mn = min(a.mn, b.mn);
        return res;
    }
    void push(Node2 &l, Node2 &r, int nl, int nr, int nm) {
        if(lazy == 0) return;
        l.apply(lazy, nl, nm);
        r.apply(lazy, nm + 1, nr);
        lazy = 0; //reset after lazy update
    }
    void apply(ll f, int l, int r) {
        lazy = lazy + f;
        mn = f + mn;
    }
};

struct BIT {
    int n, lg;
    vector<ll> bit;
    BIT() {}
    BIT(int _n) { init(_n); }
    BIT(vector<int> &a) { init(a); }
    void init(int x) {
        n = x; lg = 0;
        while(2 * (1 << lg) <= n) lg++;
        bit.resize(n + 2,0);
    }
    void init(vector<int> &a) {
        init(a.size());
        for(int i = 1; i <= n; i++) {
            bit[i] += a[i - 1]; //check this
            if(i + (i & -i) <= n)
                bit[i + (i & -i)] += bit[i];
        }
    }
    ll qry(int x) { x++;
        x = min(x, n);
        ll ans = 0;
        for(; x > 0; x -= (x & -x))
            ans += bit[x];
        return ans;
    }
    ll qry(int l, int r) { return qry(r) - qry(l - 1); }
    void upd(int x, ll v) { x++;
        if(x <= 0) return;
        for(; x <= n; x += (x & -x))
            bit[x] += v;
    }
    int lower_bound(int sum) {
        int x = 0;
        for(int k = lg; k >= 0; k--) {
            int nx = x + (1 << k);
            if(nx <= n && sum > bit[nx]) {
                x = nx;
                sum -= bit[x];
            }
        }
        return x + 1;
    }   
};


signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for(int &x : a)
        cin >> x;
    vector<array<int, 2>> b;
    for(int i = 0; i < n; i++)
        b.push_back({a[i], i});
    sort(b.begin(), b.end(), greater<>());
    BIT s; s.init(n);
    SegTree<Node2> mni(n);
    for(int i = 0; i < n; i++) {
        mni.update(i, i, [&] (auto &x, int l, int r) {
            x.apply({-Node2().mn}, l, r);
        });
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        ll sum = b[i][1] == 0 ? 0 : s.qry(0, b[i][1] - 1);
        ll mini = mni.query(b[i][1], n - 1).mn;
        //cout << sum << ' ' << mini << ' ' << b[i][1] << ' ' << b[i][0] << '\n';
        if(sum + b[i][0] >= 0 && mini + b[i][0] >= 0) {
            cnt++;
            s.upd(b[i][1], b[i][0]);
            mni.update(b[i][1], n - 1, [&] (auto &x, int l, int r) {
                x.apply({b[i][0]}, l, r);
            });
        }
    }
    cout << cnt << '\n';
    return 0;
}