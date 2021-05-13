#include "bits/stdc++.h"
//#include "graphcraft.h"
//#define int long long
using namespace std;
const long long  mod = 1e9 + 7;
const int MXN = 100 * 1000 + 3;
vector<array<long long, 3>> g[MXN];
long long dp[MXN], vis[MXN], u[MXN], id = 0;
bool cycle;

long long dfs(int v, int p) {
	if(u[v]) return dp[v];
	dp[v] = 0; u[v] = 1;
	vis[v] = 1;
	for (const auto &tx : g[v]) {
		long long u = tx[0], wt = tx[1], idx = tx[2];
		if(idx == p) continue;
		if(vis[u] == 1) {
			cycle = true; break;
		} else
			(dp[v] += (wt * dfs(u, idx)) % mod) %= mod;
		if(cycle) break;
	}
	vis[v] = 2;
	return dp[v] %= mod;
}

int graphcraft(int n, int c, vector<pair<int,int>> v[]) {
	for(int i = 1; i < n; i++) {
		for(auto tx : v[i]) {
			int x = tx.first, y = tx.second;
			g[i].push_back({x, y, id++});
		}
	}
	memset(dp, -1, sizeof dp);
	u[0] = dp[0] = 1; dfs(c, -1);
	return cycle ? -1 : dp[c];
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/input.txt", "r", stdin);
        freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/output.txt", "w", stdout);
    #endif
    int n, c;
    cin >> n >> c;
    vector<pair<int,int>> v[n];
    for(int i = 1; i < n; i++) {
    	int t; cin >> t;
    	for(int j = 0, a, b; j < t; j++) {
    		cin >> a >> b;
    		v[i].push_back(make_pair(a, b));
    	}
    }
    cout << graphcraft(n, c, v) << '\n';
    return 0;
}