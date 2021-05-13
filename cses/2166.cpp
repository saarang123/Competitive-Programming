#include <bits/stdc++.h>
using namespace std;
struct Node {
	long long pref, sum;
	Node() : pref(0), sum(0) {}
	Node(long long _pref, long long _sum) : pref(max(0LL, _pref)), sum(_sum) {}
	friend Node operator+ (const Node &a, const Node &b) {
		return Node(max(a.pref, a.sum + b.pref), a.sum + b.sum);
	}
};

const int mxn = 200 * 1000 + 3;
Node t[4 * mxn];
int a[mxn], n, q;

void build(int v = 1, int tl = 1, int tr = n) {
	if(tl == tr)
		return void(t[v] = Node(a[tl], a[tl]));
	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1|1, tm + 1, tr);
	t[v] = t[v << 1] + t[v << 1|1];
}

void update(int v, int tl, int tr, int pos, int x) {
	if(tl == tr)
		return void(t[v] = Node(x, x));
	int tm = (tl + tr) >> 1;
	if(pos <= tm)
		update(v << 1, tl, tm, pos, x);
	else
		update(v << 1|1, tm + 1, tr, pos, x);
	t[v] = t[v << 1] + t[v << 1|1];
}

void upd(int pos, int x) { update(1, 1, n, pos, x); }

Node query(int v, int tl, int tr, int l, int r) {
	if(l > r)
		return Node();
	if(tl == l && tr == r)
		return t[v];
	int tm = (tl + tr) >> 1;
	return query(v << 1, tl, tm, l, min(tm, r)) + query(v << 1|1, tm + 1, tr, max(l, tm + 1), r);
}

long long query(int l, int r) { return query(1, 1, n, l, r).pref; }

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    	cin >> a[i];
    build();
    while(q--) {
    	int tp, l, r;
    	cin >> tp >> l >> r;
    	if(tp == 1)
    		upd(l, r);
    	else
    		cout << query(l, r) << '\n';
    }
    return 0;
}