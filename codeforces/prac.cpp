#include <bits/stdc++.h>
using namespace std;
 
template<class T>
struct SegTree { //1-based
    vector<T> seg;
    int _n;
    SegTree() : _n(0) {}
    SegTree(int __n) : _n(__n), seg(2 * __n + 5) {}
    SegTree(vector<T> &a) {
        _n = a.size();
        seg.resize(2 * _n + 5);
        build(a);
    }
    void pull(int x) { seg[x] = seg[x << 1] + seg[x << 1|1]; }
    void build(vector<T> &a) {
        for(int i = 0; i < _n; i++)
            seg[_n + i] = a[i];
        for(int i = _n - 1; i > 0; i--)
            pull(i);
    }
    void upd(int x, int v) {
        x += _n - 1; //remove -1 for 0-based
        seg[x] = v; //assign update
        for(x >>= 1; x > 0; x >>= 1)
            pull(x);
    }
    T query(int l, int r) { //range [l, r]
        --l, --r; //comment for 0-based
        T ans = T();
        for(l += _n, r += _n + 1; l < r; l >>= 1, r >>= 1) {
            if(l & 1)
                ans = ans + seg[l++];
            if(r & 1)
                ans = ans + seg[--r];
        }
        return ans;
    }
};
 
struct Node {
    long long value;
    Node() : value(0) {}
    Node(long long _x) : value(_x) {}
    friend Node operator+ (const Node& a, const Node &b) {
        return Node(a.value + b.value);
    }
};
 
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<Node> a(n);
    for(auto &x : a)
        cin >> x.value;
    SegTree<Node> st(a);
    while(q--) {
        int tp; cin >> tp;
        if(tp == 1) {
            int pos, x;
            cin >> pos >> x;
            st.upd(pos, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << st.query(l, r).value << '\n';
        }
    }
    return 0;
}