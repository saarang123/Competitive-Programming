#include <bits/stdc++.h>
using namespace std;
const int mxn = 200 * 1000 + 3;
vector<int> g[mxn];
int sz[mxn];

int dfs(int v) {
	sz[v] = 1;
	for(int u : g[v])
		sz[v] += dfs(u);
	return sz[v];
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n; cin >> n;
    for(int i = 2; i <= n; i++) {
    	int x; cin >> x;
    	g[x].push_back(i);
    }
    dfs(1);
    for(int i = 1; i <= n; i++)
    	cout << sz[i] - 1 << ' ';
    cout << '\n';
    return 0;
}