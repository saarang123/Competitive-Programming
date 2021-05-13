#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
int n, q;
vector<int> seg[4 * N];
vector<array<int, 2>> a;

void build(int v, int tl, int tr) {
	if(tl == tr)
		return void(seg[v].push_back(a[tl][1]));
	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm); build(v << 1|1, tm + 1, tr);
	merge(seg[v << 1].begin(), seg[v << 1].end(),
		  seg[v << 1|1].begin(), seg[v << 1|1].end(),
		  back_inserter(seg[v]));
}

int query(int v, int tl, int tr, int l, int r, int k) {
	if(tl == tr) return seg[v][0];
	int tm = (tl + tr) >> 1;
	int cnt = upper_bound(seg[v << 1].begin(), seg[v << 1].end(), r) 
			- lower_bound(seg[v << 1].begin(), seg[v << 1].end(), l);
	if(cnt >= k) return query(v << 1, tl, tm, l, r, k);
	else return query(v << 1|1, tm + 1, tr, l, r, k - cnt);
}

int query(int l, int r, int k) { return query(1, 1, n, l, r, k); }

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/input.txt", "r", stdin);
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/output.txt", "w", stdout);
    #endif
    cin >> n >> q;
  	a.resize(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i][0], a[i][1] = i;
    auto b = a;
    sort(a.begin() + 1, a.end(), greater<>());
	build(1, 1, n);
	while(q--) {
		int l, r, c;
		cin >> l >> r >> c;
		cout << b[query(l, r, c)][0] << '\n';
	}
    return 0;
}