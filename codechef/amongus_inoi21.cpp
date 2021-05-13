#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define all(x) x.begin(), x.end()
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
const int N = 500 * 1000 + 4;
vector<array<int, 2>> g[N];
int c[N], f[N], vis[N], cnt[] = {0, 0};
bool cycle = false;

void init(int n) {
	for(int i = 1; i <= n; i++) {
		g[i].clear();
		c[i] = f[i] = vis[i] = -1;
	}
	cycle = false;
}

bool dfs(int v, int co) {
	c[v] = co;
	cnt[co]++;
	for(auto tx : g[v]) {
		int u = tx[0], t = tx[1];
		if(c[u] != -1) {
			if(t == 1 && c[u] == c[v]) return false;
			if(t == 2 && c[u] != co) return false;
		} else {
			bool b;
			if(t == 1) b = dfs(u, co ^ 1);
			else b = dfs(u, co);
			if(!b) return false;
		}
	}
	return true;
}

void solve() {
	int n, q;
	cin >> n >> q;
	init(n);
	for(int t, u, v, _ = 0; _ < q; _++) {
		cin >> t >> u >> v;
		g[u].push_back({v, t});
		g[v].push_back({u, t});
	}
	int ans = 0;
	//cout << "ok:" << endl;
	for(int i = 1; i <= n; i++) if(c[i] == -1) {
		cnt[0] = cnt[1] = 0;
		if(!dfs(i, 0)) {
			return void(cout << -1 << '\n');
		}
		ans += max(cnt[0], cnt[1]);
	}
	cout << ans << '\n';
}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int tc; cin >> tc;
	while(tc--) {
		solve();
	}
}