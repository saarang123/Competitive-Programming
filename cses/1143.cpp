#include <bits/stdc++.h>
using namespace std;
const int mxn = 200 * 1000 + 3;
int t[4 * mxn], a[mxn], n, m;

void build(int v = 1, int tl = 1, int tr = n) {
	if(tl == tr)
		return void(t[v] = a[tl]);
	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1|1, tm + 1, tr);
	t[v] = max(t[v << 1], t[v << 1|1]);
}

void upd(int v, int tl, int tr, int pos, int x) {
	if(tl == tr)
		return void(t[v] -= x);
	int tm = (tl + tr) >> 1;
	if(pos <= tm)
		upd(v << 1, tl, tm, pos, x);
	else
		upd(v << 1|1, tm + 1, tr, pos, x);
	t[v] = max(t[v << 1], t[v << 1|1]);
}

void upd(int x, int v) {
	upd(1, 1, n, x, v);
}

int query(int v, int tl, int tr, int x) {
	if(t[v] < x)
		return 0;
	if(tl == tr)
		return tl;
	int tm = (tl + tr) >> 1;
	if(t[v << 1] >= x)
		return query(v << 1, tl, tm, x);
	return query(v << 1|1, tm + 1, tr, x);
}

int query(int x) {
	return query(1, 1, n, x);
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    cin >> n >> m;
    for(int i = 1; i <= n; i++) 
    	cin >> a[i];
    build();
    for(int x, i = 0; i < m; i++) {
    	cin >> x;
    	int ans = query(x);
    	cout << ans << ' ';
    	if(ans)
    		upd(ans, x);
    }
    return 0;
}