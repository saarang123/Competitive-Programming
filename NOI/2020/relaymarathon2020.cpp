#include <bits/stdc++.h>
using namespace std;
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
const int mxn = 100 * 1000 + 3;
const int inf = 1e9 + 2;
vector<array<int, 2>> g[mxn];
int n, m, k;

int magic(vector<int> &src, vector<int> &snk) {
	priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> pq;
	vector<int> dt(n, inf);
	vector<bool> done(n);
	for(int v : src) {
		dt[v] = 0;
		pq.push({0, v});
	}
	for(int &v : snk)
		done[v] = true;
	while(!pq.empty()) {
		auto [wt, v] = pq.top();
		pq.pop();
		if(dt[v] != wt)
			continue;
		if(done[v])
			return wt;
		for(auto &[u, w] : g[v]) {
			if(dt[v] + w < dt[u]) {
				dt[u] = dt[v] + w;
				pq.push({dt[u], u});
			}
		}
	}
	int ret = inf;
	for(int &v : snk)
		ret = min(ret, dt[v]);
	return ret;
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
    for(int u, v, w, i = 0; i < m; i++) {
    	cin >> u >> v >> w;
    	g[--u].push_back({--v, w});
    	g[v].push_back({u, w});
    }
    vector<int> a(k);
    for(int &x : a)
    	cin >> x, x--;
    int ans = inf;
    while(clock() < 5 * CLOCKS_PER_SEC) {
    	shuffle(a.begin(), a.end(), rng);
    	vector<int> src[2], snk[2];
    	for(int i = 0; i < k / 2; i++)
    		src[rng() % 2].push_back(a[i]);
    	for(int i = k / 2; i < k; i++) 
    		snk[rng() % 2].push_back(a[i]);
    	ans = min(ans, magic(src[0], snk[0]) + magic(src[1], snk[1]));
    }
    cout << ans << '\n';
    return 0;
}