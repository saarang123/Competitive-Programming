#include <bits/stdc++.h>
using namespace std;
const int N = 200 * 1000 + 3;
vector<int> g[N];
int n, m, k;

vector<int> bfs(int s) {
	vector<int> dt(n, -1);
	dt[s] = 0;
	queue<int> q;
	q.push(s);
	while(!q.empty()) {
		int v = q.front(); q.pop();
		for(int u : g[v]) if(dt[u] == -1) {
			dt[u] = dt[v] + 1;
			q.push(u);
		}
	}
	return dt;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    cin >> n >> m >> k;
    vector<int> a(k);
    for(int &x : a)
    	cin >> x, x--;
    for(int u, v, _ = 0; _ < m; _++) {
    	cin >> u >> v;
    	g[--u].push_back(--v);
    	g[v].push_back(u);
    }
    vector<vector<int>> dt;
    dt.push_back(bfs(0));
    dt.push_back(bfs(n - 1));
    sort(a.begin(), a.end(), [&] (int x, int y) {
    	return dt[0][x] - dt[1][x] < dt[0][y] - dt[1][y];
    });
    int ans = 0, mx = -1e6;
    for(int u : a) {
    	ans = max(ans, mx + 1 + dt[1][u]);
    	mx = max(mx, dt[0][u]);
    }
    ans = min(ans, dt[1][0]);
    cout << ans << '\n';
    return 0;
}