#include <bits/stdc++.h>
using namespace std;
const int MXN = 200 * 1000 + 3;
vector<int> g[MXN];
vector<array<int, 2>> query[MXN];
int cnt[MXN], ans[MXN];
int n, q;

void dfs(int v = 1, int dt = 0) {
	for(auto &[d, i] : query[v])
		ans[i] -= cnt[d];
	cnt[dt]++;
	for(int u : g[v])
		dfs(u, dt + 1);
	for(auto &[d, i] : query[v])
		ans[i] += cnt[d];
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    cin >> n;
    for(int p, i = 2; i <= n; i++) {
    	cin >> p;
    	g[p].push_back(i);
    }
    cin >> q;
    for(int u, d, i = 0; i < q; i++) {
    	cin >> u >> d;
    	query[u].push_back({d, i});
    }

    dfs();
    for(int i = 0; i < q; i++)
    	cout << ans[i] << '\n';
    return 0;
}