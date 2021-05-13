#include <bits/stdc++.h>
using namespace std;
template<class T>
using min_pq = priority_queue<T, vector<T>, greater<>>;
#define int long long
const int mxn = 53;
const int mxw = 52 * 102;
int dt[mxn][mxw + 100], ans[mxn];
vector<array<int, 3>> g[mxn];
int n, m, s;
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    cin >> n >> m >> s;
    s = min(s, mxw);
    for(int u, v, a, b, i = 0; i < m; i++) {
    	cin >> u >> v >> a >> b;
    	g[u].push_back({v, -a, b});
    	g[v].push_back({u, -a, b});
    }
    for(int c, d, i = 1; i <= n; i++) {
    	cin >> c >> d;
    	g[i].push_back({i, c, d});
    }
    memset(dt, 0x5f, sizeof dt);
    memset(ans, 0x5f, sizeof ans);
    dt[1][s] = 0;
    min_pq<array<int, 3>> pq;
    pq.push({0, 1, s});

    auto wadd = [&] (int i, int c, int w) {
    	if(dt[i][c] > w) {
    		dt[i][c] = w;
    		pq.push({w, i, c});
    	}
    };
    while(!pq.empty()) {
    	auto [d, v, f] = pq.top(); pq.pop();
    	if(dt[v][f] != d) continue;
    	ans[v] = min(ans[v], d);
    	for(auto &[u, w, t] : g[v]) if(f + w >= 0) 
    		wadd(u, min(f + w, mxw), d + t);
    }
    for(int i = 2; i <= n; i++)
    	cout << ans[i] << '\n';
    return 0;
}