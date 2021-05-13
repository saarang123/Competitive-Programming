#include <bits/stdc++.h>
using namespace std;
const int mxn = 200 * 1000 + 3, inf = 2e9;

template<class Node>
struct SegTree {
	vector<Node> t;
	int n, _x;
	SegTree(int _n, vector<int> &a, int _b) {
		n = _n; _x = _b;
		t.resize(4 * n);
		build(1, 1, n, a);
	}
	void build(int v, int tl, int tr, vector<int> &a) {
		if(tl == tr)
			t[v] = Node(a[tl], tl, _x);
		else {
			int tm = (tl + tr) >> 1;
			build(v << 1, tl, tm, a);
			build(v << 1|1, tm + 1, tr, a);
			t[v] = t[v << 1] + t[v << 1|1];
		}
	}
	void upd(int v, int tl, int tr, int pos, int x) {
		if(tl == tr)
			t[v] = Node(x, pos, _x);
		else {
			int tm = (tl + tr) >> 1;
			if(pos <= tm)
				upd(v << 1, tl, tm, pos, x);
			else
				upd(v << 1|1, tm + 1, tr, pos, x);
			t[v] = t[v << 1] + t[v << 1|1];
		}
	}
	void upd(int pos, int x) { upd(1, 1, n, pos, x); }
	Node query(int v, int tl, int tr, int l, int r) {
		if(l > r)
			return Node();
		if(tl == l && tr == r)
			return t[v];
		int tm = (tl + tr) >> 1;
		return query(v << 1, tl, tm, l, min(r, tm)) + query(v << 1|1, tm + 1, tr, max(l, tm + 1), r);
	}
	Node query(int l, int r) { return query(1, 1, n, l, r); }
};

struct Node {
	int x, id, m, val;
	Node() : x(inf), id(0), m(0), val(inf) {}
	Node(int _x, int _id, int _m) : x(_x), id(_id), m(_m), val(_x + _id * _m){}
	friend Node operator+ (const Node &a, const Node &b) {
		return a.val < b.val ? a : b;
	}
};

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++)
    	cin >> a[i];
    SegTree<Node> s1(n, a, 1), s2(n, a, -1);
    while(q--) {
    	int tp; cin >> tp;
        if(tp == 1) {
    		int k, x;
    		cin >> k >> x;
    		s1.upd(k, x);
    		s2.upd(k, x);
    	} else {
    		int x; cin >> x;
    		int answer = min(s1.query(x, n).val - x, s2.query(1, x).val + x);
    		cout << answer << '\n';
    	}
    }
    return 0;
}