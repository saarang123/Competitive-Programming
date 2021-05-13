#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxn = 200 * 1000 + 3;
int a[mxn], t[4 * mxn], n, q;

void build(int v, int tl, int tr) {
	if(tl == tr)
		return void(t[v] = a[tl]);
	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1|1, tm + 1, tr);
	t[v] = 0;
}

void upd(int v, int tl, int tr, int l, int r, int add) {
	if(l > r)
		return;
	if(tl == l && tr == r)
		t[v] += add;
	else {
		int tm = (tl + tr) >> 1;
		upd(v << 1, tl, tm, l, min(tm, r), add);
		upd(v << 1|1, tm + 1, tr, max(tm + 1, l), r, add);
	}
}

void upd(int l, int r, int add) { upd(1, 1, n, l, r, add); }

int qry(int v, int tl, int tr, int x) {
	if(tl == tr)
		return t[v];
	int tm = (tl + tr) >> 1;
	if(x <= tm)
		return t[v] + qry(v << 1, tl, tm, x);
	else
		return t[v] + qry(v << 1|1, tm + 1, tr, x);
}

int qry(int x) { return qry(1, 1, n, x); }

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
    build(1, 1, n);
    while(q--) {
    	int tp; cin >> tp;
    	if(tp == 1) {
    		int l, r, add;
    		cin >> l >> r >> add;
    		upd(l, r, add);
    	} else {
    		int x; cin >> x;
    		cout << qry(x) << '\n';
    	}
    }
    return 0;
}