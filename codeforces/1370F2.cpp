#include <bits/stdc++.h>
using namespace std;
const int mxn = 1003;
vector<int> g[mxn], depth[mxn];
int dt[mxn], dmx[mxn], n;

array<int, 2> ask(vector<int> &q) {
	cout << "? " << q.size() << ' ';
	for(int x : q)
		cout << x << ' ';
	cout << endl;
	int v, d;
	cin >> v >> d;
	return {v, d};
}

void dfs(int v, int p = -1, int d = 0) {
	dt[v] = dmx[v] = d;
	for(int u : g[v]) if(u != p) {
		dfs(u, v, d + 1);
		dmx[v] = max(dmx[v], dmx[u]);
	}
	if(dmx[v] <= (n + 1) >> 1)
		depth[dt[v]].push_back(v);
}

void solve() {
	cin >> n;
	vector<int> q;
	for(int i = 0; i <= n; i++) {
		g[i].clear(); depth[i].clear();
		if(i)
			q.push_back(i);
	}
	for(int u, v, i = 1; i < n; i++) {
		cin >> u >> v;
		g[u].push_back(v); 
		g[v].push_back(u);
	}
	auto [v, dist] = ask(q);
	dfs(v);
	int mn = 0, mx = (n + 1) >> 1, one = -1;
	while(mn <= mx) {
		int mid = (mn + mx) >> 1;
		if(depth[mid].empty())
			mx = mid - 1;
		else {
			auto [u, d] = ask(depth[mid]);
			if(d == dist)
				one = u, mn = mid + 1;
			else
				mx = mid - 1;
		}
	}
	cerr << one << " is first one\n";
	assert(one > 0);
	q.clear();
	for(int i = 0; i <= n; i++) 
		depth[i].clear();
	dfs(one);
	for(int u : depth[dist])
		q.push_back(u);
	auto [two, d] = ask(q);
	assert(d == dist);
	cout << "! " << one << ' ' << two << endl;
	string s; cin >> s;
	assert(s == "Correct");
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