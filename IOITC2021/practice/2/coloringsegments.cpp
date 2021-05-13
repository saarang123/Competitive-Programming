#include <bits/stdc++.h>
using namespace std;
const int mxn = 500 * 1000 + 3;
int par[mxn], sz[mxn], cnt = 0;

void init(int n) {
	cnt = 0;
	for(int i = 1; i <= n; i++)
		par[i] = i, sz[i] = 1, cnt++;
}

int find(int v) { return par[v] == v ? v : par[v] = find(par[v]); }

void merge(int a, int b) {
	a = find(a); b = find(b);
	if(a == b) return;
	cnt--;
	if(sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	par[b] = a;
}

void solve() {
	int n, m;
	cin >> n >> m;
	init(m);
	vector<array<int, 2>> a(n), b(m);
	for(int i = 0; i < n; i++) {
		cin >> a[i][0]; a[i][1] = i + 1;
	}
	for(int i = 0; i < m; i++) {
		cin >> b[i][1]; b[i][0] = i + 1;
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	set<array<int, 2>> ost;

	int ans = 0, itr = 0;
	for(int i = 0; i < n; i++) {
		while(itr < m && b[itr][0] <= a[i][0]) 
			ost.insert({b[itr][1], b[itr][0]}), itr++;

		auto it = ost.lower_bound({a[i][1], 0});
		if(it == ost.end()) { ans++; continue; }

		for(; it != prev(ost.end());) {
			merge((*it)[1], (*ost.rbegin())[1]);
			it = ost.erase(it);
		}
	}
	cout << ans + cnt << '\n';
}
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int tc; cin >> tc;
    while(tc--)
    	solve();
    return 0;
}