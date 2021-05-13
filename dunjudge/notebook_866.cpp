#include <bits/stdc++.h>
using namespace std;
#define int long long
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
const int N = 2002;
const int inf = 1e18;
vector<array<int, 2>> g[N];
int dt[N];
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/input.txt", "r", stdin);
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/output.txt", "w", stdout);
    #endif
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    //for(int i = 0; i < m; i++) inf += "9";
    //cout << inf << '\n';
	for(int i = 0; i <= n; i++) dt[i] = inf;
	for(int u, v, c, i = 0; i < m; i++) {
		cin >> u >> v >> c;
		g[u].push_back({v, c});
		g[v].push_back({u, c});
	}
	dt[s] = 0;
	priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> pq;
	pq.push({0, s});
	while(!pq.empty()) {
		int v = pq.top()[1]; pq.pop();
		for(auto tx : g[v]) {
			int u = tx[0], w = tx[1];
			if((dt[v] * 10 + w) < dt[u]) {
				dt[u] = dt[v] * 10 + w;
				pq.push({dt[u], u});
			}
		}
	}
	cout << (dt[t] >= inf ? -1 : dt[t]) << '\n';
    return 0;
}