#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxn = 200 * 1000 + 3;
int a[mxn], t[mxn << 2], base[mxn << 2], diff[mxn << 2];
int n, q;
 
void build(int v, int tl, int tr) {
	if(tl == tr)
		t[v] = a[tl];
	else {
		int tm = (tl + tr) >> 1;
		build(v << 1, tl, tm);
		build(v << 1|1, tm + 1, tr);
		t[v] = t[v << 1] + t[v << 1|1];
	}
}
 
long long sum(int b, int l, int d) {
	return l * (2 * b + (l - 1) * d) / 2;
}
 
void push(int v, int l, int m, int r) {
	t[v] += sum(base[v], r - l + 1, diff[v]);
	if(l != r) {
		base[v << 1] += base[v];
		diff[v << 1] += diff[v];
		base[v << 1|1] += base[v] + (m - l + 1) * diff[v];
		diff[v << 1|1] += diff[v];
	}
	base[v] = diff[v] = 0;
}
 
void update(int v, int tl, int tr, int l, int r, int b, int d) {
	int tm = (tl + tr) >> 1;
	push(v, tl, tm, tr);
	if(tr < l || tl > r) return;
	if(tl >= l && tr <= r) {
		base[v] += b + (tl - l) * d;
		diff[v] += d;
		push(v, tl, tm, tr);
		return;
	}
	update(v << 1, tl, tm, l, r, b, d);
	update(v << 1|1, tm + 1, tr, l, r, b, d);
	t[v] = t[v << 1] + t[v << 1|1];
}
 
void update(int l, int r, int b, int d) {
	update(1, 1, n, l, r, b, d);
}
 
int query(int v, int tl, int tr, int l, int r) {
	int tm = (tl + tr) >> 1;
	push(v, tl, tm, tr);
	if(tr < l || tl > r) return 0;
	if(tl >= l && tr <= r) 
		return t[v];
	return query(v << 1, tl, tm, l, r) + query(v << 1|1, tm + 1, tr, l, r);
}
 
int query(int l, int r) {
	return query(1, 1, n, l, r);
}
 
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
    		int l, r;
    		cin >> l >> r;
    		update(l, r, 1, 1);
    	} else {
    		int l, r;
    		cin >> l >> r;
    		cout << query(l, r) << '\n';
    	}
    }
    return 0;
}